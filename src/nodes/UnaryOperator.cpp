#include "UnaryOperator.h"
#include "CodeGenContext.h"
#include "parser.hpp"

using namespace std;
using namespace llvm;

namespace statpy
{

   Value *UnaryOp::codeGen(CodeGenContext &context)
   {
      Value *rhsValue = rhs->codeGen(context);

      Value *lhsValue = nullptr;
      Instruction::BinaryOps instr;
      switch (op)
      {
      case TNOT:
         // instr = Instruction::UnaryOps::Not;
         if (!rhsValue->getType()->isIntegerTy())
         {
            Node::printError("Right hand side of uni operator must be an integer type.");
            context.addError();
            return nullptr;
         }

         // If rhs is 1 bit, then we can just xor with 1
         if (rhsValue->getType()->isIntegerTy(1))
         {
            lhsValue = ConstantInt::get(IntegerType::get(context.getGlobalContext(), context.getGenericIntegerType()->getIntegerBitWidth()), StringRef("1"), 10);
         } else {
            // Otherwise, we XOR with a mask of all 1s
            lhsValue = ConstantInt::get(IntegerType::get(context.getGlobalContext(), context.getGenericIntegerType()->getIntegerBitWidth()), StringRef("-1"), 10);
         }
         instr = Instruction::Xor;
         break;
      case TMINUS:
         if (rhsValue->getType()->isIntegerTy())
         {
            lhsValue = ConstantInt::get(IntegerType::get(context.getGlobalContext(), context.getGenericIntegerType()->getIntegerBitWidth()), StringRef("0"), 10);
            instr = Instruction::Sub;
         }
         else if (rhsValue->getType()->isFloatingPointTy())
         {
            lhsValue = ConstantFP::get(Type::getDoubleTy(context.getGlobalContext()), StringRef("0.0"));
            instr = Instruction::FSub;
         }
         else
         {
            Node::printError("Right hand side of uni operator must be an integer or double type.");
            context.addError();
            return nullptr;
         }
         break;
      default: // TODO user defined operator
         Node::printError("Unknown uni operator.");
         context.addError();
         return nullptr;
      }

      return BinaryOperator::Create(instr, lhsValue, rhsValue, "unarytmp", context.currentBlock());
   }

   std::string UnaryOp::toString()
   {
      std::stringstream s;
      s << "unary operation ";
      switch (op)
      {
      case TNOT:
         s << "not";
         break;
      case TMINUS:
         s << "-";
         break;
      default: // TODO user defined operator
         s << "unknown";
      }
      return s.str();
   }

} // namespace statpy

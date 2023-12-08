#include "BinaryOperator.h"
#include "CodeGenContext.h"
#include "parser.hpp"

using namespace std;
using namespace llvm;

namespace statpy
{

   Value *BinaryOp::codeGen(CodeGenContext &context)
   {
      Value *rhsValue = rhs->codeGen(context);
      Value *lhsValue = lhs->codeGen(context);
      if ((rhsValue == nullptr) || (lhsValue == nullptr))
      {
         return nullptr;
      }
      auto Ty = rhsValue->getType();

      if (rhsValue->getType() != lhsValue->getType())
      {
         // since we only support double and int, always cast to double in case of different types.
         auto doubleTy = Type::getDoubleTy(context.getGlobalContext());
         auto cinstr = CastInst::getCastOpcode(rhsValue, true, doubleTy, true);
         rhsValue = CastInst::Create(cinstr, rhsValue, doubleTy, "castdb", context.currentBlock());
         cinstr = CastInst::getCastOpcode(lhsValue, true, doubleTy, true);
         lhsValue = CastInst::Create(cinstr, lhsValue, doubleTy, "castdb", context.currentBlock());
      }

      bool isDoubleTy = rhsValue->getType()->isFloatingPointTy();
      if (isDoubleTy && (op == TAND || op == TOR || op == TMOD))
      {
         Node::printError(location, "Binary operation (AND, OR, %) on floating point value is not supported.");
         context.addError();
         return nullptr;
      }

      Instruction::BinaryOps instr;
      switch (op)
      {
      case TPLUS:
         isDoubleTy ? instr = Instruction::FAdd : instr = Instruction::Add;
         break;
      case TMINUS:
         isDoubleTy ? instr = Instruction::FSub : instr = Instruction::Sub;
         break;
      case TMUL:
         isDoubleTy ? instr = Instruction::FMul : instr = Instruction::Mul;
         break;
      case TDIV:
         isDoubleTy ? instr = Instruction::FDiv : instr = Instruction::SDiv;
         break;
      case TMOD:
         instr = Instruction::SRem;
         break;
      case TAND:
         instr = Instruction::And;
         break;
      case TOR:
         instr = Instruction::Or;
         break;
      default:
         Node::printError(location, "Unknown binary operator.");
         context.addError();
         return nullptr;
      }
      return BinaryOperator::Create(instr, lhsValue, rhsValue, "mathtmp", context.currentBlock());
   }

   std::string BinaryOp::toString()
   {
      std::stringstream s;
      s << "binary operation ";
      switch (op)
      {
      case TPLUS:
         s << "+";
         break;
      case TMINUS:
         s << "-";
         break;
      case TMUL:
         s << "*";
         break;
      case TDIV:
         s << "/";
         break;
      case TMOD:
         s << "%";
         break;
      case TAND:
         s << "and";
         break;
      case TOR:
         s << "or";
         break;
      default:
         s << "unknown";
      }
      return s.str();
   }

} // namespace statpy

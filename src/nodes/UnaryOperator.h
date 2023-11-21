#pragma once

#include "AstNode.h"

namespace statpy
{
   /*! Represents a unary operator. */
   class UnaryOp : public Expression
   {
   public:
      explicit UnaryOp(int op, Expression *rhs) : op(op), rhs(rhs) {}
      virtual ~UnaryOp() { delete rhs; }

      llvm::Value *codeGen(CodeGenContext &context) override;
      NodeType getType() override { return NodeType::expression; }
      std::string toString() override;
      void Accept(Visitor &v) override { v.VisitUnaryOperator(this); }

      Expression *getRHS() { return rhs; }

   private:
      int op{0};
      Expression *rhs;
   };

}

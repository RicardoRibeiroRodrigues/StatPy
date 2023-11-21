#pragma once
#include "AstNode.h"

namespace statpy
{

    /*! Represents a for loop. */
    class ForLoop : public Statement
    {
    public:
        explicit ForLoop(Statement *assign, Expression *expr, Statement *updateVar_, Block *loopBlock) : condition(expr), loopBlock(loopBlock), var_assign(assign), updateVar(updateVar_) {}
        virtual ~ForLoop()
        {
            delete condition;
            delete loopBlock;
            delete var_assign;
            delete updateVar;
        }

        llvm::Value *codeGen(CodeGenContext &context) override;
        NodeType getType() override { return NodeType::expression; }
        std::string toString() override { return "for loop "; }
        void Accept(Visitor &v) override { v.VisitForLoop(this); }

        Expression *getCondition() { return condition; }
        Block *getLoopBlock() { return loopBlock; }
        Statement *getAssign() { return var_assign; }
        Statement *getUpdateVar() { return updateVar; }

    private:
        Expression *condition{nullptr};
        Block *loopBlock{nullptr};
        Statement *var_assign{nullptr};
        Statement *updateVar{nullptr};
    };

} // namespace statpy

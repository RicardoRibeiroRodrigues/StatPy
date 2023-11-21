#include "ForLoop.h"
#include "CodeGenContext.h"
#include "parser.hpp"

using namespace std;
using namespace llvm;

namespace statpy
{
    Value *ForLoop::codeGen(CodeGenContext &context)
    {
        // Get the current function and create basic blocks
        Function *function = context.currentBlock()->getParent();
        BasicBlock *initBB = BasicBlock::Create(context.getGlobalContext(), "init");
        BasicBlock *condBB = BasicBlock::Create(context.getGlobalContext(), "cond");
        BasicBlock *loopBB = BasicBlock::Create(context.getGlobalContext(), "loop");
        BasicBlock *updateBB = BasicBlock::Create(context.getGlobalContext(), "update");
        BasicBlock *mergeBB = BasicBlock::Create(context.getGlobalContext(), "merge");

        // Create a branch to the initialization block
        BranchInst::Create(initBB, context.currentBlock());
        
        // Enter a new scope for the initialization block
        function->getBasicBlockList().push_back(initBB);
        context.newScope(initBB);
        
        // Generate code for the initialization (variable declaration)
        Value *initValue = this->var_assign->codeGen(context);
        if (initValue == nullptr)
        {
            Node::printError("Code gen for initialization in for loop failed.");
            context.addError();
            return nullptr;
        }

        // Create a branch to the condition block
        BranchInst::Create(condBB, context.currentBlock());
        
        // Add the condition block to the function's basic block list
        function->getBasicBlockList().push_back(condBB);

        // Enter a new scope for the condition block
        context.newScope(condBB);

        // Generate code for the loop condition
        Value *condValue = this->condition->codeGen(context);
        if (condValue == nullptr)
        {
            Node::printError("Code gen for condition expression in for loop failed.");
            context.addError();
            return nullptr;
        }

        // Check if the condition is a boolean expression
        if (!condValue->getType()->isIntegerTy(1))
        {
            Node::printError("For loop condition doesn't result in a boolean expression.");
            context.addError();
            return nullptr;
        }

        // Create a branch to the loop or merge block based on the condition
        BranchInst::Create(loopBB, mergeBB, condValue, context.currentBlock());

        // Add the loop block to the function's basic block list
        function->getBasicBlockList().push_back(loopBB);

        // Exit the scope for the condition block
        context.endScope();

        // Enter a new scope for the loop block
        context.newScope(loopBB);

        // Generate code for the loop block
        Value *loopValue = this->loopBlock->codeGen(context);
        if (loopValue == nullptr)
        {
            Node::printError("Code gen for loop value in for loop failed.");
            context.addError();
            return nullptr;
        }

        // Create a branch to the update block
        BranchInst::Create(updateBB, context.currentBlock());

        // Add the update block to the function's basic block list
        function->getBasicBlockList().push_back(updateBB);

        // Exit the scope for the loop block
        context.endScope();

        // Enter a new scope for the update block
        context.newScope(updateBB);

        // Generate code for the update
        Value *updateValue = this->updateVar->codeGen(context);
        if (updateValue == nullptr)
        {
            Node::printError("Code gen for update expression in for loop failed.");
            context.addError();
            return nullptr;
        }

        // Create a branch back to the condition block
        BranchInst::Create(condBB, context.currentBlock());

        // Add the merge block to the function's basic block list
        function->getBasicBlockList().push_back(mergeBB);

        // Exit the scope for the update block
        context.endScope();
        // Exit the scope for the initialization block
        context.endScope();

        // Set the insert point to the merge block
        context.setInsertPoint(mergeBB);

        return mergeBB;
    }

} // namespace statpy

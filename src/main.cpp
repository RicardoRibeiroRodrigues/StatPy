#include <iostream>
#include "nodes/AstNode.h"
#include <stack>
#include "nodes/CodeGenContext.h"
#include "preprocess.h"

extern statpy::Block* programBlock;
extern int yyparse();
FILE *input_file;
extern int yydebug;
extern FILE *yyin;
extern int yylex_destroy();
extern std::stack<std::string> fileNames;

typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(const char * str);
extern void yy_delete_buffer(YY_BUFFER_STATE);

int main(int argc, char **argv)
{
    bool quiet = false;
    bool verbose = true;
    bool debug = true;

    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    fileNames.push(argv[1]);
    input_file = fopen(argv[1], "r");
    if (!input_file) {
        std::cout << "Error: could not open input file " << argv[1] << std::endl;
        return 1;
    }
    yydebug = 1;
    yyin = input_file;

    // std::string pre_processed = preprocess_code(argv[1]);
    // std::cout << pre_processed << std::endl;

    // YY_BUFFER_STATE buffer = yy_scan_buffer(strnig,  sizeof(strnig));
    // YY_BUFFER_STATE buffer = yy_scan_string(pre_processed.c_str());
    yyparse();
    // yy_delete_buffer(buffer);
    
    if (programBlock == nullptr) {
        std::cout << "Error: could not parse input file " << argv[1] << std::endl;
        return 1;
    } else {
        std::ostringstream devNull;
        statpy::CodeGenContext context(quiet ? devNull : std::cout);
        context.verbose = verbose;
        context.debug = debug;
        if (context.verbose)
            context.printCodeGeneration(*programBlock, std::cout);
        
        if (context.preProcessing(*programBlock))
        {
            if (context.generateCode(*programBlock))
            {
                context.runCode();
            }
        }
            
        std::cout << programBlock << std::endl;
    }

    if (yyin != nullptr)
    {
        fclose(yyin);
    }
    
    // delete programBlock;
    yylex_destroy();
    return 0;
}
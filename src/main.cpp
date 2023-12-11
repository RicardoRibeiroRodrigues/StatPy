#include <iostream>
#include <fstream>
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
extern int has_error;
typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(const char * str);
extern void yy_delete_buffer(YY_BUFFER_STATE);

int main(int argc, char **argv)
{
    bool quiet = true;
    bool verbose = false;
    bool debug = false;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-q") == 0)
        {
            quiet = true;
            verbose = false;
        }
        else if (strcmp(argv[i], "-v") == 0)
        {
            verbose = true;
            quiet = false;
        }
        else if (strcmp(argv[i], "-d") == 0)
        {
            debug = true;
        }
        else if (strcmp(argv[i], "-h") == 0)
        {
            std::cout << "Usage: " << argv[0] << " <input_file> [-q] [-v] [-d]" << std::endl;
            std::cout << "Options:" << std::endl;
            std::cout << "  -q: quiet mode, no output" << std::endl;
            std::cout << "  -v: verbose mode, print generated code" << std::endl;
            std::cout << "  -d: debug mode, print debug info" << std::endl;
            return 0;
        }
    }

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    fileNames.push(argv[1]);
    input_file = fopen(argv[1], "r");
    if (!input_file) {
        std::cout << "Error: could not open input file " << argv[1] << std::endl;
        return 1;
    }
    yydebug = debug ? 1 : 0;
    // yyin = input_file;

    std::string pre_processed = preprocess_code(argv[1]);
    // Write temp file with pre processed content
    std::ofstream temp_file;
    temp_file.open("temp.stp");
    temp_file << pre_processed;
    temp_file.close();

    input_file = fopen("temp.stp", "r");
    if (!input_file) {
        std::cout << "Error: could not open input file " << argv[1] << std::endl;
        return 1;
    }
    yyin = input_file;

    yyparse();
    if (has_error)
    {
        std::cout << "Error: could not parse input file " << argv[1] << std::endl;
        return 1;
    }
    
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
                if (context.getErrorCount() > 0)
                {
                    std::cout << "Error: in " << argv[1] << " use -v option for detailed debug" << std::endl;
                }
            }
        }
    }

    if (yyin != nullptr)
    {
        fclose(yyin);
    }
    
    // delete programBlock;
    yylex_destroy();
    return 0;
}
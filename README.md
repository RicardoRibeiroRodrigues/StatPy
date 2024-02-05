# Creation of a programming language from scratch!

## EBNF - Defining the syntax

<details>
  <summary>Open/Close EBNF</summary>
  
```ebnf
PROGRAM = { STATEMENT } ;
STATEMENT = (VARIABLE_DECLARE, "\n" | ASSIGNMENT_STATEMENT, "\n" | IF_STATEMENT | WHILE_LOOP | FOR_LOOP | FUNCTION_DECLARE | RETURN_STATEMENT, "\n" | FUNCTION_CALL, "\n") ;

VARIABLE_DECLARE = (TYPE, IDENTIFIER, ["=", BOOL_EXPR] | "VAR", IDENTIFIER, "=", BOOL_EXPR) ;

ASSIGNMENT_STATEMENT = (IDENTIFIER, [ ARITHMETIC_OPERATOR ], "=", BOOL_EXPR | INC_DEC | BINOP_ASSIGN) ;
BINOP_ASSIGN = IDENTIFIER, ARITHMETIC_OPERATOR, "=", BOOL_EXPR;
INC_DEC = IDENTIFIER, ("++" | "--");

IF_STATEMENT = "if", BOOL_EXPR, ":", INDENTED_PROGRAM, ["else", ":", INDENTED_PROGRAM] ;

WHILE_LOOP = "while", BOOL_EXPR, ":", INDENTED_PROGRAM ;
FOR_LOOP = "for", (ASSIGNMENT_STATEMENT | VARIABLE_DECLARE), ";", BOOL_EXPR, ";", ASSIGNMENT_STATEMENT, ":", INDENTED_PROGRAM;

FUNCTION_DECLARE = "fn", IDENTIFIER, "(", [PARAMETER_LIST], ")", "->", TYPE, ":", INDENTED_PROGRAM ; 
PARAMETER_LIST = IDENTIFIER, ":", TYPE, { ",", IDENTIFIER, ":", TYPE} ;

RETURN_STATEMENT = "return", BOOL_EXPR ;

TYPE = "int" | "float" | "boolean" | "string";
COMPARISON = ( "==", ">", "<", ">=", "<=", "!=" );
BOOL_EXPR = BOOL_TERM, { "or", BOOL_TERM };
BOOL_TERM = REL_EXPR, { "and", REL_EXPR };
REL_EXPR = EXPR, { COMPARISON, EXPR };
EXPR = TERM, { ("+" | "-"), TERM };
TERM = FACTOR, { ( "*" | "/" | "%" ), FACTOR };
FACTOR = ( LITERAL | "(", BOOL_EXPR, ")" | "-" FACTOR | "!" FACTOR | IDENTIFIER "(" ARGUMENT_LIST ")" | IDENTIFIER);

LITERAL = INTEGER | FLOAT | BOOLEAN | STRING ;

ARITHMETIC_OPERATOR = "+" | "-" | "*" | "/" ;
BINARY_OPERATOR = ARITHMETIC_OPERATOR | "==" | "!=" | "<" | ">" | "<=" | ">=" ;
UNARY_OPERATOR = "-" | "!" ;

FUNCTION_CALL = IDENTIFIER, "(", [ARGUMENT_LIST], ")" ;
ARGUMENT_LIST = [ BOOL_EXPR ], { ",", BOOL_EXPR } ;

INDENTED_PROGRAM = "\n", INDENT, { STATEMENT }, DEDENT ;

LETTER = "a" | ... | "z" | "A" | ... | "Z" ;
DIGIT = "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" | "0" ;

IDENTIFIER = LETTER, { LETTER | DIGIT | "_" } ;
INTEGER = DIGIT, { DIGIT };
FLOAT = DIGIT, { DIGIT }, ".", { DIGIT };
BOOLEAN = "true" | "false" ;
STRING = `"`, { DIGIT | LETTER }, `"` ;

INDENT = "INDENT" ;  (* Token representing an increase in indentation level *)
DEDENT = "DEDENT" ;  (* Token representing a decrease in indentation level *) ;
```

</details>

## Example
There are several code examples illustrating all language features in the [examples](https://github.com/RicardoRibeiroRodrigues/APS-Linguagem/blob/main/examples/) folder.

Below is an example that uses some features, making it a comprehensive example:
```stp
# Function to calculate the square of a number
fn square(x: int) -> int:
    return x * x

# Main program
var num = 5
var result = 0

# For loop to calculate the sum of squares
for int i = 0; i <= num; i++:
    if i > 0:
        result = result + square(i)

println("The sum of squares is %d", result)
# Conditional statement to check if the result is even or odd
if result % 2 == 0:
    println("The sum of squares is even.")
else:
    println("The sum of squares is odd.")
```

This code:

- Defines a function to calculate the square of an integer.
- Uses a loop to add the square of i from 1 to num (5) to the result.
- Prints the sum of squares.
- Prints whether the result is even or odd.

## Run the Project

To run the language, there are two ways:

### Download the Release Binary

A compiled binary for [Linux has been provided in the repository](https://github.com/RicardoRibeiroRodrigues/APS-Linguagem/releases). Download it, grant execution permissions, and you should be able to use the language compiler.

### Compile Manually

1. Install cmake:
```bash
sudo apt install cmake
```
2. Install LLVM 14.
```bash
sudo apt install llvm-14
```
3. Install **flex** and **bison**.
```bash
sudo apt-get install flex
sudo apt-get install bison
```
4. Run the following command to create the build folder:
```bash
cmake -B build -S .
```
5. Execute the make command in the project:
```bash
cd build
make
```
6. After that, you should have the `statipy` executable inside the `build/src/` folder.

NOTE: There is a possibility that cmake may not recognize the installed LLVM 14. In that case, follow these steps:
1.Run the command `llvm-config --cmakedir` and note the output path.
2. Export the output path to the environment variable (example):
```bash
export LLVM_ROOT="/usr/lib/llvm-14"
```
(Exclude the `lib/cmake/llvm` part)

### Compiler Options

The compiler usage should be as follows:
```bash
./statipy <input_file> [-q] [-v] [-d]
```

Where:
- '-q': Quiet mode, code generation will not print all steps.
- '-d': Debug mode, for both parser and code generation.
- '-v': Verbose mode for code generation, all generation steps will be printed to the console.

## Licença

This project is under the MIT license [see more](LICENSE).

## Referências
- Parser and lexer based on https://gnuu.org/2009/09/18/writing-your-own-toy-compiler/
- AST and code generation adapted from https://github.com/xkbeyer/liquid

# APS Linguagem - Logica da computação

Criação de uma linguagem de programação do zero!


## EBNF

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

## Exemplo
Existem diversos exemplos de código, ilustrando todas as features da linguagem na pasta [examples](https://github.com/RicardoRibeiroRodrigues/APS-Linguagem/blob/main/examples/)

Podemos visualizar abaixo um exemplo que utiliza algumas features e portanto é um exemplo bem completo:
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

Este código:
- Define uma função para calcular o quadrado de um inteiro.
- Faz um loop que soma em result o quadrado de i de 1 até num (5).
- Printa a soma dos quadrados.
- Printa se o resultado é par ou ímpar.

## Rodar o projeto

Para rodar a linguagem, existem duas formas:

### Baixar o binário do release

Foi disponibilizado [no repositório um binário compilado para linux](https://github.com/RicardoRibeiroRodrigues/APS-Linguagem/releases), baixando ele e dando permissões de execução, já deve ser possível usar o compilador desenvolvido para a linguagem.

### Compilar manualmente

1. Instalar o cmake:
```bash
sudo apt install cmake
```
2. Instalar o LLVM 14.
```bash
sudo apt install llvm-14
```
3. Instalar o flex e o bison
```bash
sudo apt-get install flex
sudo apt-get install bison
```
4. Rodar o comando abaixo para criar a pasta build:
```bash
cmake -B build -S .
```
5. Executar o make do projeto:
```bash
cd build
make
```
6. Feito isso você deve ter dentro da pasta `build/src/` o executável `statipy`

OBS:
Existe a possibilidade de o cmake não reconhecer o LLVM 14 instalado, neste caso, siga os seguintes passos:
1. Rode o comando `llvm-config --cmakedir` e anote o caminho da saída
2. exporte para o env o caminho do output anterior (exemplo):
```bash
export LLVM_ROOT="/usr/lib/llvm-14"
```
(Não deve ser incluida a parte do `lib/cmake/llvm`)

### Opções do compilador

O uso do compilador deve ser feito da seguinte maneira:
```bash
./statipy <input_file> [-q] [-v] [-d]
```

Sendo:
- '-q': Modo quieto, a geração de código não vai printar todas as etapas.
- '-d': Modo de debug, tanto do parser como da geração de código.
- '-v': Modo verbose da geração de código, todas as etapas da geração serão printadas no console.

## Licença

Este projeto está sob licença MIT [veja mais](LICENSE).

## Referências
- Parser e lexer baseados em https://gnuu.org/2009/09/18/writing-your-own-toy-compiler/
- AST e geração de código adaptados de https://github.com/xkbeyer/liquid

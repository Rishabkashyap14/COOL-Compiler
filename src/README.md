# Source Code
- Consists of the lex file "cool.l" which acts as our lexical analyzer  
- The "COOL.y" Yacc file builds on all the syntactic as well as the sematic rules to be followed while parsing through the program  
- The symbolTable.h and .c files are used to construct the Symbol Table for the program based on the parser built from the above yacc file
- We then have the typeChecking files that allow us to identify the type of token being parsed 
- The codeOptimization file is used to apply optimization techniques to the parsed AST built by the parser
- The "cfg.c" file gives us the structures used to create the final Tree Structure after the entire process is done  
  
As mentioned earlier, simply run the entire program using `make` command, and `make clean` to clear all output files. The 'test.out' file is the generated compiler,
and we add the file to be compiled as the first argument, in this case:  
`./test.out trial2.cl`

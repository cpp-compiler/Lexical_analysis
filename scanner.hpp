#ifndef SCANNER_HPP
#define SCANNER_HPP
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//FUNCTIONS
typedef enum{_identifier,_eof,_err,_resv_word,_oct,_hex,_rea,_leftp,_rightp,_leftb,_rightb,_sum,_sub,_mult,_div,_coma,_semicolon,_colons} sequential;
sequential next();

/////////////
bool EOFF();
int read();
bool wsp();
void fail();
void sucess();
void full_back();
/////////////

void open(const char*);
///////////////
int automaton_One_id();
int S(int,char);

int automaton_Two_delta();
int S2(int,char);

int automaton_Three_delta_op();
int S3(int,char);

int automaton_Four_wspeof();
int S4(int,char);

int length(char[]);

int compare(char[]);
int compare1(char[]);
int compare2(char[]);

int lines(); 
bool comments();
//int line();
void word();
void clear_word();

bool automaton_One_reserved_word();
bool automaton_One_reserved_word1();
bool automaton_One_reserved_word2();
/*
UNSOLVED TASKS
message when the analysis had finished

number of lines of the file

6. Comentarios
Un comentario es cualquier secuencia de caracteres que inicia con la marca # (hash) y termina con el fin de
línea.

11. Espacios en blanco
Se contempla el uso de espacios, tabuladores y saltos de línea.


token error
	the carather and the line


SOLVED
12. La marca de fin de archivo ( EOF )

*/
#endif


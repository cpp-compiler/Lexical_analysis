#ifndef SCANNER_HPP
#define SCANNER_HPP
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//FUNCTIONS
typedef enum{_identifier,_eof,_err} secuential;
secuential next();
/////////////
bool EOFF();
int read();
bool wsp();
void fail();
void sucess();
void full_back();
/////////////
int token();
char get_letter();
void set_letter(char);
char casting(int);
void open(const char*);
///////////////
int udfa();
int S(int,char);
int length(char[]);
int compare(char[]);
int compare1(char[]);
int compare2(char[]);
int S2(int,char);
int delta();


#endif


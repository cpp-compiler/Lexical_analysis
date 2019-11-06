#ifndef SCANNER_HPP
#define SCANNER_HPP
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//FUNCTIONS
typedef enum{_identifier,_eof,_err,_resv_word,_oct,_hex,_rea} sequential;
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
int udfa();
int S(int,char);
int delta();
int S2(int,char);
int delta_op();
int S3(int,char);
int length(char[]);
int compare(char[]);
int compare1(char[]);
int compare2(char[]);

int line();
void word();
void clear_word();
bool reserved_word();
bool reserved_word1();
bool reserved_word2();

#endif


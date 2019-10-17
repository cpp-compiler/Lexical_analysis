#ifndef SCANNER_HPP
#define SCANNER_HPP
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//FUNCTIONS
bool EOFF();
int read();
bool wsp();
void fail();
void sucess();
void full_back();
int token();
char get_letter();
void set_letter(char);
char get_letter1();
void set_letter1(char);
char casting(int);
void open(const char*);
int udfa();
int S(int,char);
bool reserved_words();
int Srw(int,char);
int length(char[]);
int compare(char[]);
int compare1(char[]);
int compare2(char[]);

#endif


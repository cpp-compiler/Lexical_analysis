#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//VARS

FILE *file_p;
int udef=4;
long q=0;
//FUNCTIONS
int S(int);
bool udfa();
bool identifier();
bool EOFF();
char read();
void fail();
void sucess();
void full_back();
void tokenn();
bool jump();
int main()
{
    char c;
    printf("ka");
    file_p=fopen("text.txt","r");
  /*  while((c=fgetc(file_p))!=EOF){
        printf("%c",c);
    }
*/

    tokenn();
    fclose(file_p);

    return 0;
}
char read(){
    return fgetc(file_p);
}
void fail(){
    fseek(file_p,q,SEEK_SET);
}
void sucess(){
    q=ftell(file_p);
}
void full_back(){
    fseek(file_p,-1,SEEK_CUR);
}
bool EOFF(){
    if(read()==EOF){
        full_back();
        return true;
    }
    full_back();
    return false;
}
bool jump(){
        while(isspace(read()))
        full_back();
        sucess();
        return true;
}
void tokenn(){
    jump();

    do{
        if(identifier()){
            printf("identifier");
        }else{
        printf("error 4004");
        }

    }while(EOFF());
}
/*
bool udfa(){
    int actual=0,prior=0;
    actual=0;
    while(actual!=udef){
        prior=actual;
        actual=S(actual);

    }
    return prior==2;
}*/
/*
int S(int q){
    int state=0;

    switch(q){

        case 0:
                if(read()==A){
                    state=2;
                }else if(read()==sub){
                    state=1;
                }else{
                    state=udef;
                }

            break;
        case 1:
                if((read()==N)||(read()==sub)){
                    state=1;
                }else if(read()==A){
                    state=2;
                }else{
                    state=udef;
                }
            break;
        case 2:
                if((read()==A)||(read==N)||(read==sub)){
                    state=2;
                }else{
                    state=udef;
                }

            break;
        default: state=udef;
    }
    return state;
}*/
bool identifier(){
    int prior=0;
    int actual=0;
    char c;
    while(actual!=udef){
        prior=actual;
        c=read();

        switch(actual){

            case 0:
                    if((read()>=97||read()<=122)||(read()>=65||read()<=90)){
                        actual=2;
                    }else if(read()==' '){
                        actual=1;
                    }else{
                        actual=udef;
                    }

                break;
            case 1:
                    if((read()>=48||read()<=57)||(read()==' ')){
                        actual=1;
                    }else if((read()>=97||read()<=122)||(read()>=65||read()<=90)){
                        actual=2;
                    }else{
                        actual=udef;
                    }
                break;
            case 2:
                    if(((read()>=97||read()<=122)||(read()>=65||read()<=90))||(read()>=48||read()<=57)||(read()==' ')){
                        actual=2;
                    }else{
                        actual=udef;
                    }

                break;

        }
    }
    if(prior==2){
        full_back();
        sucess();

        return true;
    }
    fail();

    return false;
}

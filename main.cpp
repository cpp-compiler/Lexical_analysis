#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//VARS

FILE *file_p;
int udef=-1;
long q=0;
//FUNCTIONS

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
  
    file_p=fopen("text.txt","r");
    /*while((c=fgetc(file_p))!=EOF){
        printf("%c",c);
    }*/
    do{
           printf("%c",read());
     
    }while(EOFF());
        
    
    

    fclose(file_p);

    return 0;
}
char read(){
    return fgetc(file_p);
    
}
bool EOFF(){
    if(!feof(file_p)){
         
        return true;
        
    }else{
        return false;
    }
    /*
   while(read()!=EOF){
       return true;
   }
   return false;*/
}
void sucess(){
    q=ftell(file_p);
}
void fail(){
    fseek(file_p,q,SEEK_SET);
}
void full_back(){
    fseek(file_p,-1,SEEK_CUR);
}
bool identifier(){
    int prior=0;
    int actual=0;
    char c;
    while(actual!=udef){
        prior=actual;
        c=read();

        switch(actual){

            case 0:
                    if((c>=97||c<=122)||(c>=65||c<=90)){
                        actual=2;
                    }else if(c==' '){
                        actual=1;
                    }else{
                        actual=udef;
                    }

                break;
            case 1:
                    if((c>=48||c<=57)||(c==' ')){
                        actual=1;
                    }else if((c>=97||c<=122)||(c>=65||c<=90)){
                        actual=2;
                    }else{
                        actual=udef;
                    }
                break;
            case 2:
                    if(((c>=97||c<=122)||(c>=65||c<=90))||(c>=48||c<=57)||(c==' ')){
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
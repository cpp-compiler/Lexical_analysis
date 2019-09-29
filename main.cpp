#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//VARS
FILE *file_p;
int udef=-1;
long q=0;
char get;
//FUNCTIONS
bool EOFF();
int read();


bool wsp();
bool identifier();
void fail();
void sucess();
void full_back();
void token();

char w;
char get_letter();
void set_letter(char);
char casting(int);
bool calis();

int main(){
    file_p=fopen("text.txt","r");
        do
        {
            //char k=(char)read();
            //printf("%c",k);

            /*if(read()=='\n'){
                printf("JUMP");
            }*//*
            if(read()=='\0'){
                printf("end");
            }*/
            /*wsp();
            if(identifier()){
                printf("yes");
            }else{
                printf("nop");
            }*/
            
            printf("(%c)",get_letter());
            if(get_letter()==' '){
                printf("yes");
            }/*
            if(calis()){
                    printf("yes");
            }else{
                printf("nope");
            }*/
        } while (EOFF());
        
    return 0;
}

bool calis(){
    if(get_letter()==' '){
                
                return true;
    }else{
        
        return false;
    }
}
int read(){
        int c;
        signed int aux;
        char word;
        c=fgetc(file_p);
        aux=c;
    // printf("[{%i}]",c);
    //printf("[%c][%c]",c,aux);
        word=casting(aux);
        set_letter(word);  
        sucess();
    return c;
}
void set_letter(char cyk){
     w=cyk;
}
char get_letter(){
    return w;
}


void sucess(){ q=ftell(file_p); printf("\n{Activated sucess %li}",q);}
void fail(){fseek(file_p,q,SEEK_SET);}
void full_back(){fseek(file_p,-1,SEEK_CUR);}

bool EOFF(){
    if(read()==EOF){  
         //  full_back();  
        return false;      
    }else{
        //    full_back();
        return true; 

    }

}
bool wsp(){
        while(isspace(read()))
        full_back();
        sucess();
        
        return true;
}
bool identifier(){
    int prior;
    int actual=0;
    char c;
    while(actual!=udef){
        prior=actual;
        c=get_letter();
       // printf("{id %c}",c);
        printf("<c[%c] prior[%i] actual[%i]>",c,prior,actual);
        /*if(c=='h'){
            printf("1[YES]");
        }
        if(c==104){
            printf("2[YES]");
        }*/
        if(c==' '){
                        printf("yes ");
                    }
        switch(actual){

            case 0:
                
                    if((c>='a'&& c<='z')||(c>='A'&&c<='Z')){
                        actual=2;
                    }else if(c=='_'){
                        actual=1;
                    }else{
                        actual=udef;
                    }

                break;
            case 1:
                    if((c>='0'&& c<='9')||(c=='_')){
                        actual=1;
                    }else if((c>='a'&& c<='z')||(c>='A'&&c<='Z')){
                        actual=2;
                    }else{
                        actual=udef;
                    }
                break;
            case 2:
                    if(((c>='a'&& c<='z')||(c>='A'&&c<='Z'))||((c>='0'&& c<='9'))||(c=='_')){
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

char casting(int c){
    switch (c)
    {
    case -1:
            break;
    case 32:
            return ' ';
        break;
    case 97:
            return 'a';
        break;
    case 98:
            return 'b';
        break;
    case 99: 
            return 'c';
        break;
    case 100:
            return 'd';
        break;
    case 101:
            return 'e';
        break;
    case 102:
            return 'f';
        break;
    case 103:
            return 'g';
        break;
    case 104:
            return 'h';
        break;
    case 105:
            return 'i';
        break;
    case 106:
            return 'j';
        break;
    case 107:
            return 'k';
        break;
    case 108:
            return 'l';
        break;
    case 109:
            return 'm';
        break;
    case 110:
            return 'n';
        break;
    case 111:
            return 'o';
        break;
    case 112:
            return 'p';
        break;
    case 113:
            return 'q';
        break;
    case 114:
            return 'r';
        break;
    case 115:
            return 's';
        break;
    case 116:
            return 't';
        break;
    case 117:
            return 'u';
        break;
    case 118:
            return 'v';
        break;
    case 119:
            return 'w';
        break;
    case 120:
            return 'x';
        break;
    case 121:
            return 'y';
        break;
    case 122:
            return 'z';
        break;
    
    default:

        break;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//VARS
FILE *file_p;
int udef=-1;
long q=0;
long p=0;
long pp=0;
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
void open(const char*);
bool udfa();
int S(int,char);
int main(){
        open("text.txt");

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

/*
            if(wsp()){
                full_back();
            }
            if(identifier()){
                printf("\nidentificator ");
            }else{
                printf("END FILE");
            }*/

            if(wsp()){
                full_back();
                //sucess();
            }
            if(udfa()){
                printf("\nidentificator ");
            }else{
                printf("ERROR");
            }
/*
            printf("(%c)",get_letter());
            if(get_letter()==' '){
                printf("yes");
            }*//*
            if(calis()){
                    printf("yes");
            }else{
                printf("nope");
            }*/
        } while (EOFF());

    return 0;
}


void open(const char* name){
    file_p=fopen(name,"r");
}
int read(){
        int c;
        signed int aux;
        char word;
        pp=ftell(file_p);

       printf("\n-pos %li-",pp);
        //fseek(file_p,p,SEEK_SET);
        c=fgetc(file_p);
        aux=c;
     //printf("[{%i}]",c);
    //printf("[%c][%c]",c,aux);
        word=casting(aux);
        set_letter(word);

    return c;
}
void set_letter(char cyk){
     w=cyk;
}
char get_letter(){
    return w;
}


void sucess(){ q=ftell((file_p)); printf("\n{Activated sucess %li}",q);}
void fail(){fseek(file_p,q,SEEK_SET);}
void full_back(){ fseek(file_p,-1,SEEK_CUR);}

bool EOFF(){
    if(read()==EOF){
         //printf("si");
        // full_back();
        return false;
    }else{
        //printf("no");
       //  full_back();
        return true;

    }

}
bool wsp(){
        while(isspace(read()))
        full_back();
        sucess();

        return true;
}
bool udfa(){
    int actual=0,prior;
    bool flag_a;
    char c;
    int a,b;

    while(actual!=udef && EOFF()){
        prior=actual;
	    c=get_letter();


        b=actual=S(actual,c);
/*else if(prior==2 && actual==2){
            a=1;
        }*/

       printf(" p%li and q%li",p,q);
       printf("\n<c[%c] prior[%i] actual[%i]>",c,prior,actual);
    }
    if(b==2){
            b=0;
        return true;
    }
    /*
    if(b){
	    return true;

    }else{
        return false;
    }*/

    if(prior==2){

        full_back();
        sucess();

        return true;
    }else{

        fail();

    return false;

    }
}
int S(int q,char c){

    switch(q){
        case 0:

		    if((c>='a'&& c<='z')||(c>='A'&&c<='Z')){
                        return 2;
                    }else if(c=='_'){
                        return 1;
                    }else{
                        return udef;
                    }
            break;
        case 1:

		    if((c>='0'&& c<='9')||(c=='_')){
                        return 1;
                    }else if((c>='a'&& c<='z')||(c>='A'&&c<='Z')){
                        return 2;
                    }else{
                        return udef;
                    }
            break;
        case 2:
                if(((c>='a'&& c<='z')||(c>='A'&&c<='Z'))||((c>='0'&& c<='9'))||(c=='_')){
                        return 2;
                    }else{
                        return udef;
                    }
            break;

    }

}



char casting(int c){
    switch (c)
    {
    case -1:
            break;
    case 32:
            return ' ';
        break;
    case 65:
            return 'A';
        break;
    case 66:
            return 'B';
        break;
    case 67:
            return 'C';
        break;
    case 68:
            return 'D';
        break;
    case 69:
            return 'E';
        break;
    case 70:
            return 'F';
        break;
    case 71:
            return 'G';
        break;
    case 72:
            return 'H';
        break;
    case 73:
            return 'I';
        break;
    case 74:
            return 'J';
        break;
    case 75:
            return 'K';
        break;
    case 76:
            return 'L';
        break;
    case 77:
            return 'M';
        break;
    case 78:
            return 'N';
        break;
    case 79:
            return 'O';
        break;
    case 80:
            return 'P';
        break;
    case 81:
            return 'Q';
        break;
    case 82:
            return 'R';
        break;
    case 83:
            return 'S';
        break;
    case 84:
            return 'T';
        break;
    case 85:
            return 'U';
        break;
    case 86:
            return 'V';
        break;
    case 87:
            return 'W';
        break;
    case 88:
            return 'X';
        break;
    case 89:
            return 'Y';
        break;
    case 90:
            return 'Z';
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

    }
}

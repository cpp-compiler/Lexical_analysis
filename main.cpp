#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//VARS
FILE *file_p;
int udef=-1;
long q=0;
long p=0;

char w;
char a;
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
char word1[]={'i','d','e','n','t','i','t','y'};
char get[30];
int length(char[]);

int main(){
        open("text.txt");
        do
        {
            switch(token()){
                case 1: printf("Identificator");break;
                case 2: printf("reserved word");break;
                case 3: printf("END File");
            }

        } while (EOFF());
    return 0;
}

int token(){


            if(wsp()){
                full_back();
                sucess();
            }
            if(udfa()==1){
                return 1;
            }
            if(udfa()==2){
                return 2;
            }

            if(udfa()==0){
                return 3;
            }
}

int read(){
        int c;
        signed int aux;
        char word;
        //pp=ftell(file_p);
        //p=pp;
       //printf("\n-pos %li-",pp);
        //fseek(file_p,p,SEEK_SET);
        c=fgetc(file_p);
        aux=c;
     //printf("[{%i}]",c);
    //printf("[%c][%c]",c,aux);
        word=casting(aux);
        set_letter(word);

    return aux;
}
void open(const char* name){ file_p=fopen(name,"r");}
void set_letter(char cyk){ w=cyk; }
char get_letter(){ return w; }
void sucess(){ q=ftell((file_p)); printf("\n{Activated sucess %li}",q);}
void fail(){fseek(file_p,q,SEEK_SET);}
void full_back(){ fseek(file_p,-1,SEEK_CUR);}
int Srw(int,char);
bool EOFF(){
    if(read()==EOF){

         //printf("si");
       // full_back();
        return false;
    }
        //printf("no");
        // full_back();
        //sucess();
        return true;

}
bool wsp(){
        while(isspace(read()))
        full_back();
        sucess();
        return true;
}
int length(char c[]){
int i=0;
    while(c[i]!='\0'){
        i++;
    }
    return i;
}
int length1(char c[]){
int i=0;
    while(c[i]!='\0'){
        i++;
    }
    return i;
}
int udfa(){
    int actual=0,prior;
    bool flag_a;
    char c;
    int a,b;
    int resa,resb;
    int i=0;
    int len,len2;
    while(actual!=udef && EOFF()){
        prior=actual;
	    c=get_letter();

        b=actual=S(actual,c);
        get[i]=c;
        i+=1;
       printf(" p%li and q%li",p,q);
       printf("\n<c[%c] prior[%i] actual[%i]>",c,prior,actual);
       len=length(get);
            printf("longi%i",len);
            if(len==8){
               char aux[len];
                    for(int i=0;i<=len;i++){
                        aux[i]=get[i];
                    }
                    int it=0;
                    int prior1;
                    int state1=0;
                    while(state1!=udef){
                        prior1=state1;
                        state1=Srw(prior1,aux[it]);


                        printf("\n prior1[%i] state1[%i]>",prior1,state1);
                        i++;
                    }
                    if(prior1==8){
                        resa=2;
                    }else{
                        resb=1;
                    }

            }else{
                resb=1;
            }
    }/*
    for(int i=0;i<30;i++){
          printf("{%c,%c}",get[i],word1[i]);
        }*/

        if(b==2){
                //full_back();
            //sucess();
            /*len=length(get);

            printf("longi%i",len);
            return 1;*/
            if(resa==2){
                return 2;
            }
            if(resb==1){
                return 1;
            }
            /*
            for(int i=0;i<len;i++){
                printf("{%c,%c}",aux[i],word1[i]);
            }*/


            //return 2;
            /*
            for(int i=0;i<30;i++){


                if(get[i]==word1[i]){
                    return 2;
                }else if(get[i]!=word1[i]){
                    return 1;
                }
            }
            int
            while()*/

        }/*
        for(int i=0;i<30;i++){
            get[i]=' ';
            printf("%c",get[i]);
        }*/
    /*if(b==2){
        for(int i=0;i<30;i++){
            if(get[i]==word1[i]){
                return 2;
            }else if(get[i]!=word1[i]){
                return 1;
            }
        }

        b=0;
    }*/

    if(prior==2){
        full_back();
        sucess();
         for(int i=0;i<30;i++){
            if(get[i]==word1[i]){

                return 2;
            }else if(get[i]!=word1[i]){

                return 1;
            }

        }
        for(int i=0;i<30;i++){
            get[i]=' ';
           // printf("%c",get[i]);
        }

    }else{


        fail();

        return 0;
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
int Srw(int q,char c){
    switch(q){

            case 0:
                if(c=='i'){//i
                  return 1;
                }else{
                    return udef;
                }
                break;
            case 1:
                if(c=='d'){//d
                    return 2;
                }else{
                    return udef;
                }
                break;
            case 2:
                if(c=='e'){//e
                    return 3;
                }else{
                    return udef;
                }
                break;
            case 3:
                if(c=='n'){//n
                    return 4;
                }else{
                    return udef;
                }
                break;
            case 4:
                if(c=='t'){//t
                    return 5;
                }else{
                    return udef;
                }
                break;
            case 5:
                if(c=='i'){//i
                    return 6;
                }else{
                    return udef;
                }
                break;
            case 6:
                if(c=='t'){//t
                    return 7;
                }else{
                    return udef;
                }
                break;
            case 7:
                if(c=='y'){//y
                    return 8;
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
    default:
            return -1;
        break;
    }
}

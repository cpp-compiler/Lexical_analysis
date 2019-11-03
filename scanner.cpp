#include "scanner.hpp"
FILE *file_p;
char word1[]={'i','d','e','n','t','i','t','y'};
char word2[]={'t','r','a','n','s','p','o','s','e'};
char word3[]={'t','h','r','o','w'};
char get[30];

int udef=-1;
long q=0;
long p=0;

char w;
char a;
sequential next(){
        wsp();
        if(udfa()==1){

           
                return _identifier;
        }
        if(udfa()==0){
                return _err;
        }
        if(EOFF()==false){
            return _eof;
        }
}

int read(){
        int c;
        signed int aux;
        char word;
        char wop;
        //pp=ftell(file_p);
        //p=pp;
       //printf("\n-pos %li-",pp);
        //fseek(file_p,p,SEEK_SET);
        c=wop=fgetc(file_p);
        aux=c;
     //printf("[{%i}]",c);
    //printf("[%c][%c]",c,aux);
        word=casting(aux);
        set_letter(word);

    return wop;
}
void open(const char* name){ file_p=fopen(name,"r");}
void set_letter(char cyk){ w=cyk; }
char get_letter(){ return w; }
void sucess(){ q=ftell((file_p)); printf("\n{Activated sucess %li}",q);}
void fail(){fseek(file_p,q,SEEK_SET);}
void full_back(){ fseek(file_p,-1,SEEK_CUR);}
bool EOFF(){
    if(read()==EOF){

        printf("si");
       // full_back();
       
        return false;
    }
        printf("no");
        // full_back();
        //sucess();
       
        return true;

}

bool wsp(){
        while(isspace(read()));
        full_back();
        sucess();
        return true;
     

}

int udfa(){
    int actual=0,prior;
    bool flag_a;
    char c;
    int a,b;
    int i=0;
    while(actual!=udef){
        prior=actual;
	    c=read();

        b=actual=S(actual,c);
        get[i]=c;
        i+=1;
       printf(" p%li and q%li",p,q);
       printf("\n<c[%c] prior[%i] actual[%i]>",c,prior,actual);
    }

        if(b==2){
                //full_back();
            //sucess();
            return 1;

        }


    if(prior==2){
        full_back();
        sucess();

         return 1;

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

char casting(int c){
    switch (c)
    {
    case -1:
            break;
    case 40:
            return '(';
            break;
    case 41:
            return ')';
            break;
    case 91:
            return '[';
            break;
    case 93:
            return ']';
            break;
    case 43:
            return '+';
            break;
    case 45:
            return '-';
            break;
    case 42:
            return '*';
            break;
    case 47:
            return '/';
            break;
    case 46:
            return '.';
            break;
    case 44:
            return ',';
            break;
    case 59:
            return ';';
            break;
    case 58:
            return ':';
            break;
    case 48:
            return '0';
            break;
    case 49:
            return '1';
            break;
    case 50:
            return '2';
            break;
    case 51:
            return '3';
            break;
    case 52:
            return '4';
            break;
    case 53:
            return '5';
            break;
    case 54:
            return '6';
            break;
    case 55:
            return '7';
            break;
    case 56:
            return '8';
            break;
    case 57:
            return '9';
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


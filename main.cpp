#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//VARS
FILE *file_p;
int udef=-1;
long q=0;
long p=0;
long pp=0;
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
char rw[]={'i','d','e','n','t','i','t','y'};
int res[7];
void tokeen();
int main(){
        open("text.txt");
        do
        {
            switch(token()){
                case 1: printf("Identificator");break;
                case 2: printf("reserved word");
                break;
            }

        } while (EOFF());
    return 0;
}

int token(){
          // w=get_letter();

            if(wsp()){
                full_back();
                //sucess();
            }
            if(udfa()==1){
                return 1;
            }else if(udfa()==2){
                return 2;
            }else{
                printf("ERROR");
            }
}
char gotten(){
    return get_letter();
}
int read(){
        int c;
        signed int aux;
        char word;
        pp=ftell(file_p);
        p=pp;
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
void open(const char* name){ file_p=fopen(name,"r");}
void set_letter(char cyk){ w=cyk; }
char get_letter(){ return w; }

void set_letter1(char k){ a=k; }
char get_letter1(){ return a; }

void sucess(){q=p; q=ftell((file_p)); printf("\n{Activated sucess %li}",q);}
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
int udfa(){
    int actual=0,prior;
    bool flag_a;
    char c;
    int a,b;

    while(actual!=udef && EOFF()){
        prior=actual;
	    c=get_letter();
       // set_letter1(c);
        b=actual=S(actual,c);

       printf(" p%li and q%li",p,q);
       for(int i=0;i<7;i++){
            if(rw[i]==c){
                res[i]=1;
                printf("yes");
            }else{
                res[i]=0;
                printf("no");
            }
       }
       printf("\n<c[%c] prior[%i] actual[%i]>",c,prior,actual);
    }
    for(int k=0;k<7;k++){
        if(res[k]==1){
            return 2;
        }else{

        }
    }
    if(b==3){
            b=0;
        return 1;
    }
    printf("\nOUTSIDE c[%c] prior[%i] actual[%i]>",c,prior,actual);
    if(prior==12||prior==22||prior==28){
        return 2;
    }

    if(prior==3){
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
                        return 3;
                    }else{
                        return udef;
                    }
                    if(c=='_'){
                        return 2;
                    }else{
                        return udef;
                    }
                    if(c=='i'){
                    	return 5;
                    }else{
                        return udef;
                    }
                    if(c=='t'){
                    	return 13;
                    }else{
                        return udef;
                    }
            break;
        case 2:

		    if((c>='0'&& c<='9')||(c=='_')){
                        return 2;
                    }else if((c>='a'&& c<='z')||(c>='A'&&c<='Z')){
                        return 3;
                    }else{
                        return udef;
                    }
            break;
        case 3:
                if(((c>='a'&& c<='z')||(c>='A'&&c<='Z'))||((c>='0'&& c<='9'))||(c=='_')||(c==39)){
                        return 3;
                    }else{
                        return udef;
                    }
            break;
        case 5:
        		if(c=='d'){
        			return 6;
        		}else{
        			return udef;
        		}
        	break;
        case 6:
        		if(c=='e'){
        			return 7;
        		}else{
        			return udef;
        		}
        		break;
        case 7:
        		if(c=='n'){
        			return 8;
        		}else{
        			return udef;
        		}
        		break;
        case 8:
        		if(c=='t'){
        			return 9;
        		}else{
        			return udef;
        		}
        		break;
        case 9:
        		if(c=='i'){
        			return 10;
        		}else{
        			return udef;
        		}
        		break;
        case 10:
        		if(c=='t'){
        			return 11;
        		}else{
        			return udef;
        		}
        		break;
        case 11:
        		if(c=='y'){
        			return 12;
        		}else{
        			return udef;
        		}
        		break;
        case 13:
        		if(c=='r'){
        			return 15;
        		}else{
        			return udef;
        		}
        		if(c=='h'){
        			return 25;
        		}else{
        			return udef;
        		}
        		break;
        case 15:
        		if(c=='a'){
        			return 16;
        		}else{
        			return udef;
        		}
        		break;
        case 16:
        		if(c=='n'){
        			return 17;
        		}else{
        			return udef;
        		}
        case 17:
        		if(c=='s'){
        			return 18;
        		}else{
        			return udef;
        		}
        		break;
        case 18:
        		if(c=='p'){
        			return 19;
        		}else{
        			return udef;
        		}
        		break;
        case 19:
        		if(c=='o'){
        			return 20;
        		}else{
        			return udef;
        		}
        		break;
        case 20:
        		if(c=='s'){
        			return 21;
        		}else{
        			return udef;
        		}
        		break;
        case 21:
        		if(c=='e'){
        			return 22;
        		}else{
        			return udef;
        		}
        		break;
       	case 25:
       			if(c=='r'){
       				return 26;
       			}else{
       				return udef;
       			}
       			break;
       	case 26:
       			if(c=='o'){
       				return 27;
       			}else{
       				return udef;
       			}
       			break;
       	case 27:
       			if(c=='w'){
       				return 28;
       			}else{
       				return udef;
       			}
       			break;
    }
}
bool reserved_words(){
    int actual=0,prior;
    char c;
    while(actual!=udef){
        prior=actual;
	   c=get_letter1();
        actual=Srw(actual,c);
        printf("{RW c[%c]prior[%i]actual[%i]}",c,prior,actual);
      // printf(" p%li and q%li",p,q);
    //   printf("\n<c[%c] prior[%i] actual[%i]>",c,prior,actual);
    }


    if(prior==8){
        return true;
    }else{

        return false;
    }
}
int Srw(int q,char c){
    switch(q){

            case 0:
                if(c=='i'){//i
                  return 1;
                }
                break;
            case 1:
                if(c=='d'){//d
                    return 2;
                }
                break;
            case 2:
                if(c=='e'){//e
                    return 3;
                }
                break;
            case 3:
                if(c=='n'){//n
                    return 4;
                }
                break;
            case 4:
                if(c=='t'){//t
                    return 5;
                }
                break;
            case 5:
                if(c=='i'){//i
                    return 6;
                }
                break;
            case 6:
                if(c=='t'){//t
                    return 7;
                }
                break;
            case 7:
                if(c=='y'){//y
                    return 8;
                }
                break;
            case 8:
                return 8;
                break;
        }
        return udef;
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

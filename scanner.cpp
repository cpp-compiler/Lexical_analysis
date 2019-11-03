#include "scanner.hpp"
FILE *file_p;
char word1[]={'i','d','e','n','t','i','t','y'};
char word2[]={'t','r','a','n','s','p','o','s','e'};
char word3[]={'t','h','r','o','w'};
char get[30];
int udef=-1;
long q=0;
long p=0;

sequential next(){
        if(wsp()){
            
        }
        
        if(udfa()==1){   
            return _identifier;
        }
        if(EOFF()){
            printf("yes1");
            return _eof;
        }else{
            printf("no1");
        }
        if(udfa()==0){
            return _err;
        }
        
        //EOFF();
}
int read(){
        char wop;
        //pp=ftell(file_p);
        //p=pp;
       //printf("\n-pos %li-",pp);
        //fseek(file_p,p,SEEK_SET);
        wop=fgetc(file_p);
        
     //printf("[{%i}]",c);
    //printf("[%c][%c]",c,aux);
    return wop;
}
void open(const char* name){ file_p=fopen(name,"r");}
void sucess(){ q=ftell((file_p)); printf("\n{Activated sucess %li}",q);}
void fail(){fseek(file_p,q,SEEK_SET);}
void full_back(){ fseek(file_p,-1,SEEK_CUR);}

bool EOFF(){
   
    while(read()!=EOF)
    {
        printf("no2");
        //full_back();
        return true;
        /*if(read()==EOF){
           printf("yes2");
         //full_back();
         
        return false;     
        }*/
    }
    if(read()==EOF){
        return true;
    }
    return false;
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
       printf("\n<c[%c][%i] prior[%i] actual[%i]>",c,c,prior,actual);
       //EOFF();
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

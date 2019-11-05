#include "scanner.hpp"
FILE *file_p;
char word1[]={'i','d','e','n','t','i','t','y'};//8
char word2[]={'t','r','a','n','s','p','o','s','e'};//9
char word3[]={'t','h','r','o','w'};//5
char get[30];
char get1[30];
int udef=-1;
long q=0;
long p=0;

sequential next(){
        if(wsp()){
            
        }
        
        if(udfa()==1){   
                if(reserved_word()||reserved_word1()||reserved_word2()){
                        clear_word();
                    return _resv_word;
                }else{
                    clear_word();
                return _identifier;
                }
        }
        int d=delta();
        switch (d)
        {
        case 6:
            printf("S1");
            return _oct;
                break;
        case 4:
            printf("S2");
            return _hex;
                 break;    
        case 11:
            printf("S3");
              return _rea;
              break;
        default:

            break;
        }
        
        
        if(EOFF()) return _eof;
       
        return _err;
        
        
        //EOFF();
}
int delta(){
    int len=length(get);
    printf("<lenght %i>",len);
    int actual=0,prior;
    char c;
    int b;
    int i=0;
    while(actual!=udef){
        prior=actual;
	    c=read();

        b=actual=S2(actual,c);
        get[i]=c;
        //get1[i]=c;
        i+=1;
       printf(" p%li and q%li",p,q);
       printf("\n<dc[%c][%i] prior[%i] actual[%i]>",c,c,prior,actual);
       //EOFF();
       word();
    }
    if(prior==6){
        printf("op1");
        full_back();
        sucess();
        
       return 6;
         
    }else{
        fail();
        return 0;
    }
    if(prior==4){
            printf("op2");
            full_back();
        sucess();
        
       return 4;
        
    }else{
        fail();
        return 0;
    }
    if(prior==11||prior==7||prior==9){
            printf("op3");
            full_back();
        sucess();
        
       return 11;
        
        
    }else{
        fail();
        return 0;
    }
     

}
int S2(int q,char c){
    switch(q){
    case 0:
        //printf("\nhere1 [%c]",c);
        if(c=='0'){
            printf("\nhere1 [%c]",c);
            return 1;
        }else if(c>='1'&& c<='9'){
        printf("\nhere2 [%c]",c);

            return 7;
        }else{
            return udef;
        }
        break;
    case 1:
        if(c>='1'&& c<='7'){
            return 6;
        }else if(c=='x'||c=='X'){
            return 3;
        }else if(c=='.'){
            return 8;
        }else{
            return udef;
        }
        break;
    case 3:
        if((c>='0'&& c<='9')||((c>='a'&& c<='f')||(c>='A'&&c<='F'))){
            return 4;
        }else{
            return udef;
        }
        break;
    case 4:
        if((c>='0'&& c<='9')||((c>='a'&& c<='f')||(c>='A'&&c<='F'))){
            return 4;
        }else{
            return udef;
        }
        break;
    case 6:
        if(c>='1'&& c<='7'){
            return 6;
        }else{
            return udef;
        }
        break;
    case 7:
        if(c>='0'&& c<='9'){
            return 7;
        }else if(c=='.'){
            return 8;
        }else if(c=='e'||c=='E'){
            return 10;
        }else{
            return udef;
        }
        break;
    case 8:
        if(c>='0'&& c<='9'){
            return 9;
        }else{
            return udef;
        }
        break;
    case 9:
        if(c>='0'&& c<='9'){
            return 9;
        }else if(c=='e'||c=='E'){
            return 10;
        }else{
            return udef;
        }
        break;
    case 10:
        if(c=='-'||c=='+'){
            return 10;
        }else if(c>='0'&& c<='9'){
            return 11;
        }else{
            return udef;
        }
        break;
    case 11:
        if(c>='0'&& c<='9'){
            return 11;
        }else{
            return udef;
        }
        break;
    }
}
void word(){
    int n=length(get);
    for(int i=0;i<n;i++){
        
           printf("x{%c}",get[i]);   
    }
}
/*********************************************************************************************************************************/
void clear_word(){
    int n=length(get);
    for(int i=0;i<n;i++){
           get[i]=' '; 
           printf("x{%c}",get[i]);   
    }
}
int length(char c[]){
    int i=0;
    while(c[i]!=' ' && c[i]!='\0'){
        i++;
    }
    return i;
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
        printf("yes2");
        //full_back();
        return true;
        /*if(read()==EOF){
           printf("yes2");
         //full_back();
         
        return false;     
        }*/
    }
    if(read()==EOF){
            printf("yes3");
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
/********************************************************************************************************/
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
        get1[i]=c;
        i+=1;
       printf(" p%li and q%li",p,q);
       printf("\n<c[%c][%i] prior[%i] actual[%i]>",c,c,prior,actual);
       //EOFF();
       word();
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
bool reserved_word(){
    if(get[0]==word1[0]){
        if(get[1]==word1[1]){
            if(get[2]==word1[2]){
                if(get[3]==word1[3]){
                    if(get[4]==word1[4]){
                        if(get[5]==word1[5]){
                            if(get[6]==word1[6]){
                                if(get[7]==word1[7]){
                                    return true;
                                }else{
                                    return false;
                                }
                            }else{
                                return false;
                            }
                        }else{
                            return false;
                        }
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
    
}
bool reserved_word1(){
    if(get[0]==word2[0]){
            if(get[1]==word2[1]){
                if(get[2]==word2[2]){
                    if(get[3]==word2[3]){
                        if(get[4]==word2[4]){
                            if(get[5]==word2[5]){
                               if(get[6]==word2[6]){
                                    if(get[7]==word2[7]){
                                        if(get[8]==word2[8]){
                                            return true;
                                        }else{
                                            return false;
                                        }
                                    }else{
                                        return false;
                                    }
                               }else{
                                    return false;
                               }
                            }else{
                                return false;
                            }
                        }else{
                            return false;
                        }
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }else{
                return false;
            }
    }else{
        return false;
    }
}
bool reserved_word2(){
    if(get[0]==word3[0]){
        if(get[1]==word3[1]){
            if(get[2]==word3[2]){
                if(get[3]==word3[3]){
                    if(get[4]==word3[4]){
                        return true;
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}
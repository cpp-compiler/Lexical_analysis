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
long f=0;
bool eof=0;
bool eof1=0;
bool eof2=0;
long line=0;

sequential next(){
        
        if(wsp()){
            printf("YES WHITE");
            
        }
        if(EOFF()){
            return _eof;
        }else{
            if(tokenError()==0){
                return _err;
            } 
            if(automaton_One_id()==1){   
                    if(automaton_One_reserved_word()||automaton_One_reserved_word1()||automaton_One_reserved_word2()){
                            clear_word();
                        return _resv_word;
                    }else{
                        clear_word();
                    return _identifier;
                    }
            }
            int d=automaton_Two_delta();
            if(d==6){
                printf("S1");
                return _oct;
            }else if(d==4){
                printf("S2");
                return _hex;
            }else if(d==11){
                printf("S3");
                return _rea;
            }

                
            int dp=automaton_Three_delta_op();
           // printf("\tDP %i",dp);
            if (dp>=1 && dp<=11)
            {
                if(dp==1){
                    return _leftp;
                }else if(dp==2){
                    return _rightp;
                }else if(dp==3){
                    return _leftb;
                }else if(dp==4){
                    return _rightb;
                }else if(dp==5){
                    return _sum;
                }else if(dp==6){
                    return _sub;
                }else if(dp==7){
                    return _mult;
                }else if(dp==8){
                    return _div;
                }else if(dp==9){
                    return _coma;
                }else if(dp==10){
                    return _semicolon;
                }else if(dp==11){
                    return _colons;
                }
               // printf("###########YES########");
            }else{
             //   printf("###########NOP########");
            }
           if(automaton_Four_comments()==1){
                printf("comments");
                return _comment;
            }
           
           // printf("\tDP %i",dp);
           
           
            
            
            
        }

            
       // return _err;
        
        
    
}

void word(){
    int n=length(get);
    for(int i=0;i<n;i++){
        
           printf("x{%c}",get[i]);   
    }
}

/*********************************************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/


int read(){
    int w;
    w=fgetc(file_p);
    if(w==10){
        lines();
        printf("=================(YES)==============");
    }
    
    
    return w;}
void open(const char* name){ file_p=fopen(name,"r");}
void sucess(){ q=ftell((file_p)); printf("\n{Activated sucess %li}",q);}
void fail(){p=fseek(file_p,q,SEEK_SET);printf("\n{Activated fail %li}",p);}
void full_back(){ f=fseek(file_p,-1,SEEK_CUR);printf("\n{Activated full back %li}",f);}

bool EOFF(){
   
 /* while(read()!=EOF)
    {
        printf("yes2");
        return true;
     */   /*if(read()==EOF){
           printf("yes2");
         //full_back();
         
        return false;     
        }*/
    //}
    if(eof==1||eof1==1){
        return true;
    }
    return false;

    printf("EOF %c,",read());
    /*if(read()==-1){
            printf("yes3");
        return true;
    }
    return false;*/
}
bool wsp(){
        while(isspace(read()));
        full_back();
        sucess();
        return true;
}

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
int lines(){
     return line++;
}
/********************************************************************************************************/
/********************************************************************************************************/
/********************************************************************************************************/

int automaton_One_id(){
    int actual=0,prior,priorr,priors,prior_wsp;
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
       printf("\n<A1 c[%c][%i] prior[%i] actual[%i]>",c,c,prior,actual);
       if(c==-1){//eof
            printf("YEs eof A1");
            
            //fail()
            //return 1;
            
       // return 1;
            actual=-1;
            prior=0;
            priorr=3;
            eof=1;
        }
       if(c==10){//new line
                printf("=====A1 =new line====");
            actual=-1;
            prior=0;
            priorr=0;
            eof=0;
            priors=4;
        }
        if(c==32){
                printf("====A1==SPACE====");
            //eof=1;
            prior_wsp=1;

           // wsp();
        }
       
       word();
    }

    if(prior==2){
        full_back();
        sucess();
        
       return 1;
         
    }else if(priorr==3){
       // prior=0;
       full_back();
        sucess();
        
       return 1;    
    }else if(priors==4){
           full_back();
        sucess();
        return 1;
    }else if(prior_wsp==1){
           //printf("===white====");
            eof1=1;
    }else{
        printf("ACTIVATED FAIL A1");
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
                if(((c>='a'&& c<='z')||(c>='A'&&c<='Z'))||((c>='0'&& c<='9'))||(c=='_')||(c==39)){
                        return 2;
                    }else{
                        return udef;
                    }
                    
            break;
    }
}
int automaton_Two_delta(){
    int len=length(get);
    printf("<lenght %i>",len);
    int actual=0,prior,priorr,aux,priors,aux2;
    char c;
    int b;
    int i=0;
    while(actual!=udef){
        prior=actual;
	    c=read();
        if(c==-1){
            
            eof=1;
            printf(" A2 YES EOF ");
            aux=prior;
            //fail();
            actual=-1;
            prior=0;
            priorr=3;
            
        }
        if(c==10){
            printf("=====A2 =new line====");
            aux2=prior;
            actual=-1;
            prior=0;
            priorr=0;
            eof=0;
            priors=4;
        }
        b=actual=S2(actual,c);
        get[i]=c;
        //get1[i]=c;
        i+=1;
       printf(" p%li and q%li",p,q);
       printf("\n<A2 dc[%c][%i] prior[%i] actual[%i]>",c,c,prior,actual);

       word();
       
    }
    if(prior==6){
        printf("op1");
        full_back();
        sucess();
        
       return 6;
         
    }else if(prior==5){
            printf("op2");
            full_back();
        sucess();
        
       return 4;
        
    }else if(prior==11||prior==7||prior==9){
            printf("op3");
            full_back();
        sucess();
        
       return 11;
        
        
    }else if(priorr==3){
       // prior=0;
       switch (aux)
       {
       case 6:full_back(); sucess(); return 6;break;
       case 5:full_back(); sucess(); return 4;break;
       case 11:full_back(); sucess(); return 11;break;
       case 7:full_back(); sucess(); return 11;break;
       case 9:full_back(); sucess(); return 11;break;
       
       }
           
    }else if(priors==4){
        switch (aux2)
       {
       case 6:full_back(); sucess(); return 6;break;
       case 5:full_back(); sucess(); return 4;break;
       case 11:full_back(); sucess(); return 11;break;
       case 7:full_back(); sucess(); return 11;break;
       case 9:full_back(); sucess(); return 11;break;
       
       }
        full_back(); sucess();
    }else{
        printf("ACTIVATED FAIL A2");
        fail();
        return 0;
    }
     

}
int S2(int q,char c){
    switch(q){
    case 0:
        //printf("\nhere1 [%c]",c);
        if(c=='0'){
             return 1;
        }else if(c>='1'&& c<='9'){
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
            return 5;
        }else{
            return udef;
        }
        break;
    case 5:
        if((c>='0'&& c<='9')||((c>='a'&& c<='f')||(c>='A'&&c<='F'))){
            return 5;
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
int automaton_Three_delta_op(){
     int actual=0,prior,priorr,aux,priors,aux2;
    bool flag_a;
    char c;

    int i=0;
    while(actual!=udef){
        prior=actual;
	    c=read();
        if(c==-1){
            printf("A3 YES EOF");
            aux=prior;
            //fail();
            actual=-1;
            prior=0;
            priorr=3;
            eof=1;
        }
        if(c==10){
            printf("=====A3=new line====");
            aux2=prior;
            actual=-1;
            prior=0;
            priorr=0;
            eof=0;
            priors=4;
        }
        if(c==32){
                printf("=====A3=SPACE====");
            //eof=1;
          //  prior_wsp=1;

           // wsp();
        }
        actual=S3(actual,c);
        
       printf(" p%li and q%li",p,q);
       printf("\n<A3 dpc[%c][%i] prior[%i] actual[%i]>",c,c,prior,actual);
      
    }
       
    
    if(prior==1){       full_back(); sucess(); return 1;
    }else if(prior==2){ full_back(); sucess(); return 2;
    }else if(prior==3){ full_back(); sucess(); return 3;
    }else if(prior==4){ full_back(); sucess(); return 4;
    }else if(prior==5){ full_back(); sucess(); return 5;
    }else if(prior==6){ full_back(); sucess(); return 6;
    }else if(prior==7){ full_back(); sucess(); return 7;
    }else if(prior==8){ full_back(); sucess(); return 8;
    }else if(prior==9){ full_back(); sucess(); return 9;
    }else if(prior==10){full_back(); sucess(); return 10;
    }else if(prior==11){full_back(); sucess(); return 11;
    }else if(priorr==3){
        switch (aux)
        {
        case 1:full_back(); sucess(); return 1;break;
        case 2:full_back(); sucess(); return 2;break;
        case 3:full_back(); sucess(); return 3;break;
        case 4:full_back(); sucess(); return 4;break;
        case 5:full_back(); sucess(); return 5;break;
        case 6:full_back(); sucess(); return 6;break;
        case 7:full_back(); sucess(); return 7;break;
        case 8:full_back(); sucess(); return 8;break;
        case 9:full_back(); sucess(); return 9;break;
        case 10:full_back(); sucess(); return 10;break;
        case 11:full_back(); sucess(); return 11;break;
        
        }
    }else if(priors==4){
        switch (aux2)
        {
        case 1:full_back(); sucess(); return 1;break;
        case 2:full_back(); sucess(); return 2;break;
        case 3:full_back(); sucess(); return 3;break;
        case 4:full_back(); sucess(); return 4;break;
        case 5:full_back(); sucess(); return 5;break;
        case 6:full_back(); sucess(); return 6;break;
        case 7:full_back(); sucess(); return 7;break;
        case 8:full_back(); sucess(); return 8;break;
        case 9:full_back(); sucess(); return 9;break;
        case 10:full_back(); sucess(); return 10;break;
        case 11:full_back(); sucess(); return 11;break;
        
        }
        //full_back(); sucess();
    }else{
        printf("ACTIVATED FAIL A3");
        fail();
        return 0;
    }
}
int S3(int q,char c){
    if(q==0){
        switch (c)
        {
        case '(':return 1;break;
        case ')':return 2;break;
        case '[':return 3;break;
        case ']':return 4;break;
        case '+':return 5;break;
        case '-':return 6;break;
        case '*':return 7;break;
        case '/':return 8;break;
        case ',':return 9;break;
        case ';':return 10;break;
        case ':':return 11;break;   
        }
        return udef;
    }
    return udef;
}
int automaton_Four_comments(){
    int actual=0,prior,prior_a,go_to;
    char c;
    int a;
    int i=0;
    while(actual!=udef){
        prior=actual;
	    c=read();
       if(c==-1){
            printf("YES  EOF A4");
            actual=-1;
            //prior=0;
            eof=1;
            go_to=1;
        }
        actual=S4(actual,c);
        if(prior==2){//this conditional is for stop the algorithm
            actual=-1;
            //printf("STOP");
        }
       printf(" p%li and q%li",p,q);
       printf("\n<A4 dpc[%c][%i] prior[%i] actual[%i]>",c,c,prior,actual);
       
    }
  
    if(prior==2){
        full_back();
        sucess();
        
       return 1;
         
    }else if(go_to==1){
        full_back();
        sucess();
        return 1;
    }else{
        printf("ACTIVATED FAIL A4");
        fail();
        return 0;
    }  

}
int S4(int q,char c){
    switch (q)
    {
    case 0:
        if(c==35){
            return 1;
        }else{
            return udef;
        }
        break;
    case 1:
        if(c>=32 && c<=254){
           // printf("comment");
            return 1;
        }else if(c==10){
           // printf("change");
            return 2;
        }else
        {
            return udef;
        }
        
        break;
    case 2:
        return 2;
        break;
    }
}
int tokenError(){
      int actual=0,prior,priorr,aux,priors,aux2;
    bool flag_a;
    char c;

    int i=0;
    while(actual!=udef){
        prior=actual;
	    c=read();
        if((c>=47 && c<=59) || (c>=40 && c<=45) || (c>=65 && c<=90) || (c>=97 && c<=122)|| (c==39)||(c==35)){
           full_back();
           sucess();
        }else{
            priorr=3;
        }
        actual=-1;
        
           printf(" p%li and q%li",p,q);
        printf("\n<A5 dpc[%c][%i] prior[%i] actual[%i]>",c,c,prior,actual);
      
    }
       
    
     if(priorr==3){
        printf("ACTIVATED FAIL A5");
        fail();
        return 0;
    }
    
}
bool automaton_One_reserved_word(){
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
bool automaton_One_reserved_word1(){
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
bool automaton_One_reserved_word2(){
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
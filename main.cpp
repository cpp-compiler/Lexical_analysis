#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//VARS
FILE *file_p;
int udef=-1;
long q=0;

//FUNCTIONS
bool EOFF();
char read();

bool identifier();
void fail();
void sucess();
void full_back();
void token();
bool wsp();

int main()
{
    char c;
  
    file_p=fopen("text.txt","r");
    
    token();
    //printf("%ld",q);
    fclose(file_p);
    return 0;
}
char read(){
    return fgetc(file_p);
}
bool EOFF(){
    if(!feof(file_p)){    
        return true;      
    } 
        return false; 
}

bool wsp(){  
        while (isspace(read()))
        {
        full_back();
        sucess();
        return true;
        }      

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
void token(){
   
    do{
       // wsp();
           //printf("%i  %c",i,read());
           
            //printf("[%d]",identifier());
            if(identifier()){
                printf(" ID ");
            }else{
                printf(" <err> ");
            }
         
            
    }while(EOFF());
        
}

bool identifier(){
    
    int prior;
    char c;
    int actual=0;

    while(actual!=udef){
        prior=actual;
        c=read();
        printf("%c",c);
        
       printf("[%i,%i]",prior,actual);
                    /*if(isspace(c)){
                        //wsp();
                        full_back();
                        sucess();
                        prior=actual=0;
                    }*/
                    //printf("here");
        switch(actual){
            case 0:
                    if((c>=97||c<=122)||(c>=65||c<=90)){
                        actual=2;
                    }else if(c=='_'){
                        actual=1;
                    }else{

                        actual=udef;
                    }

                break;
            case 1:
                    if((c>=48||c<=57)||(c=='_')){
                        actual=1;
                    }else if((c>=97||c<=122)||(c>=65||c<=90)){
                        actual=2;
                    }else{
                        actual=udef;
                    }
                break;
            case 2:
                    
                    if(((c>=97||c<=122)||(c>=65||c<=90))||(c>=48||c<=57)||(c=='_')){
                        actual=2;
                    }else{
                    actual=udef;
                    }
                    actual=udef;
                    

                break;
                  
            
        }

       
        
    }
    if(prior==2){
           // full_back();
         //   sucess();
            actual=0;

        //    printf("-%i-",prior);
            return true;
    }else{
             fail();

    return false; 

    }
    
    
}
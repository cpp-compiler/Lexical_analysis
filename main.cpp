#include "scanner.hpp"
int main(){
    open("text.txt");
        sequential tokenn;

        do
        {
            tokenn=next();
            switch(tokenn){
                case 0: printf("Identificator");break;
                case 1: printf("EOF");break;
                case 2: printf("ERR");break;
                case 3: printf("Reserved word");break;
                case 4: printf("Octal number"); break;
                case 5: printf("Hexadecimal"); break;
                case 6: printf("Real number"); break;
                /*case 1: printf("Identificator");break;
                case 2: printf("Reserved word");break;
                
                
                

                case 7: printf("END File");*/
            }

        } while (tokenn!=_eof && tokenn!=_err);

    return 0;
}

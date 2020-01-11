#include "scanner.hpp"
int main(){
    open("text.txt");
        sequential tokenn;

        do
        {
            tokenn=next();
            switch(tokenn){
                case 0: printf("Identificator");break;
                case 1: printf("EOF \n\nThe analysis had finished.");printf("\n==========Total Lines: %i========= ",lines());break;
                case 2: printf("ERR");printf("Error in line : %i ",lines());break;
                case 3: printf("Reserved word");break;
                case 4: printf("Octal number"); break;
                case 5: printf("Hexadecimal"); break;
                case 6: printf("Real number"); break;
                case 7: printf("Delimitation character Left parenthesis"); break;
                case 8: printf("Delimitation character Right parenthesis"); break;
                case 9: printf("Delimitation character Left bracket"); break;
                case 10: printf("Delimitation character Right bracket"); break;
                case 11: printf("Arithmetic operator sum");break;
                case 12: printf("Arithmetic operator substraction");break;
                case 13: printf("Arithmetic operator multiplication");break;
                case 14: printf("Arithmetic operator division"); break;
                case 15: printf("Puntuation sign comma");break;
                case 16: printf("Puntuation sign semicolon"); break;
                case 17: printf("Assign operator colon"); break;
                case 18: /*printf("comments");*/ break;
                /*case 1: printf("Identificator");break;
                case 2: printf("Reserved word");break;
                
                
                

                case 7: printf("END File");*/
            }

        } while (tokenn!=_eof && tokenn!=_err);

    return 0;
}

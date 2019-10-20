#include "scanner.hpp"
int main(){
    open("text.txt");
        do
        {
            switch(token()){
                case 1: printf("Identificator");break;
                case 2: printf("Reserved word");break;
                case 3: printf("Octal number"); break;
                case 4: printf("Hexadecimal"); break;
                case 5: printf("Real number"); break;

                case 7: printf("END File");
            }

        } while (EOFF());
    return 0;
    return 0;
}

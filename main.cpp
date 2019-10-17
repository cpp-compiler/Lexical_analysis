#include "scanner.hpp"
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
    return 0;
}

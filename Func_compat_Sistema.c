//verifica sistema operacional
#ifdef WIN32
#include <windows.h>
#define WIN 1
#else
#include <unistd.h>
#define WIN 0
#endif // WIN32


void espera(int t){
    if(WIN == 1){
        Sleep(t);
    }else{
        sleep(t/1000);
    }
}

void limpa(){
    if(WIN == 1){
        system("cls");
    }else{
        system("clear");
    }
}
void amarelo(){
    if(WIN == 1){
        system("color 06");
    }else{
    printf("\x1B[33m");
    }
}

void vermelho(){
    if(WIN == 1){
        system("color 04");
    }else{
        printf("\x1B[31m");
    }
}

void verde(){
    if(WIN == 1){
        system("color 02");
    }else{
        printf("\x1B[32m");
    }
}

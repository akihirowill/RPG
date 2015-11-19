#ifndef RPG_H
#define RPG_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct{
    int classe;
    char *classname;
    int str;
    int dex;
    int con;
} Class;

typedef struct{
    char *nome;
    int str;
    int dex;
    int con;
    int gold;
    int exp;
} Monsters;
Monsters Monstros[10][3];
Monsters Instrutores[9]; // Structure com os instrutores
Monsters Eenlucifer; // Sttructure boss final
Class Personagem;
void imprimechar (Class Personagem, int nivel, char* nome, int expa, int expt,int hpa,int hpmax, int gold, int hppot);
void imprimemenu (Class Personagem, int nivel, char* nome, int expa, int expt,int hpc, int hpmax, int gold, int hppot);
void imprimemonasterio (Class Personagem, int nivel, char* nome, int expa, int expt,int hpa,int hpmax, int gold, int hppot);
void monasterio(int *gold, int *hpa, int hpmax, int *hppot, int action);
void imprimetreino (Class Personagem, int nivel, char* nome, int expa, int expt,int hpa,int hpmax, int gold, int hppot);
void treino (Class *Personagem, int nivel, int *gold, int action,int *hpc, int *hpmax);
void imprimeexplora (Class Personagem, int nivel, char* nome, int expa, int expt,int hpa,int hpmax, int gold, int hppot);
int batalha( Class *Personagem, int*gold, int *expa, int expt, char* nome, Monsters Monstros[][3],int niv, int j,int *hpa, int hpmax,int *hppot);
void imprimemestre (Class Personagem, int nivel, char* nome, int expa, int expt, int hpa, int hpmax, int gold, int hppot);
void explora (int action,int nivel, Class *Personagem, int *gold, int *expa, int expt,char* nome,int *hpa, int hpmax, int *hppot,int *death);
void mestre (Class *Personagem, int* nivel, int* gold, int* expa, int* expt,char* nome,Monsters Instrutores[],int *hpa, int *hpmax, int *hppot,int n);
void boss (Class *Personagem,char* nome,Monsters Eenlucifer,int *hpa, int *hpmax, int *hppot,int n,int* win, int* death);
void incrementa (Class *Personagem,int n);
#endif

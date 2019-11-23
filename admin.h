#ifndef DEF_admin
#define DEF_admin
#include<stdio.h>
#include<stdlib.h>
#include"fonctions.h"
typedef struct admine{

char smdp[20];

}admine;
echelon * cree_echelon();
int admin(char *motdepasse1,char*motfepasse2);
void admine_securite( FILE *fichier);
void menu_admin(FILE*fichier,char *question,char* ra,char*wa1,char*wa2,char *wa3);
#endif



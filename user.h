
#ifndef DEF_user
#define DEF_user
#include "fonctions.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct{
 char nom[50];
 char prenom[50];
 char mot_de_passe[20];
 int level;
}user;
user* creer_user(char * Nom,char * Prenom,char * Motdepasse,int level);
void enregistrer(user *p);
int verifie(char *nom_entree,char *mdp_entree,FILE *fichier);
int user_menu();
int repondre(int a,int b);
user* modifier_user(int i, char *nom,char*prenom,char*ANmdp);
int passe(int i,int k);
int maxim(int a,int b);
#endif

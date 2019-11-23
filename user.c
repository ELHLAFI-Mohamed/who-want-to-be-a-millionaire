#ifndef DEF_question
#define DEF_question
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"user.h"
#include "fonctions.h"
user* creer_user(char * Nom,char * Prenom,char * Motdepasse,int level){
    user *compte=(user*)malloc(sizeof(user));
   strcpy(compte->nom,Nom);
  strcpy(compte->prenom,Prenom);
  strcpy(compte->mot_de_passe,Motdepasse);
  compte->level=0;
    return compte;
}
void enregistrer(user *p){
    char name [10];
    strcpy(name,p->nom);
FILE* fichier=fopen(name,"wb");
fwrite(p,sizeof(user),1,fichier);
fclose(fichier);
}
int verifie(char *nom_entree,char *mdp_entree,FILE *fichier){
    user *how=(user*)malloc(sizeof(user));
    if (fichier==NULL){
            printf("error le nom n existe pas");
    return 9;
    }
    else {
        fread(how,sizeof(user),1,fichier);
        return (strcmp(mdp_entree,how->mot_de_passe)); /*return 0 si le mdp est correct */
    }
}
user* modifier_user(int i, char *nom,char*prenom,char*ANmdp){
    char nvnom[20],nvprenom[20],nvmdp[20];
    user* ancompte=(user*)malloc(sizeof(user));
    FILE *fichier=fopen(nom,"rb");
    fread(ancompte,sizeof(user),1,fichier);
    fclose(fichier);
    switch(i){
    case 0:printf("donner le nouveau nom\n");
    scanf("%s",nvnom);
    strcpy(ancompte->nom,"");
    strcpy(ancompte->nom,nvnom);break;
    case 1:printf("donner le nouveau prenom\n");
    scanf("%s",nvprenom);
    strcpy(ancompte->prenom,"");
    strcpy(ancompte->prenom,nvprenom);break;
    case 2:printf("donner le nouveau mot de passe\n");
    scanf("%s",nvmdp);
    strcpy(ancompte->mot_de_passe,"");
    strcpy(ancompte->mot_de_passe,nvmdp);
    break;
    }
    return ancompte;
}
int passe(int i,int k){
    if (k==1){
    if (i==5)  return 1;
    else return 0;
    }
    if (k==0) return 0;
    return 300;

}
int maxim(int a,int b){
    if (a>b) return a;
    else return b;
}
#endif

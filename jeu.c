#include"admin.h"
#include<stdio.h>
#include <stdlib.h>
#include"jeu.h"
#include<string.h>
#include"fonctions.h"
int repondre(int reponse,int choice)
{
    switch(choice){
    case 0 :
        switch(reponse){
        case 1 : return 1;break;
        case 2 : return 0;break;
        case 3 : return 0;break;
        case 4 : return 0;break;
        case 5 : return 5;break;
        case 6 : return 6;break;
        case 7 : return 7;break;
    }
        case 1:
            switch(reponse){
        case 1 : return 0;break;
        case 2 : return 0;break;
        case 3 : return 1;break;
        case 4 : return 0;break;
        case 5 : return 5;break;
        case 6 : return 6;break;
        case 7 : return 7;break;

}
        case 2:
            switch(reponse){
        case 1 : return 0;break;
        case 2 : return 1;break;
        case 3 : return 0;break;
        case 4 : return 0;break;
        case 5 : return 5;break;
        case 6 : return 6;break;
        case 7 : return 7;break;

}
        case 3:
            switch(reponse){
        case 1 : return 0;break;
        case 2 : return 0;break;
        case 3 : return 0;break;
        case 4 : return 1;break;
        case 5 : return 5;break;
        case 6 : return 6;break;
        case 7 : return 7;break;

}
    }
    return 4000;
}
void insertion(echelon *liste,FILE *fichier)
{
    /* Création du nouvel élément */
    echelon *nouveau = cree_echelon();
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau=remplir_echelon(fichier,nouveau);

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->suivant;
    liste->suivant = nouveau;
}
int barrer_50(int i,int j){
    if(j){
        if (i==6) return 1;
        else return 0;
    }
    else {
            return 0;
    }
}
int barrer_25(int i,int j){
    if(j){
        if (i==7) return 1;
        else return 0;
    }
    else {
            return 0;
    }
    return 40000;
}

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"user.h"
#include"fonctions.h"
#include"admin.h"
#include <time.h>
#include"jeu.h"
#include"rlutil.h"
int main()
{ int option,jouer,w,cadmin=0;
/*FILE* fichier=fopen("Admin1","wb");
admine_securite(fichier); */  /*on execute une seule fois ces deux instructions  pour donner a l'admin la permission de changer le mot de passe*/


do{
        setColor(10);
    printf("bonjour et binvenue au jeu\n:" );
    printf("             *$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*             \n ");
    printf("         **   ################################   **         \n ");
    printf("       ***    ################################   ***        \n ");
    printf("      ****    ################################   ****       \n ");
setColor(1);
setBackgroundColor(15);
    printf("              WHO WANTS TO BE A MILLIONNAIRE                 \n");
    setBackgroundColor(0);
    setColor(10);
    printf("      ****    ################################   ****       \n ");
    printf("       ***    ################################   ***        \n ");
    printf("         **   ################################   **         \n ");
    printf("             *$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*             \n ");
    setColor(5);
    printf("\n\nchoisir une option:\n1:COMMENCER LE JEU\n2:QUITTER \n3:LOGIN AS ADMIN\n");
    scanf("%d",&option);
    if(option==2){
        break;
    }
    if (option==3){
        cls();
            char mdp[20]; /* char ou on va retourne le mot de passe entree*/
            admine * ad1=(admine*)malloc(sizeof(admine));
            do{
            setColor(7);
            printf("entrer le mot de passe de l'Admin\n");
            scanf("%s",mdp);
            FILE *fichier_mpd=fopen("Admin1","rb");
            fread(ad1,sizeof(admine),1,fichier_mpd);
            fclose(fichier_mpd);
            if (admin(ad1->smdp,mdp)!=0){
                setColor(4);
                printf("mot de passe incorrect\n");
                }
                cadmin++;
            }while(admin(ad1->smdp,mdp)!=0 && cadmin!=3);
            if(cadmin==3){
                setColor(4);
                printf("vous etes pas un admin");

            }
           else {int choix_admine;
        cls();
           do{
              setColor(7);
           printf("Bonjour\n");
           printf("pour changer le mot de passe tapper 1\npour charger les question a zero tapper 2\n pour retoure au meunu principale taper 3\n  ");
           scanf("%d",&choix_admine);
           if(choix_admine==2){
            char question[200],ra[100],Wa1[100],Wa2[100],Wa3[100]; /* on va retourner les questions et reponses entrer par l'admin */
            FILE* fichier=NULL;
            int j;
            fichier = fopen("questions.bin", "wb");
            for(j=1;j<=nbr_quest;j++){
            printf("donner la question la reponse vrais et les reponese faux dans cette ordre");
            scanf(" %[^\t\n]s",question);
            scanf(" %[^\t\n]s",ra);
            scanf(" %[^\t\n]s",Wa1);
            scanf(" %[^\t\n]s",Wa2);
            scanf(" %[^\t\n]s",Wa3);
            menu_admin(fichier,question,ra,Wa1,Wa2,Wa3);
                    cls();
            }
            fclose(fichier);
    }
    if(choix_admine==1){
        char nwempd[20];
        printf("donner le nouveau mot de passe\n ");
        scanf("%s",nwempd);
        admine *ad2;
        ad2=(admine*)malloc(sizeof(admine));
        strcpy(ad2->smdp,nwempd);
        FILE* fichier=fopen("Admin1","wb");
        fwrite(ad2,sizeof(admine),1,fichier);
        fclose(fichier);
                cls();



    }
           }while(choix_admine!=3);
    }
    }
    user*temp=(user*)malloc(sizeof(user));
    if (option==1){
            setColor(7);
            printf("pour cree un nouveau compte tapez 1 \n");
            printf("pour acceder a votre compte tapez 2 \n");
            scanf("%d",&w);
                    cls();
            if(w==1){
                char nom[10],prenom[10],motdepasse[10];
                user * utilisateur;
                printf("entrer votre nom ,prenom et mot de passe:\n");
                scanf("%s%s%s",nom,prenom,motdepasse);
                utilisateur=creer_user(nom,prenom,motdepasse,0);
                enregistrer(utilisateur);
                temp=utilisateur;
                        cls();
            }
            if(w==2){
                    int verify,i=1;
                    char nom[20],prenom[20],motdepasse[20];
                        do{
                            setColor(7);
                printf("entrer le nom  et le mot de passe\n ");
                scanf("%s%s",nom,motdepasse);
                FILE* fichier=fopen(nom,"rb");
                verify=verifie(nom,motdepasse,fichier);
                 fclose(fichier);
                 i++;
                        }while(verify!=0 && i!=3 );
                        if(i==3){
                            setColor(3);
                            printf("vous avez depassée le nombre de saisie\n ");
                            w=3;


                        }
                    else{
                            FILE* fichier=fopen(nom,"rb");
                            fread(temp,sizeof(user),1,fichier);
                        setColor(7);
                    printf("BONJOUR Mr %s !!!\n",nom);
                    printf("Pour jouer taper 1\n");
                    printf("Pour Modifier votre compte tapper 0\n");
                    scanf("%d",&jouer);
                            cls();
                    if(jouer==0){
                            int mode;
                            user* nouveau_compte=(user*)malloc(sizeof(user));
                    printf("pour modifier le nom taper 0\npour modifier le prenom taper 1\npour modifier le mot de passe taper 2:\n");
                    scanf("%d",&mode);
                    if(mode==1 || mode==2){
                    nouveau_compte=modifier_user(mode,nom,prenom,motdepasse);
                    FILE *fichier=fopen(nom,"wb");
                    fwrite(nouveau_compte,sizeof(user),1,fichier);
                    fclose(fichier);
                    }
                    if(mode==0){
                        nouveau_compte=modifier_user(mode,nom,prenom,motdepasse);
                        FILE *fichier=fopen(nouveau_compte->nom,"wb");
                        fwrite(nouveau_compte,sizeof(user),1,fichier);
                        fclose(fichier);
                    }
                    printf("pour commencer le jeux tapez 1 ou taper 0 pour modifier votre compte");
                    scanf("%d",&jouer);
                           cls();
                    }
                    }
                }
            }
                if(jouer==1 || w==1){
            int choix,reponse,answer=0,num_quest=1;
            FILE* fichier=NULL;
            fichier=fopen("questions.bin","rb");
            echelon*tete=cree_echelon();
            tete->suivant=NULL;
            int k;
        for (k=1;k<=nbr_quest;k++){
                insertion(tete,fichier);
    }
    fclose(fichier);
    echelon *p=tete->suivant;
    int switch_availabe=1,barrer50=2,barrer25=1;
    fclose(fichier);
   int t=1;int niveau;
   do{
        cls();
         printf("les regles deux jeux taper 0 pour quitter 5 POUR switcher 6 pour 50/50 ET 7 POUR 25/25\n\n");
        setColor(0);
   setBackgroundColor(3);
   if(t!=0){
            bravo(num_quest-1);
            printf("\n");
   }
   setColor(0);
   setBackgroundColor(15);
    choix=affichage_questions(p,num_quest,0);
          num_quest++;
           setColor(15);
   setBackgroundColor(0);
          scanf("%d",&reponse);
          answer=repondre(reponse,choix);
          if(passe(answer,switch_availabe)==1 ){
                p=p->suivant;
                num_quest--;
          answer=1;
          switch_availabe=0;
          t=0;
          }
          else if (barrer_50(answer,barrer50)==1){
              num_quest--;
                 choix=affichage_questions(p,num_quest,barrer50);
                 scanf("%d",&reponse);
                  answer=repondre(reponse,choix);
                  barrer50=0;
                   p=p->suivant;
                   num_quest++;
                   t=0;
                   }
          else if (barrer_25(answer,barrer25)==1){
                t=0;
                num_quest--;
                 choix=affichage_questions(p,num_quest,barrer25);
                 scanf("%d",&reponse);
                  answer=repondre(reponse,choix);
                  barrer25=0;
                   p=p->suivant;
          num_quest++;
          }

          else{
          p=p->suivant;
          t=1;
          }
    }while(answer==1 && num_quest<nbr_quest);
    niveau=(num_quest-1);
    temp->level=maxim(temp->level,niveau);
    cls();
    if(reponse ==0){
               setColor(0);
   setBackgroundColor(4);
        bravo(num_quest-2);
        printf("A la praochane fois  ");
    }
    else{
if(num_quest<2){
        setColor(0);
   setBackgroundColor(4);
        printf("DOMMAAAAAGE VOUS AVEZ PERDU TOTALEMENT AVEC UN PALIER DE 0 DH\n ");
        }
if(num_quest>2 && num_quest<=6){
    setColor(0);
   setBackgroundColor(4);
    printf("DOMMAGE VOUS AVEZ PERDU TOTALEMENT AVEC UN PALIER DE 100 DH\n ");
}
if(num_quest>6 && num_quest<=11){
    setColor(0);
   setBackgroundColor(4);
    printf("DOMMAGE VOUS AVEZ PERDU TOTALEMENT AVEC UN PALIER DE 1000 DH\n");
}
if(num_quest>11 && num_quest<16){
    setColor(0);
   setBackgroundColor(4);
    printf("DOMMAGE VOUS AVEZ PERDU TOTALEMENT AVEC UN PALIER DE 32000 DH\n");
}
if(num_quest==16){
    setColor(0);
   setBackgroundColor(2);
        printf("BRAVOOOOOO VOUS AVEZ GAGNER UN MILLION!!");
    }
    printf("\n votre meilleur score est %d\n",temp->level);
    FILE*ut=fopen(temp->nom,"wb");
    fwrite(temp,sizeof(user),1,ut);
    fclose(ut);
    }
    }
    setBackgroundColor(0);
}while(option!=2);
    }





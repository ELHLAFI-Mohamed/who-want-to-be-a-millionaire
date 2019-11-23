#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include"fonctions.h"
#include"user.h"
int  affichage_questions(echelon *p,int num_quest,int barrer){
    srand(time(NULL));
    int r=(rand() %4);
int choice;
if(barrer==0){
switch (r){
    case 0:printf("LA QUESTION NUMERO:%d\n%s\n1-%s\t2-%s\n3-%s\t4-%s\n",num_quest,p->Question,p->rightanswer,p->Wanswer_1,p->Wanswer_2,p->Wanswer_3);choice=0;break;
    case 1:printf("LA QUESTION NUMERO:%d\n%s\n1-%s\t2-%s\n3-%s\t4-%s\n",num_quest,p->Question,p->Wanswer_2,p->Wanswer_1,p->rightanswer,p->Wanswer_3);choice=1;break;
    case 2:printf("LA QUESTION NUMERO:%d\n%s\n1-%s\t2-%s\n3-%s\t4-%s\n",num_quest,p->Question,p->Wanswer_1,p->rightanswer,p->Wanswer_2,p->Wanswer_3);choice=2;break;
    case 3:printf("LA QUESTION NUMERO:%d\n%s\n1-%s\t2-%s\n3-%s\t4-%s\n",num_quest,p->Question,p->Wanswer_3,p->Wanswer_1,p->Wanswer_2,p->rightanswer);choice=3;break;
}
}
if(barrer==1){
    switch (r){
    case 0:printf("LA QUESTION NUMERO:%d\n%s\n1-%s\t2-%s\n--------\t4-%s\n",num_quest,p->Question,p->rightanswer,p->Wanswer_1,p->Wanswer_3);choice=0; break;
    case 1:printf("LA QUESTION NUMERO:%d\n%s\n--------\t2-%s\n3-%s\t4-%s\n",num_quest,p->Question,p->Wanswer_1,p->rightanswer,p->Wanswer_3);choice=1;break;
    case 2:printf("LA QUESTION NUMERO:%d\n%s\n1-%s\t2-%s\n--------\t4-%s\n",num_quest,p->Question,p->Wanswer_1,p->rightanswer,p->Wanswer_2);choice=2;break;
    case 3:printf("LA QUESTION NUMERO:%d\n%s\n1-%s\t--------\n3-%s\t4-%s\n",num_quest,p->Question,p->Wanswer_1,p->Wanswer_2,p->rightanswer);choice=3;break;
    }
}
if(barrer==2){
     switch (r){
    case 0:printf("LA QUESTION NUMERO:%d\n%s\n1-%s\t2-%s\n--------\t--------\n",num_quest,p->Question,p->rightanswer,p->Wanswer_3);choice=0; break;
    case 1:printf("LA QUESTION NUMERO:%d\n%s\n--------\t2-%s\n3-%s\t--------\n",num_quest,p->Question,p->Wanswer_1,p->rightanswer);choice=1;break;
    case 2:printf("LA QUESTION NUMERO:%d\n%s\n1-%s\t2-%s\n--------\t--------\n",num_quest,p->Question,p->rightanswer,p->Wanswer_2);choice=2;break;
    case 3:printf("LA QUESTION NUMERO:%d\n%s\n--------\t2-%s\n--------\t4-%s\n",num_quest,p->Question,p->Wanswer_1,p->rightanswer);choice=3;break;
    }
}
printf("choisir la bonne reponse !\n");
return choice ;
}
echelon *remplir_echelon(FILE*fichier,echelon * p){
    fread(p,sizeof(echelon),1,fichier);
    return p;
}
int bravo(int i){
switch(i){
case 0:printf("*******{$$ BONNE CHANCE!!!!!$$}*******\n\n");break;
case 1:printf("****bravo!vous avez mantenant %d DH****\n",100);return 100;break;
case 2:printf("****bravo!vous avez mantenant %d DH****\n",200);return 200;break;
case 3:printf("****bravo!vous avez mantenant %d DH****\n",400);return 400;break;
case 4:printf("****bravo!vous avez mantenant %d DH****\n",500);return 500 ;break;
case 5:printf("****bravo!vous avez mantenant %d DH****\n",1000);return  1000;break;
case 6:printf("****bravo!vous avez mantenant %d DH****\n",2000);return  2000;break;
case 7:printf("****bravo!vous avez mantenant %d DH****\n",4000);return 4000;break;
case 8:printf("****bravo!vous avez mantenant %d DH****\n",8000);return 8000;break;
case 9:printf("****bravo!vous avez mantenant %d DH****\n",16000);return  16000;break;
case 10:printf("****bravo!vous avez mantenant %d DH****\n",32000);return 32000;break;
case 11:printf("****bravo!vous avez mantenant %d DH****\n",64000);return 64000;break;
case 12:printf("****bravo!vous avez mantenant %d DH****\n",125000);return 125000;break;
case 13:printf("****bravo!vous avez mantenant %d DH****\n",250000);return 250000;break;
case 14:printf("****bravo!vous avez mantenant %d DH****\n",5000000);return 500000;break;
}
return 1000000;
}


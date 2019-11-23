#include"admin.h"
#include<string.h>
echelon * cree_echelon(){
    echelon *pi=malloc(sizeof(*pi));
    return pi;
}
void menu_admin(FILE*fichier,char *question,char* ra,char*wa1,char*wa2,char *wa3){
    echelon * q;
                q=cree_echelon();
                strcpy(q->Question,question);
                strcpy(q->rightanswer,ra);
                strcpy(q->Wanswer_1,wa1);
                strcpy(q->Wanswer_2,wa2);
                strcpy(q->Wanswer_3,wa3);
    fwrite(q,sizeof(echelon),1,fichier);
}


int admin(char *motdepasse1,char*motfepasse2){
    return strcmp(motdepasse1,motfepasse2);
}
void admine_securite( FILE *fichier){
admine *ad;
ad=(admine*)malloc(sizeof(admine));
strcpy(ad->smdp,"");
strcpy(ad->smdp,"admin123");
fwrite(ad,sizeof(admine),1,fichier);
fclose(fichier);
}






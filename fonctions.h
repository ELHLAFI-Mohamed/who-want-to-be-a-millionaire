#ifndef DEF_fonctions
#define DEF_fonctions
typedef struct echelon echelon;
struct echelon{
    char  Question[200] ;
    char rightanswer [100];
    char Wanswer_1[100];
    char Wanswer_2[100];
    char Wanswer_3[100];
    struct echelon *suivant;
};
echelon *remplir_echelon(FILE*fichier,echelon * p);
int  affichage_questions(echelon *p,int num_quest,int barrer);
int bravo(int i);


#endif


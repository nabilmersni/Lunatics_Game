#ifndef enigme_H_INCLUDED
#define enigme_H_INCLUDED



#include "struct.h"


int Init_enigme(enigme *g );
void afficherEnigme(enigme *e);
int genererEnigme();
void pause(SDL_Surface *screen);

void sauvegarder(int heropos,int heroposy ,int enemypos,int enemyposy ,int vie ,int score  ,int camera , int heropos1  , int enigme ,int enigmey  , char *nomfichier , int enigme_reponse , int enigme2_reponse ,int enigme2x , int enigme2y);
void Save(SDL_Surface *screen);
void charger(int *heropos,int *heroposy , int *enemypos ,int *enemyposy,int *vie ,int *score  ,int *camera , int *heropos1  , int *enigme ,int *enigmey , char *nomfichier , int *enigme_reponse , int *enigme2_reponse ,int *enigme2x , int *enigme2y);
void getPose2(int *heropos,int *heroposy , int *enemypos ,int *enemyposy,int *vie ,int *score  ,int *camera , int *heropos1  , int *enigme ,int *enigmey , int *enigme_reponse , int *enigme2_reponse ,int *enigme2x , int *enigme2y );



#endif // DS_H_INCLUDED
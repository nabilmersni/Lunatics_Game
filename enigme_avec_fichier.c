#include "Headers/headers.h"

//----------------------------Fonction init enigme-----------------------------------------
int Init_enigme(enigme *g ) 
{ char quest1[100],choix1[100],choix2[100],win[100],lose[100],rep1[3],line[300] , rep1hover[100] , rep2hover[100];

g->poschoix.x = 2180 ;
g->poschoix.y = 400;
g->choix= IMG_Load("Assets/graphic/enigme1/selectE.png");

int i,j;
    FILE *fichier = NULL;
    fichier= fopen("text.txt","r"); 
   i=genererEnigme();
    if(fichier!=NULL)

    {
      
      for(j=0;j<i+1;j++)
      {
         fgets(line,300,fichier) ;
      }
     
char * token = strtok(line, " "); 
 
   
    
    strcpy(choix1,token);
    token = strtok(NULL, " "); 

    strcpy(choix2,token);
    token = strtok(NULL, " ");

    strcpy(rep1,token);
    token = strtok(NULL, " ");
 
    strcpy(quest1,token);
     token = strtok(NULL, " ");

    strcpy(win,token);
    token = strtok(NULL, " ");
 
    strcpy(lose,token);
    token = strtok(NULL, " ");

    strcpy(rep1hover,token);
    token = strtok(NULL, " ");

    strcpy(rep2hover,token);


      
    }


g->pos.x=0;
g->pos.y=0;
g->reponse= IMG_Load(choix1);
g->reponse1= IMG_Load(choix2); 
g->enigme= IMG_Load(quest1);

g->reponse_pos.x = 0;
g->reponse_pos.y = 0;


g->t=IMG_Load(win);
g->h = IMG_Load(lose);
g->reponsehover = IMG_Load(rep1hover);
g->reponse1hover = IMG_Load(rep2hover);
strcpy(g->rep,rep1);

  
}

//---------------------------Fonction afficher enigme-------------------------------------------
void afficherEnigme(enigme *e )
{ 
     

    SDL_Surface * screen, *score;;
    Hero hero;
    char direction[50];
    char scoreText[100];
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Lunatics", NULL); //window title

   //declare simple variables
    bool running=true;
	int i,enigme_reponse=0;
    GameplayBg b;
    enemie f;
  
    //-------

     Input I;
     I.up=0;
  I.save=1;
    //----------
  
      TTF_Init();
    TTF_Font *police;
    police = police = TTF_OpenFont("Assets/fonts/DelaGothicOne-Regular.ttf", 25);
    SDL_Color white = {0, 0, 0};
   sprintf(scoreText, "Score: %d", hero.score);

  
   //declare the event
	SDL_Event event;

SDL_EnableKeyRepeat(200,0);
while(running)
{

while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
        SDL_Quit();
			running=false;
		break; 
        case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				case SDLK_KP1:
                if (strcmp(e->rep,"1")==0)
                {       
                    SDL_BlitSurface(e->reponsehover,NULL,screen,&e->reponse_pos); 
                    SDL_Flip(screen);
                     SDL_Delay(200);  
                      
                     //  updateHeroScore(&hero, &hero.score, police, white, scoreText, screen); 
                        stage_1(screen , 1) ;            
                }
                else
                {
                    SDL_BlitSurface(e->reponse1hover,NULL,screen,&e->reponse_pos);
                     SDL_Flip(screen);
                     SDL_Delay(200); 
                  //updateHeroHealth(&hero, direction);
                    stage_1(screen , 1) ;   
                 
                }
               
                
                break;

            case SDLK_KP2:
            if (strcmp(e->rep,"2")==0)
                {
                    SDL_BlitSurface(e->reponsehover,NULL,screen,&e->reponse_pos); 
                    SDL_Flip(screen);
                     SDL_Delay(200); 
                     I.up=1;
                  
             // updateHeroScore(&hero, &hero.score, police, white, scoreText, screen);

                 stage_1(screen ,1) ;
              
                }
                else
                {
                     SDL_BlitSurface(e->reponse1hover,NULL,screen,&e->reponse_pos);
                     SDL_Flip(screen);
                     SDL_Delay(200); 
I.up=2;
                  //updateHeroHealth(&hero, direction);

                 stage_1(screen ,1) ;
                }
    
                break;
			}  
		break;

        case SDL_KEYUP:
			switch (event.key.keysym.sym) 
			{	
				
			}
		break;
	    }
     
       
    }

     SDL_BlitSurface(e->enigme,NULL,screen,&e->pos);
     SDL_BlitSurface(e->reponse,NULL,screen,&e->reponse_pos);  
     SDL_BlitSurface(e->reponse1,NULL,screen,&e->reponse_pos);
    
SDL_Flip(screen);
SDL_Delay(16); 
} 

}

//-----------------------------------Fonction generer enigme-------------------------------------------
int genererEnigme()
{
int i ;
srand(time(NULL));
i=(rand()%2);
 return i ;
}



void pause(SDL_Surface *screen)
{
    enemie f;
    enigme enigme_avec_fichier;
    Hero hero;
    GameplayBg b;



    int english, done = 1;
    int enigme_reponse , enigme2_reponse;
    int resInputHover = 0, savInputHover = 0, setInputHover = 0, quiInputHover = 0;
    getlanguage(&english);
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    SDL_WM_SetCaption("Lunatics", NULL); //window title

    //initialise audio
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);

    //declare and set music
    Mix_Music *music;
    music = Mix_LoadMUS("Assets/graphic/MainMenu/ost.mp3");

    //declare and set the hover sound effect
    Mix_Chunk *hoverSound;
    hoverSound = Mix_LoadWAV("Assets/graphic/settings/click.wav");

    //get the music volume from the file
    /* getVolume(&musicVol);

    volBarIndex = musicVol / 20;*/

    //set the music volume andplay it
    //  Mix_VolumeMusic(musicVol);
    Mix_PlayMusic(music, -1);

    hoverSound = Mix_LoadWAV("Assets/graphic/settings/click.wav");

    SDL_Surface *BACKGROUND, *RESUMER_b[2], *SAVE_b[2], *SETTINGS_b[2], *QUITE_b[2];
    SDL_Surface *BACKGROUND_FR, *RESUMER_b_FR[2], *SAVE_b_FR[2], *SETTINGS_b_FR[2], *QUITE_b_FR[2];
    BACKGROUND = IMG_Load("Assets/graphic/stages/bg.jpg");
    RESUMER_b[0] = IMG_Load("Assets/graphic/stages/resume0.png");
    RESUMER_b[1] = IMG_Load("Assets/graphic/stages/resume1.png");
    SAVE_b[0] = IMG_Load("Assets/graphic/stages/save0.png");
    SAVE_b[1] = IMG_Load("Assets/graphic/stages/save1.png");
    SETTINGS_b[0] = IMG_Load("Assets/graphic/stages/settings0.png");
    SETTINGS_b[1] = IMG_Load("Assets/graphic/stages/settings1.png");
    QUITE_b[0] = IMG_Load("Assets/graphic/stages/exit0.png");
    QUITE_b[1] = IMG_Load("Assets/graphic/stages/exit1.png");

    BACKGROUND_FR = IMG_Load("Assets/graphic/stages/bg.jpg");
    RESUMER_b_FR[0] = IMG_Load("Assets/graphic/stages/resumefr0.png");
    RESUMER_b_FR[1] = IMG_Load("Assets/graphic/stages/resumefr1.png");
    SAVE_b_FR[0] = IMG_Load("Assets/graphic/stages/savefr0.png");
    SAVE_b_FR[1] = IMG_Load("Assets/graphic/stages/savefr1.png");
    SETTINGS_b_FR[0] = IMG_Load("Assets/graphic/stages/parametre0.png");
    SETTINGS_b_FR[1] = IMG_Load("Assets/graphic/stages/parametre1.png");
    QUITE_b_FR[0] = IMG_Load("Assets/graphic/stages/quitter0.png");
    QUITE_b_FR[1] = IMG_Load("Assets/graphic/stages/quitter1.png");

    SDL_Rect pos;

    pos.x = 0;
    pos.y = 0;
    SDL_Event event;

    while (done)
    {
        if (english == 0)
        {
            SDL_BlitSurface(BACKGROUND, NULL, screen, &pos);
            SDL_BlitSurface(RESUMER_b[resInputHover], NULL, screen, &pos);
            SDL_BlitSurface(SAVE_b[savInputHover], NULL, screen, &pos);
            SDL_BlitSurface(SETTINGS_b[setInputHover], NULL, screen, &pos);
            SDL_BlitSurface(QUITE_b[quiInputHover], NULL, screen, &pos);
        }
        else if (english == 1)
        {
            SDL_BlitSurface(BACKGROUND_FR, NULL, screen, &pos);
            SDL_BlitSurface(RESUMER_b_FR[resInputHover], NULL, screen, &pos);
            SDL_BlitSurface(SAVE_b_FR[savInputHover], NULL, screen, &pos);
            SDL_BlitSurface(SETTINGS_b_FR[setInputHover], NULL, screen, &pos);
            SDL_BlitSurface(QUITE_b_FR[quiInputHover], NULL, screen, &pos);
        }
        SDL_Flip(screen);

        if (SDL_WaitEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                done = 0;
                SDL_Quit();
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                   // done = 0;
                    stage_1(screen ,2);
                    break;

                case SDLK_UP:
                    if (resInputHover == 0 && savInputHover == 0 && setInputHover == 0 && quiInputHover == 0)
                    {
                        resInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 1 && savInputHover == 0 && setInputHover == 0 && quiInputHover == 0)
                    {
                        resInputHover = 0;
                        quiInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 0 && savInputHover == 0 && setInputHover == 0 && quiInputHover == 1)
                    {
                        quiInputHover = 0;
                        savInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 0 && savInputHover == 1 && setInputHover == 0 && quiInputHover == 0)
                    {
                        savInputHover = 0;
                        setInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 0 && savInputHover == 0 && setInputHover == 1 && quiInputHover == 0)
                    {
                        setInputHover = 0;
                        resInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }

                    break;

                case SDLK_DOWN:
                    if (resInputHover == 0 && savInputHover == 0 && setInputHover == 0 && quiInputHover == 0)
                    {
                        resInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 1 && savInputHover == 0 && setInputHover == 0 && quiInputHover == 0)
                    {
                        resInputHover = 0;
                        setInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 0 && savInputHover == 0 && setInputHover == 1 && quiInputHover == 0)
                    {
                        setInputHover = 0;
                        savInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 0 && savInputHover == 1 && setInputHover == 0 && quiInputHover == 0)
                    {
                        savInputHover = 0;
                        quiInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 0 && savInputHover == 0 && setInputHover == 0 && quiInputHover == 1)
                    {
                        quiInputHover = 0;
                        resInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }

                    break;
                case SDLK_RETURN:
                    if (resInputHover == 1)
                    {
                        stage_1(screen , 2);
                    }
                    else if (setInputHover == 1)
                    {
                        settingsMenu(screen);
                    }
                    else if ( savInputHover ==1)
                    {
                        getPose2(&hero.heroPos.x ,&hero.heroPos.y, &f.rect.x, &f.rect.y ,&hero.hp ,&hero.score  ,&b.camera.x ,&hero.heroPos_relative.x  , &enigme_avec_fichier.poschoix.x ,&enigme_avec_fichier.poschoix.y , &enigme_reponse , &enigme2_reponse);
                    }
                    else if (quiInputHover == 1)
                    {
                        done = 0;
                    }
                    break;
                }
            }
        }
    }

    SDL_FreeSurface(screen);
    SDL_Quit();
}


//save the pose  to the file "savepos.txt"
void sauvegarder(int heropos,int heroposy ,int enemypos,int enemyposy ,int vie ,int score  ,int camera , int heropos1  , int enigme ,int enigmey  , char *nomfichier , int enigme_reponse , int enigme2_reponse)
{
    FILE *fichier = NULL;
    fichier = fopen(nomfichier, "w");
    fprintf(fichier, "%d %d %d %d %d %d %d %d %d %d %d %d" ,heropos,heroposy ,enemypos,enemyposy, vie ,score  ,camera , heropos1  ,enigme, enigmey ,enigme_reponse ,enigme2_reponse);
    fclose(fichier);
}

//get the pos  from the file "savepos.txt"
void charger(int *heropos,int *heroposy , int *enemypos ,int *enemyposy,int *vie ,int *score  ,int *camera , int *heropos1  , int *enigme ,int *enigmey , char *nomfichier , int *enigme_reponse , int *enigme2_reponse)
{
    FILE *fichier = NULL;
    fichier = fopen(nomfichier, "r");
    while (!feof(fichier))
    {
    fscanf(fichier, "%d %d %d %d %d %d %d %d %d %d %d %d" ,heropos,heroposy ,enemypos, enemyposy, vie ,score  ,camera ,heropos1  ,enigme, enigmey , enigme_reponse, enigme2_reponse);
    //fscanf(fichier,"%d",heropos->x);
    }
    fclose(fichier);
}


//sauvegarder les données de fichier savepos2.txt dans le fichier savepos.txt
void getPose2(int *heropos,int *heroposy , int *enemypos ,int *enemyposy,int *vie ,int *score  ,int *camera , int *heropos1  , int *enigme ,int *enigmey , int *enigme_reponse , int *enigme2_reponse )
{
    FILE *fichier = NULL;
    fichier = fopen("Fichier/savepos2.txt", "r");
    
    FILE *fichier1 = NULL;
    fichier1 = fopen("Fichier/savepos.txt", "w");

    while ( (!feof(fichier)) && (!feof(fichier1)) )
    {
    fscanf(fichier  , "%d %d %d %d %d %d %d %d %d %d %d %d" ,heropos,heroposy ,enemypos, enemyposy, vie ,score  ,camera ,heropos1  ,enigme, enigmey ,enigme_reponse,enigme2_reponse);
    fprintf(fichier1, "%d %d %d %d %d %d %d %d %d %d %d %d" ,*heropos,*heroposy ,*enemypos,*enemyposy, *vie ,*score  ,*camera , *heropos1  ,*enigme, *enigmey ,enigme_reponse , enigme2_reponse);
    }
    fclose(fichier);
    fclose(fichier1);
}




/*

//save the pose  to the file "savepos.txt"
void sauvegarder(Hero hero, enemie f , enigme enigme_avec_fichier , GameplayBg b ,char *nomfichier )
{
   
enemie f;
    enigme enigme_avec_fichier;
    Hero hero;
    GameplayBg b;




    FILE *fichier = NULL;
    fichier = fopen(nomfichier, "w");
    fprintf(fichier, "%d %d %d %d %d %d %d %d %d %d" ,hero.heroPos.x,hero.heroPos.y ,f.rect.x,f.rect.y, hero.hp ,hero.score  ,b.camera.x , hero.heroPos_relative.x  , enigme_avec_fichier.poschoix.x , enigme_avec_fichier.poschoix.y);
    fclose(fichier);
}

//get the pos  from the file "savepos.txt"
void charger(Hero *hero, enemie *f , enigme *enigme_avec_fichier , GameplayBg *b ,char *nomfichier )
{
    FILE *fichier = NULL;
    fichier = fopen(nomfichier, "r");
    while (!feof(fichier))
    {
    fscanf(fichier, "%d %d %d %d %d %d %d %d %d %d" ,hero->heroPos.x,hero->heroPos.y ,f->rect.x,f->rect.y, hero->hp ,hero->score  ,b->camera.x , hero->heroPos_relative.x  , enigme_avec_fichier->poschoix.x , enigme_avec_fichier->poschoix.y);
    //fscanf(fichier,"%d",heropos->x);
    }
    fclose(fichier);
}

*/
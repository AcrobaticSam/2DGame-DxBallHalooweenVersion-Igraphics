#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED
using namespace std;

int image[50];

//Co-Ordinates::
int woodx = 800;
int woody = 50;
int pumpkinx = 900;
int pumpkiny = 100;
int pumpkinxspeed = 10;
int pumpkinyspeed = 5;

//Scorings::
int scorepoints = 0;
char score[500];
int r, g, b,p;

//Image Directories::
int bat;
int pumpkin;
int background;
int background1;
int background2;
int instructionimage;
int creditpage;
//Game Mode Mechanisms:
bool game = false;
bool gamestart = false;
bool gameover = false;
bool menu = true;
int option = false;
int credit = false;

int button[50];
int buttonsize[50];
int buttonanimation[6] = { true, true, true, true, true };

//menubutton
int buttonwidth = 220;
int buttonheight = 32;

#endif // VARIABLES_H_INCLUDED

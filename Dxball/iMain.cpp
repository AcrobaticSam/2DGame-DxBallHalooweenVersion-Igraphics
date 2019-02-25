#include "iGraphics.h"
#include "bitmap_loader.h"
#include<iostream>
#include"structure.h"
#include"variables.h"

void iDraw()
{
	iClear();
	if (menu)
	{
		iShowImage(0, 0, 1920, 1000, background2);


		if (buttonanimation[1])
			iShowImage(80, 700, buttonwidth, buttonheight, button[0]);
		if (!buttonanimation[1])
			iShowImage(80, 700, buttonwidth, buttonheight, button[4]);
		if (buttonanimation[2])
			iShowImage(80, 600, buttonwidth, buttonheight, button[1]);
		if (!buttonanimation[2])
			iShowImage(80, 600, buttonwidth, buttonheight, button[7]);
		if (buttonanimation[3])
			iShowImage(80, 500, buttonwidth, buttonheight, button[2]);
		if (!buttonanimation[3])
			iShowImage(80, 500, buttonwidth, buttonheight, button[5]);
		if (buttonanimation[4])
			iShowImage(80, 400, buttonwidth, buttonheight, button[3]);
		if (!buttonanimation[4])
			iShowImage(80, 400, buttonwidth, buttonheight, button[6]);


	}
	if (option)
		iShowImage(0, 0, 1900, 1000, instructionimage);
	if (credit)
		iShowImage(0, 0, 1900, 1000, creditpage);
	if (game)
	{
		iShowImage(0, 0, 1920, 1000, background);
		iShowImage(pumpkinx, pumpkiny, 100, 100, pumpkin);
		iShowImage(woodx, woody, 300, 50, image[2]);
		iSetColor(r, g, b);
		sprintf(score, "%d", scorepoints);
		iText(1700, 50, "Score :", GLUT_BITMAP_HELVETICA_18);
		iText(1780, 50, score, GLUT_BITMAP_HELVETICA_18);
		for (int i = 0; i < 800; i++)
		{
			if (brick[i].show)
			{
				iShowImage(brick[i].brickx, brick[i].bricky, 200, 100, bat);
			}
		}
	}
	if (gameover)
	{
		iShowImage(0, 0, 1920, 1000, background1);
		iSetColor(r, g, b);
		iText(900, 500, "Score : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(970, 500, score, GLUT_BITMAP_TIMES_ROMAN_24);
	}

}

void iMouseMove(int mx, int my)
{
	woodx = mx;
}


void iMouse(int button, int state, int mx, int my)
{

	if (my >= 700 && my <= 732)
	{

		if (mx >= 80 && mx <= 300)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{

				menu = false;
				option = false;
				credit = false;
				game = true;
			}
		}
	}
	if (my >= 600 && my <= 632)
	{

		if (mx >= 80 && mx <= 300)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{

				menu = false;
				option = true;
				credit = false;
				game = false;
			}
		}
	}
	if (my >= 500 && my <= 532)
	{

		if (mx >= 80 && mx <= 300)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{
				menu = false;
				option = false;
				credit = true;
				game = false;
			}
		}
	}
	if (my >= 400 && my <= 432)
	{

		if (mx >= 80 && mx <= 300)
		{
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
				exit(0);
		}
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		cout << mx <<endl<< my<<endl;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		exit(0);
	}
}

void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	if (key == 'a')
	{
		if (woodx > 0)
		{
			woodx -= 20;
		}
	}
	if (key == 'd')
	{
		if (woodx <= 1580)
		{
			woodx += 20;
		}
	}
	if (key == 'w')
	{
		iResumeTimer(p);
	}
	if (key == 's')
	{
		iPauseTimer(p);
		
	}
	if (key == 'm')
	{
		menu = true;
		game = false;
		gamestart = false;
		gameover = false;
	}
	if (key == ' ')
	{
		gamestart = true;
	}
	if (key == '\b')
	{
		gameover = false;
		game = false;
		menu = true;
		option = false;
		credit = false;
		pumpkiny = 90;
		gamestart = false;
		woodx = 800;
		woody = 50;
	}
}
void iPassiveMouse(int mx, int my)
{

	if (my >= 700 && my <= 732)
	{

		if (mx >= 80 && mx <= 300)
		{
			buttonanimation[1] = false;
		}
		else
			buttonanimation[1] = true;
	}
	else
		buttonanimation[1] = true;

	if (my >= 600 && my <= 632)
	{

		if (mx >= 80 && mx <= 300)
		{
			buttonanimation[2] = false;
		}
		else
			buttonanimation[2] = true;
	}
	else
		buttonanimation[2] = true;

	if (my >= 500 && my <= 532)
	{

		if (mx >= 80 && mx <= 300)
		{

			buttonanimation[3] = false;
		}
		else
			buttonanimation[3] = true;
	}
	else
		buttonanimation[3] = true;

	if (my >= 400 && my <= 432)
	{

		if (mx >= 80 && mx <= 300)
		{

			buttonanimation[4] = false;

		}
		else
			buttonanimation[4] = true;
	}
	else
		buttonanimation[4] = true;

}

void ballchange()
{
	//RGB Animations::
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
	

	//Pumpkin Movement Animations::
	if (gamestart)
	{
		pumpkinx += pumpkinxspeed;
		pumpkiny += pumpkinyspeed;
		if (pumpkinx >= 1870 || pumpkinx <= 0)
		{
			pumpkinxspeed *= (-1);
		}
		else if (pumpkiny >= 970)
		{
			pumpkinyspeed *= (-1);
		}
		else if (pumpkiny <= 0)
		{
			gameover = true;
			game = false;

		}
		if (pumpkinx >= woodx && pumpkinx <= woodx + 300 && pumpkiny >= woody+30 && pumpkiny <= woody + 50)
		{
			pumpkinyspeed *= (-1);
		}

		for (int i = 0; i < 36; i++)
		{
			if (brick[i].show)
			{
				if (pumpkinx >= brick[i].brickx && pumpkinx <= brick[i].brickx + 100)
				{
					if (pumpkiny >= brick[i].bricky && pumpkiny <= brick[i].bricky + 20)
					{
						pumpkinyspeed *= (-1);
						brick[i].show = false;
						scorepoints++;
					}
				}
				else if (pumpkiny >= brick[i].bricky && pumpkiny <= brick[i].bricky + 20)
				{
					if (pumpkinx >= brick[i].brickx && pumpkinx <= brick[i].brickx + 100)
					{
						pumpkinxspeed *= (-1);
						brick[i].show = false;
						scorepoints++;
					}
				}
			}
		}
	}
}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (woodx > 0)
			woodx -= 30;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		if (woodx <= 1580)
		woodx += 30;
	}
}
void setbricks()
{
	int bkx = 10;
	int bky = 850;
	for (int i = 0; i < 36; i++)
	{
		brick[i].brickx = bkx;
		brick[i].bricky = bky;
		bkx += 200;
		if (bkx >= 1800)
		{
			bkx = 10;
			bky -= 100;
		}
	}
}


int main()
{
	setbricks();
	iInitialize(1900, 1000, "Halloween ball");
	p=iSetTimer(5, ballchange);

	image[2] = iLoadImage("wood.png");
	image[3] = iLoadImage("bricks.png");
	background=iLoadImage("new.jpg");
	background1 = iLoadImage("gameover.png");
	background2 = iLoadImage("mainmenu.png");
	pumpkin = iLoadImage("pumpkin.png");
	bat = iLoadImage("bat.png");
	instructionimage = iLoadImage("images\\instructions.png");
	creditpage = iLoadImage("images\\credit.png");

	button[0] = iLoadImage("images\\button\\newgame.png");
	button[2] = iLoadImage("images\\button\\credits.png");
	button[3] = iLoadImage("images\\button\\quit.png");
	button[1] = iLoadImage("images\\button\\option.png");

	button[4] = iLoadImage("images\\button\\newgame2.png");
	button[5] = iLoadImage("images\\button\\credits2.png");
	button[6] = iLoadImage("images\\button\\quit2.png");
	button[7] = iLoadImage("images\\button\\option2.png");

	iStart(); 

	return 0;
}


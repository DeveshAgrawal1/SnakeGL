#include<gl\freeglut.h>
#include<iostream>
using namespace std;
int snakedirx, snakediry;
int snakepositionsx[10000], snakepositionsy[10000];
int foodx, foody,level=0,fooddirx,fooddiry,screen=0;
int score, highscore,flag=0;
int snakesize;  
char buffer[10];
bool gameover;

void initgame()
{
	glClearColor(0,0,0,1);
	snakesize = 4;
	snakepositionsx[0] = 320; 
	snakepositionsy[0] = 240; 
	snakepositionsx[1] = 310;
	snakepositionsy[1] = 240;
	snakepositionsx[2] = 300;
	snakepositionsy[2] = 240;
	snakepositionsx[3] = 290;
	snakepositionsy[4] = 240;
	snakedirx = 0;
	snakediry = 1;
	fooddirx=1;
	fooddiry=0;
	score = 0;
	level=0;
	foodx = (rand() % 630) + 15; //put the food in random x position
	foody = (rand() % 470) + 15; //put the food in random x position
}



void drawString (void * font, char *s, float x, float y){
	unsigned int i;

	 glRasterPos2f(x, y);
	 
     for (i = 0; i < strlen (s); i++)
	 {
          glutBitmapCharacter (font, s[i]);
	 }
}

void drawFood()
{
	//draw the food in yellow
	if(screen==1)
	{
	if(score>=250&&score<500)
	{
		level=1;
	}
	else if(score>=500)
	{
		level=2;
	}
	if(level==0)
	{
		glBegin(GL_QUADS);
			glColor3f(1, 1, 0);
			glVertex2f (foodx - 5, foody - 5);
			glVertex2f (foodx - 5, foody + 5);
			glVertex2f (foodx + 5, foody + 5);
			glVertex2f (foodx + 5, foody - 5);
	   glEnd();
	   
	}
	else if(level==1)
	{
		foodx+=fooddirx*5;
	foody+=fooddiry*5;
	
	if(foodx - 5 < 0 || foodx + 5 > 640 ||foody - 5 < 0 || foody + 5 > 480)
	{
		
		fooddirx=-fooddirx;
		fooddiry=-fooddiry;
	}

	for(int i=1;i<snakesize;i++)
	{
	if(snakepositionsx[i] + 5 > foodx - 5 && snakepositionsx[i] - 5 < foodx + 5 && snakepositionsy[i] - 5 < foody + 5 && snakepositionsy[i] + 5 > foody - 5)
	{	fooddirx=-fooddirx;
	fooddiry=-fooddiry;
	}
	}

	glBegin(GL_QUADS);
		glColor3f(1, 1, 0);
		glVertex2f (foodx - 5, foody - 5);
		glVertex2f (foodx - 5, foody + 5);
		glVertex2f (foodx + 5, foody + 5);
		glVertex2f (foodx + 5, foody - 5);
	glEnd();
	}
	else if(level>1)
	{
	foodx+=fooddirx*8;
	foody+=fooddiry*8;
	
	if(foodx - 5 < 0 || foodx + 5 > 640 ||foody - 5 < 0 || foody + 5 > 480)
	{
		
		fooddirx=-fooddirx;
		fooddiry=-fooddiry;
	}
	if(((foody-5<=130)||(foody+5>=300))&&(foodx>=470)&&(foodx<=500))
	{
		
			fooddiry=-fooddiry;
	}
	if(((foody-5<=130)||(foody+5>=300))&&(foodx>=100)&&(foodx<=130))
	{
		
			fooddiry=-fooddiry;
	}
	if(((foody-5>=230)||(foody+5<=200))&&(foodx>=270)&&(foodx<=300))
	{
		
			fooddiry=-fooddiry;
	}
	if((foody-5<=330)&&(foodx>=100)&&(foodx<=130))
	{
		
			fooddiry=-fooddiry;
	}
	if((foody-5<=330)&&(foodx>=470)&&(foodx<=500))
	{
		
			fooddiry=-fooddiry;
	}
	if((foody+5>=100)&&(foodx>=100)&&(foodx<=130))
	{
		
			fooddiry=-fooddiry;
	}
	if((foody+5>=100)&&(foodx>=470)&&(foodx<=500))
	{
		
			fooddiry=-fooddiry;
	}



	if((foodx+5>=100)&&(foody<=130&&foody>=100))
	{
		
		fooddirx=-fooddirx;
	}
	if((foodx+5>=100)&&(foody<=330&&foody>=300))
	{
		
		fooddirx=-fooddirx;
	}
	if((foodx-5<=500)&&(foody<=130&&foody>=100))
	{
		
		fooddirx=-fooddirx;
	}
	if((foodx-5<500)&&(foody<=330&&foody>=300))
	{
		
		fooddirx=-fooddirx;
	}
	if(fooddirx==1&&(foodx<270))
	{
		if((foodx+5>270)&&(foody<=230&&foody>=200))
		{
			
		fooddirx=-fooddirx;
		}
	}
	else if(fooddirx==-1&&(foodx>300))
	{
		if((foodx-5<300)&&(foody<=230&&foody>=200))
		{
			
		fooddirx=-fooddirx;
		}
	}
	if((foodx-5<130||foodx+5>470)&&(foody<=130&&foody>=100))
		fooddirx=-fooddirx;
	if((foodx-5<130||foodx+5>470)&&(foody<=330&&foody>=300))
		fooddirx=-fooddirx;
	glBegin(GL_QUADS);
		glColor3f(1, 1, 0);
		glVertex2f (foodx - 5, foody - 5);
		glVertex2f (foodx - 5, foody + 5);
		glVertex2f (foodx + 5, foody + 5);
		glVertex2f (foodx + 5, foody - 5);
	glEnd();
	
	}
  }
  else
  {
	  foodx+=fooddirx*8;
	foody+=fooddiry*8;
	
	if(foodx - 5 < 0 || foodx + 5 > 640 ||foody - 5 < 0 || foody + 5 > 480)
	{
		
		fooddirx=-fooddirx;
		fooddiry=-fooddiry;
	}
	glBegin(GL_QUADS);
		glColor3f(1, 1, 0);
		glVertex2f (foodx - 5, foody - 5);
		glVertex2f (foodx - 5, foody + 5);
		glVertex2f (foodx + 5, foody + 5);
		glVertex2f (foodx + 5, foody - 5);
	glEnd();
  }
}

void drawsnake()
{

	if(screen==1)
	{
	//move the snake
	for(int j = snakesize - 1; j > 0; j--)
	{
		snakepositionsx[j] = snakepositionsx[j - 1];
		snakepositionsy[j] = snakepositionsy[j - 1];
	}
	
	//new position for the snake head
	snakepositionsx[0] = snakepositionsx[0] + snakedirx * 10;
	snakepositionsy[0] = snakepositionsy[0] + snakediry * 10;

	//Draw the snake except the head in green
	for(int j = 1; j < snakesize; j++)
	{
		glBegin(GL_QUADS);
			glColor3f(0, 1, 0);
			glVertex2f (snakepositionsx[j] - 5, snakepositionsy[j] - 5);
			glVertex2f (snakepositionsx[j] - 5, snakepositionsy[j] + 5);
			glVertex2f (snakepositionsx[j] + 5, snakepositionsy[j] + 5);
			glVertex2f (snakepositionsx[j] + 5, snakepositionsy[j] - 5);
		glEnd();

		glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex2f (snakepositionsx[j] - 5, snakepositionsy[j] - 5);
			glVertex2f (snakepositionsx[j] - 5, snakepositionsy[j] + 5);
			glVertex2f (snakepositionsx[j] + 5, snakepositionsy[j] + 5);
			glVertex2f (snakepositionsx[j] + 5, snakepositionsy[j] - 5);
		glEnd();
	}

	//now draw the head in red
	glBegin(GL_QUADS);
			glColor3f(1, 0, 0);
			glVertex2f (snakepositionsx[0] - 5, snakepositionsy[0] - 5);
			glVertex2f (snakepositionsx[0] - 5, snakepositionsy[0] + 5);
			glVertex2f (snakepositionsx[0] + 5, snakepositionsy[0] + 5);
			glVertex2f (snakepositionsx[0] + 5, snakepositionsy[0] - 5);
	glEnd();


	//check if the snake hit the wall
	if(snakepositionsx[0] - 5 < 0 || snakepositionsx[0] + 5 > 640 || snakepositionsy[0] - 5 < 0 || snakepositionsy[0] + 5 > 480)
	{		
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if(level==2)
	{
		
	if((snakepositionsx[0]+5>=100)&&(snakepositionsx[0]+5<=130)&&(snakedirx==1)&&(snakepositionsy[0]<=130&&snakepositionsy[0]>=100))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		
		gameover = true;
	}
	if((snakepositionsx[0]+5>=470)&&(snakepositionsx[0]+5<=500)&&(snakedirx==1)&&(snakepositionsy[0]<=130&&snakepositionsy[0]>=100))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsx[0]+5>=270)&&(snakepositionsx[0]+5<=300)&&(snakedirx==1)&&(snakepositionsy[0]<=230&&snakepositionsy[0]>=200))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsx[0]+5>=100)&&(snakepositionsx[0]+5<=130)&&(snakedirx==1)&&(snakepositionsy[0]<=330&&snakepositionsy[0]>=300))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsx[0]+5>=470)&&(snakepositionsx[0]+5<=500)&&(snakedirx==1)&&(snakepositionsy[0]<=330&&snakepositionsy[0]>=300))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}

	if((snakepositionsx[0]-5<=130)&&(snakepositionsx[0]-5>=100)&&(snakedirx==-1)&&(snakepositionsy[0]<=130&&snakepositionsy[0]>=100))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsx[0]-5<=500)&&(snakepositionsx[0]-5>=470)&&(snakedirx==-1)&&(snakepositionsy[0]<=130&&snakepositionsy[0]>=100))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsx[0]-5<=300)&&(snakepositionsx[0]-5>=270)&&(snakedirx==-1)&&(snakepositionsy[0]<=230&&snakepositionsy[0]>=200))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsx[0]-5<=130)&&(snakepositionsx[0]-5>=100)&&(snakedirx==-1)&&(snakepositionsy[0]<=330&&snakepositionsy[0]>=300))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsx[0]-5<=500)&&(snakepositionsx[0]-5>=470)&&(snakedirx==-1)&&(snakepositionsy[0]<=330&&snakepositionsy[0]>=300))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsy[0]+5>=100)&&(snakepositionsy[0]+5<=130)&&(snakediry==1)&&(snakepositionsx[0]<=130&&snakepositionsx[0]>=100))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsy[0]+5>=100)&&(snakepositionsy[0]+5<=130)&&(snakediry==1)&&(snakepositionsx[0]<=500&&snakepositionsx[0]>=470))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsy[0]+5>=200)&&(snakepositionsy[0]+5<=230)&&(snakediry==1)&&(snakepositionsx[0]<=300&&snakepositionsx[0]>=270))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsy[0]+5>=300)&&(snakepositionsy[0]+5<=330)&&(snakediry==1)&&(snakepositionsx[0]<=130&&snakepositionsx[0]>=100))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsy[0]+5>=300)&&(snakepositionsy[0]+5<=330)&&(snakediry==1)&&(snakepositionsx[0]<=500&&snakepositionsx[0]>=470))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsy[0]-5>=100)&&(snakepositionsy[0]-5<=130)&&(snakediry==-1)&&(snakepositionsx[0]<=130&&snakepositionsx[0]>=100))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsy[0]-5>=100)&&(snakepositionsy[0]-5<=130)&&(snakediry==-1)&&(snakepositionsx[0]<=500&&snakepositionsx[0]>=470))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsy[0]-5>=200)&&(snakepositionsy[0]-5<=230)&&(snakediry==-1)&&(snakepositionsx[0]<=300&&snakepositionsx[0]>=270))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsy[0]-5>=300)&&(snakepositionsy[0]-5<=330)&&(snakediry==-1)&&(snakepositionsx[0]<=130&&snakepositionsx[0]>=100))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	if((snakepositionsy[0]-5>=300)&&(snakepositionsy[0]-5<=330)&&(snakediry==-1)&&(snakepositionsx[0]<=500&&snakepositionsx[0]>=470))
	{
		glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
	}
	//check if the snake hit itself
	for(int j = 1; j < snakesize; j++)
	{
		if(snakepositionsx[0] + 5 > snakepositionsx[j] - 5 && snakepositionsx[0] - 5 < snakepositionsx[j] + 5 && snakepositionsy[0] - 5 < snakepositionsy[j] + 5 && snakepositionsy[0] + 5 > snakepositionsy[j] - 5)
		{
			glColor3f(1, 0, 0);
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", 290, 420);
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to play Again? Press Y", 210, 440);
		
		gameover = true;
		}
	}
	}
	//check if the snake ate the food
	if(snakepositionsx[0] + 5 > foodx - 5 && snakepositionsx[0] - 5 < foodx + 5 && snakepositionsy[0] - 5 < foody + 5 && snakepositionsy[0] + 5 > foody - 5)
	{
		score = score + 50; //increment score by 50
		snakesize = snakesize + 1;
		foodx = (rand() % 630) + 5;
		foody = (rand() % 470) + 5;
		if(fooddirx==0){fooddirx=1;}
		else
			fooddirx=0;
		if(fooddiry==0){fooddiry=1;}
		else
			fooddiry=0;
	}	

  }

  else
  {

	  for(int j = snakesize - 1; j > 0; j--)
	{
		snakepositionsx[j] = snakepositionsx[j - 1];
		snakepositionsy[j] = snakepositionsy[j - 1];
	}
	
	//new position for the snake head
	snakepositionsx[0] = snakepositionsx[0] + snakedirx * 10;
	snakepositionsy[0] = snakepositionsy[0] + snakediry * 10;

	//Draw the snake except the head in green
	for(int j = 1; j < snakesize; j++)
	{
		glBegin(GL_QUADS);
			glColor3f(0, 1, 0);
			glVertex2f (snakepositionsx[j] - 5, snakepositionsy[j] - 5);
			glVertex2f (snakepositionsx[j] - 5, snakepositionsy[j] + 5);
			glVertex2f (snakepositionsx[j] + 5, snakepositionsy[j] + 5);
			glVertex2f (snakepositionsx[j] + 5, snakepositionsy[j] - 5);
		glEnd();

		glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0);
			glVertex2f (snakepositionsx[j] - 5, snakepositionsy[j] - 5);
			glVertex2f (snakepositionsx[j] - 5, snakepositionsy[j] + 5);
			glVertex2f (snakepositionsx[j] + 5, snakepositionsy[j] + 5);
			glVertex2f (snakepositionsx[j] + 5, snakepositionsy[j] - 5);
		glEnd();
	}

	//now draw the head in red
	glBegin(GL_QUADS);
			glColor3f(1, 0, 0);
			glVertex2f (snakepositionsx[0] - 5, snakepositionsy[0] - 5);
			glVertex2f (snakepositionsx[0] - 5, snakepositionsy[0] + 5);
			glVertex2f (snakepositionsx[0] + 5, snakepositionsy[0] + 5);
			glVertex2f (snakepositionsx[0] + 5, snakepositionsy[0] - 5);
	glEnd();

	if(snakepositionsx[0] - 10 <=30 )
	{		
		
		snakedirx=0;
		snakediry=-1;
		
		
	}
	if( snakepositionsx[0] + 20 > 640 )
	{
		snakediry=1;
		snakedirx=0;
	}
	if(snakepositionsy[0]-20<0)
	{
		snakedirx=1;
		snakediry=0;

	}
	if(snakepositionsy[0] + 80 > 480)
	{
		snakedirx=-1;
		snakediry=0;
	}

	if(snakepositionsx[0] + 5 > foodx - 5 && snakepositionsx[0] - 5 < foodx + 5 && snakepositionsy[0] - 5 < foody + 5 && snakepositionsy[0] + 5 > foody - 5)
	{
		//score = score + 50; increment score by 50
		snakesize = snakesize + 1;
		foodx = (rand() % 630) + 5;
		foody = (rand() % 470) + 5;
		if(fooddirx==0){fooddirx=1;}
		else
			fooddirx=0;
		if(fooddiry==0){fooddiry=1;}
		else
			fooddiry=0;
	}	

  }

}


void drawobstacle()
{
	glBegin(GL_QUAD_STRIP);
		glVertex2f(100,130);
		glVertex2f(130,130);
		glVertex2f(100,100);
		glVertex2f(130,100);
	glEnd();


	glBegin(GL_QUAD_STRIP);
		glVertex2f(470,130);
		glVertex2f(500,130);
		glVertex2f(470,100);
		glVertex2f(500,100);
	glEnd();


	glBegin(GL_QUAD_STRIP);
		glVertex2f(100,330);
		glVertex2f(130,330);
		glVertex2f(100,300);
		glVertex2f(130,300);
	glEnd();


	glBegin(GL_QUAD_STRIP);
		glVertex2f(470,330);
		glVertex2f(500,330);
		glVertex2f(470,300);
		glVertex2f(500,300);
	glEnd();

	glBegin(GL_QUAD_STRIP);
		glVertex2f(270,230);
		glVertex2f(300,230);
		glVertex2f(270,200);
		glVertex2f(300,200);
	glEnd();
}

void display()
{

	cout<<flag<<" "<<screen<<endl;
	
	if(gameover == false&&flag==2)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0, 0, 0, 1);
		if(level==2)
		{
			
		drawobstacle();
		}
		drawFood();
		drawsnake();
		
		glColor3f(1, 1, 1);

		drawString(GLUT_BITMAP_HELVETICA_18, "Score:", 10, 20);
		itoa(score, buffer, 10);
		drawString(GLUT_BITMAP_HELVETICA_18, buffer, 70, 20);
		
		if(score > highscore)
			highscore = score;

		drawString(GLUT_BITMAP_HELVETICA_18, "High score:", 420, 20);
		itoa(highscore, buffer, 10);
		drawString(GLUT_BITMAP_HELVETICA_18, buffer, 520, 20);
		

		glutSwapBuffers();
		Sleep(100);
	}
}

void cov()
{
	
	cout<<flag<<" "<<screen<<endl;
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	
	glOrtho(0,0,0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	
		
	drawFood();
	drawsnake();
	glColor3f(0, 1, 0);
	drawString(GLUT_BITMAP_TIMES_ROMAN_24, "MENU:", 250, 175);
	glColor3f(1,0,0.3);
	drawString(GLUT_BITMAP_HELVETICA_18, "1. Play", 250, 200);
	glColor3f(0.4,0,0.6);
	drawString(GLUT_BITMAP_HELVETICA_18,"2. Controls",250,225);
	glColor3f(0.7,0.8,0);
	drawString(GLUT_BITMAP_HELVETICA_18,"3. Exit",250,250);
	
	glFlush();
	glutSwapBuffers();
	Sleep(100);
}
void rules()
{
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	
	glOrtho(0,0,0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	

	glColor3f(0,0.5,0.9);
	drawString(GLUT_BITMAP_HELVETICA_18, "W : Move Up", 250, 175);
	glColor3f(1,0,0.3);
	drawString(GLUT_BITMAP_HELVETICA_18, "A: Move Left", 250, 200);
	glColor3f(0.4,0,0.6);
	drawString(GLUT_BITMAP_HELVETICA_18,"S: Move Down",250,225);
	glColor3f(0.7,0.8,0);
	drawString(GLUT_BITMAP_HELVETICA_18,"D: Move Right",250,250);

	glColor3f(1,0,0);
	drawString(GLUT_BITMAP_HELVETICA_18, "Press 0 to move to the previous screen!", 300, 400);

	glFlush();
	glutSwapBuffers();
	Sleep(100);
}
void menu()
{
	if(screen==0)
		{
			cov();

			}
	else if(screen==1)
	{
		
		display();
	}
	else if(screen==2)
	{
		rules();
	}
}


void reshape(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 640, 480, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);

}


void keypress(unsigned char key, int x, int y ){
    switch(key){
		if(screen==0)
		{
			case '1':
			{
			
			flag=2;
			screen=1;
			
			break;
			}
			case '2':
				{
					screen=2;
					break;
				}
			case '3':
				exit(0);
		}
		else if(screen==1)
		{
			
	case 'w':
	 if(snakediry != 1)
	 {
		snakedirx = 0;
		snakediry = -1;
	 }
	break;
	case 'a':
		if(snakedirx != 1)
		{
		snakedirx = -1;
		snakediry = 0;
		}
		break;
	case 's':
		if(snakediry != -1)
		{
		snakedirx = 0;
		snakediry = 1;
		}
		break;
	case 'd':
		if(snakedirx != -1)
		{
		 snakedirx = 1;
		 snakediry = 0;
		}
		break;
	case 'y':
		if(gameover == true)
		{
			gameover = false;
			initgame();
		}
		break;
	case 'n':
		if(gameover == true)
			exit(0);
		break;
	case 'c':
		break;
	
	case 27:exit(0);
		}
	else if(screen==2)
	{
	case '0':
		{
			screen=0;
			break;
		}
		}}
}
	
void main(int argc, char **argv)
{
	initgame();
	glutInit(&argc,argv);
	//glClearColor(0,0,0,1);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("snake");
	glutReshapeFunc(reshape);
	glutDisplayFunc(menu);
	glutKeyboardFunc(keypress);
	glutIdleFunc(menu);
    glutMainLoop();
}
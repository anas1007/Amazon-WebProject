#include<GL/gl.h>
#include<GL/glut.h>
#include<ctime>
#include "game.h"

int GridX,GridY;
int SnakeLength=5;
bool Frog=true;
int FrogX,FrogY;
short SnakeMovement = RIGHTkey;

extern int Score;
extern bool GameOver;

int PositionX[60]={20,20,20,20,20};
int PositionY[60]={20,19,18,17,16};

void Grid(int x,int y){
    GridX=x;
    GridY=y;
}

void unit(int,int);

void DrawGrid(){
  for(int x=0;x<GridX;x++){
    for(int y=0;y<GridY;y++){
        unit(x,y);
    }
  }
}


void unit(int x,int y){
if(x==0 || y==0 || x==GridX-1 || y==GridY-1){
    glLineWidth(5.0);
    glColor3f(1.0,0.0,0.0);
}
else{
    glLineWidth(1.0);
    glColor3f(1.0,1.0,1.0);
}
glBegin(GL_LINE_LOOP);
glVertex2f(x,y);
glVertex2f(x+1,y);
glVertex2f(x+1,y+1);
glVertex2f(x,y+1);
glEnd();
}


void DrawFrog(){
if(Frog){
    RandomValue(FrogX,FrogY);
}
Frog=false;
glColor3f(0.0,1.0,0.0);
glRectf(FrogX,FrogY,FrogX+1,FrogY+1);
}


void DrawSnake(){
for(int i=SnakeLength;i>0;i--){
    PositionX[i]=PositionX[i-1];
    PositionY[i]=PositionY[i-1];
}
if(SnakeMovement==UPkey){
    PositionY[0]++;
}
else if(SnakeMovement==DOWNkey){
    PositionY[0]--;
}
else if(SnakeMovement==RIGHTkey){
    PositionX[0]++;
}
else if(SnakeMovement==LEFTkey){
    PositionX[0]--;
}
for(int i=0;i<SnakeLength;i++){
    glRectd(PositionX[i],PositionY[i],PositionX[i]+1,PositionY[i]+1);
}
if(PositionX[0]==0 || PositionX[0]==GridX-1 || PositionY[0]==0 || PositionY[0]==GridY-1){
     GameOver=true;
}
if(PositionX[0]==FrogX && PositionY[0]==FrogY){
    Score++;
    SnakeLength++;
    if(SnakeLength>MAX){
        SnakeLength=MAX;
    }
    Frog=true;
}
}


void RandomValue(int &x,int &y){
int MAXIMUMX=GridX-2;
int MAXIMUMY=GridY-2;
int MINIMUM=1;
srand(time(NULL));
x=MINIMUM + rand() % (MAXIMUMX-MINIMUM);
y=MINIMUM + rand() % (MAXIMUMY-MINIMUM);
}

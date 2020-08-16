#include<GL/gl.h>
#include<GL/glut.h>
#include "game.h"
#include<stdlib.h>
#define COLUMNS 40
#define ROWS 40
#define Speed 8

extern short SnakeMovement;
bool GameOver=false;
int Score=0;

void init(){
glClearColor(0.0,0.0,0.0,1.0);
Grid(COLUMNS,ROWS);
}

int i=0;
void display(){
glClear(GL_COLOR_BUFFER_BIT);
DrawGrid();
DrawSnake();
DrawFrog();
glutSwapBuffers();
if(GameOver){
    char ScoreGame[10];
    itoa(Score,ScoreGame,10);
    char text[30]="Your Score is: ";
    strcat(text,ScoreGame);
    MessageBox(NULL,text,"Game Over",0);
    exit(0);
}
}


void Reshape(int weight, int height){
glViewport(0,0,weight,height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
glMatrixMode(GL_MODELVIEW);
}


void keyboard(int key,int,int){

 switch(key){

 case GLUT_KEY_UP:
     if(SnakeMovement!=DOWNkey){
         SnakeMovement=UPkey;
     }
     break;

 case GLUT_KEY_DOWN:
     if(SnakeMovement!=UPkey){
        SnakeMovement=DOWNkey;
     }
     break;

 case GLUT_KEY_RIGHT:
     if(SnakeMovement!=LEFTkey){
        SnakeMovement=RIGHTkey;
     }
     break;

 case GLUT_KEY_LEFT:
     if(SnakeMovement!=RIGHTkey){
        SnakeMovement=LEFTkey;
     }
     break;
 }


}



void timer(int){
 glutPostRedisplay();
 glutTimerFunc(1000/Speed,timer,0);
}


int main(int argc,char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB);
glutInitWindowSize(500,500);
glutCreateWindow("Snake Game");
glutDisplayFunc(display);
glutReshapeFunc(Reshape);
glutTimerFunc(0,timer,0);
glutSpecialFunc(keyboard);
init();
glutMainLoop();
return 0;
}

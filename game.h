#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#define UPkey 1
#define DOWNkey -1
#define RIGHTkey 2
#define LEFTkey -2
#define MAX 60

void Grid(int,int);
void DrawGrid();
void DrawSnake();
void DrawFrog();
void RandomValue(int&,int&);

#endif // GAME_H_INCLUDED

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void draw();
void move(int x,int y);
int person_x = 0,person_y = 4;
int box_x = 1,box_y = 4;

char map[10][10]={
    {'*','*','*','*','P','*','*','*','*','*'},
    {'*','*','*',' ','B',' ','*','*','*','*'},
    {'*','*',' ',' ',' ',' ','*','*','*','*'},
    {'*','*',' ',' ','*','*','*','*','*','*'},
    {'*','*',' ',' ','*','*','*','*','*','*'},
    {'*','*',' ',' ',' ','E','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*','*','*'},
    };

int main()
{
    char control;
    draw();
    while(control = _getch())
    {
        switch(control)
        {
            case 'w':
                move(-1,0);
                break;
            case 'a':
                move(0,-1);
                break;
            case 'd':
                move(0,1);
                break;
            case 's':
                move(1,0);
                break;
            case 'q':
                printf("quit\n");
                return 0;
                break;
            default:
                draw();
        }
    }
    return 0;
}

void move(int x,int y){
    char person,box;
    person = map[person_x+x][person_y+y];
    box = map[box_x+x][box_y+y];
    switch(person)
    {
    case ' ':
        map[person_x+x][person_y+y] = 'P';
        map[person_x][person_y] = ' ';
        person_x += x;
        person_y += y;
        draw();
        break;
    case 'B':
        switch(box)
        {
        case ' ':
            map[person_x+x][person_y+y] = 'P';
            map[person_x][person_y] = ' ';
            map[box_x+x][box_y+y] = 'B';
            person_x += x;
            person_y += y;
            box_x += x;
            box_y += y;
            draw();
            break;
        case 'E':
            map[person_x+x][person_y+y] = 'P';
            map[person_x][person_y] = ' ';
            map[box_x+x][box_y+y] = 'B';
            person_x += x;
            person_y += y;
            draw();
            printf("Win!!!");
            break;
        }
//        map[person_x+x][person_y+y] = 'P';
//        map[person_x][person_y] = ' ';
//        draw();
//        printf("Win!!!\n");
        break;
    }
}

void draw()
{
    system("cls");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char gameboard[3][3];
void drawboard();
int showresult(char ch);
int validateinput(int cell);
void trunplayer0(int* pcell);
void trunplayerx(int* pcell);
void getrowcol(int cell,int* px,int* py);

int main()
{
    int x =0,
    y = 0,
    row = 0,
    col = 0,
    selectedcell=0,
    availablecell = 9;

    char startchar = '1';

    for(row=0;row<3;row++)
       for(col=0;col<3;col++)
        gameboard[row][col] = startchar++;


    drawboard();

    while(availablecell>=0)
    {
        trunplayerx(&selectedcell);
        getrowcol(selectedcell,&x,&y);
        gameboard[x][y]='x';
        availablecell -= 1;

    drawboard();

    if(showresult('x') == 1)
    {
        break;
    }

    else if(availablecell==0)
    {
        printf("\n Game drawn");
        break;
    }

    trunplayer0(&selectedcell);
    getrowcol(selectedcell,&x,&y);
     gameboard[x][y]='0';
      availablecell -=1;
     drawboard();
    if(showresult('0') == 1)
    {
        break;
    }

    else if(availablecell==0)
    {
        printf("\n Game drawn");
        break;
    }

    }

    getch();
    return 0;
}

void drawboard()
{
    int i,j;
    printf("\n\t\t TIC TOC TOE");

    printf("\n\n Digits (1-9) indicates valid cell no\n");

    printf("\n    %c | %c | %c",gameboard[0][0],gameboard[0][1],gameboard[0][2]);

    printf("\n   ---|---|---");
    printf("\n    %c | %c | %c",gameboard[1][0],gameboard[1][1],gameboard[1][2]);

    printf("\n   ---|---|---");
    printf("\n    %c | %c | %c",gameboard[2][0],gameboard[2][1],gameboard[2][2]);
}

void trunplayer0(int* pcell)
{
    int cell;
    do
    {
        printf("\n\n Player 0\n\n Select valid cell number: ");
        scanf("%d",&cell);
    }while( 0 == validateinput(cell));

    *pcell = cell;
}

void trunplayerx(int* pcell)
{
    int cell;
    do
    {
        printf("\n\n Player x\n\n selected valid cell number: ");
        scanf("%d",&cell);
    }while( 0 == validateinput(cell) );
    *pcell = cell;
}

void getrowcol(int cell,int* px,int* py)
{
    *px=(cell-1)/3;
    *py=(cell-1)%3;
}

int validateinput(int cell)
{
    int row,col;
    if((cell<1) || (cell>9))
        return 0;

    getrowcol(cell,&row,&col);

    if(('0' == gameboard[row][col]) || ('x' == gameboard[row][col]))
    {
        return 0;
    }

    return 1;

}

int showresult(char ch)
{
    int status = 0;

    if(gameboard[0][0] == ch && gameboard[1][1] == ch &&gameboard[2][2] == ch )
    {
        printf("\n\n player %c is win\n",ch);
        status = 1;
    }

    else if(gameboard[0][2] == ch && gameboard[1][1] == ch &&gameboard[2][0] == ch )
    {
        printf("\n\n player %c is win\n",ch);
        status = 1;
    }


    else if(gameboard[0][0] == ch && gameboard[1][0] == ch &&gameboard[2][0] == ch )
    {
        printf("\n\n player %c is win\n",ch);
        status = 1;
    }

    else if(gameboard[1][0] == ch && gameboard[1][1] == ch &&gameboard[1][2] == ch )
    {
        printf("\n\n player %c is win",ch);
        status = 1;
    }

    else if(gameboard[2][0] == ch && gameboard[2][1] == ch &&gameboard[2][2] == ch )
    {
        printf("\n\n player %c is win\n",ch);
        status = 1;
    }

    else if(gameboard[0][0] == ch && gameboard[0][1] == ch &&gameboard[0][2] == ch )
    {
        printf("\n\n player %c is win\n",ch);
        status = 1;
    }

    else if(gameboard[0][1] == ch && gameboard[1][1] == ch &&gameboard[2][1] == ch )
    {
        printf("\n\n player %c is win\n",ch);
        status = 1;
    }

    else if(gameboard[0][2] == ch && gameboard[1][2] == ch &&gameboard[2][2] == ch )
    {
        printf("\n\n player %c is win\n",ch);
        status = 1;
    }

    return status;
}

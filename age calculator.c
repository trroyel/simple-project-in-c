                                               ///AGE CALCULATOR
                                        /// created. 2 - february - 2014



#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <windows.h>

int gotoxy(int x, int y);
int table_draw(void);
int clear_screen(void);

COORD coord = {0,0};

int main()
{

    time_t time_val;
    struct tm *tp;

    int bir_d ,bir_m ,bir_y ,cur_wday,age_d,age_m,age_y,x = 7;
    char ch;

    char *month[] = {"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY",
                    "AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};


    char *day[] = {"SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATARDAY"};

    time_val = time(NULL);
    tp = localtime(&time_val);

    SetConsoleTitle("royel, t.r.royel@gmail.com ");

    table_draw();

    gotoxy(32,3);
    printf("AGE CALCULATOR");

    gotoxy(30,4);
    printf("CALCULATE YOUR AGE.");

    gotoxy(x,8);
    printf("ENTER BIRTHDAY(D-M-Y)");

    gotoxy(x,11);
    printf("YOUR BIRTH DATE:");

    gotoxy(x,14);
    printf("CURRENT DATE IS:");

    gotoxy(x,17);
    printf("NOW YOUR AGE IS:");

    while(ch != 'N' && ch != 'n')
    {

         clear_screen();

         gotoxy(31,8);
         scanf("%d %d %d",&bir_d,&bir_m,&bir_y);

         if(bir_d > tp->tm_mday)
         {
             if(bir_m > (tp->tm_mon + 1))
             {
                 age_d = (tp->tm_mday + 31) - bir_d;
                 age_m = ((tp->tm_mon + 1) + 12) - (bir_m+1);
                 age_y = (tp->tm_year +1900) - (bir_y+1);
             }

             else
             {
                 age_d = (tp->tm_mday + 31) - bir_d;
                 age_m = ((tp->tm_mon + 1) - 1) - bir_m;
                 age_y = (tp->tm_year + 1900)- bir_y;
             }
         }


         else
         {
             if(bir_m >(tp->tm_mon + 1))
             {
                 age_d = tp->tm_mday - bir_d;
                 age_m = ((tp->tm_mon + 1) + 12) - bir_m;
                 age_y = (tp->tm_year + 1900) - (bir_y+1);
             }

             else
             {
                 age_d = tp->tm_mday - bir_d;
                 age_m = (tp->tm_mon + 1) - bir_m;
                 age_y = (tp->tm_year + 1900) - bir_y;
             }
         }

         gotoxy(31,11);
         printf("%d %s %d",bir_d,month[bir_m - 1],bir_y);

         gotoxy(31,14);
         printf("%s, %d %s %d",day[tp->tm_wday],tp->tm_mday,month[tp->tm_mon],tp->tm_year +1900);

         gotoxy(31,17);
         printf("%d YEAR, %d MONTH, %d DAY",age_y,age_m,age_d);

         gotoxy(31,20);
         printf("EXIT(N): ");
         ch = getch();

    }

    return 0;

}


int gotoxy(int x, int y)
{
    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    return 0;
}


int table_draw(void)
{
    int i,j;

    gotoxy(2,2);

    printf("%c",201);

    for(i = 3; i < 76; i++)
    {
        gotoxy(i,2);

        printf("%c",205);
    }

    gotoxy(76,2);

    printf("%c",187);

    for(i = 3; i < 22; i++)
    {
        gotoxy(76,i);

        if(i==5)
            printf("%c",185);

        else
            printf("%c",186);

    }

    gotoxy(76, 22);
    printf("%c",188);

    for(i = 75; i > 2; i--)
    {
        gotoxy(i,22);

        if(i == 29)
            printf("%c",202);

        else
            printf("%c",205);

    }

    gotoxy(2, 22);
    printf("%c",200);

    for(i = 21; i > 2; i--)
    {
        gotoxy(2,i);

        if(i==5)
            printf("%c",204);

        else
            printf("%c",186);

    }

    for(i = 3; i < 76; i++)
    {
        gotoxy(i,5);

        if(i == 29)
            printf("%c",203);

        else
            printf("%c",205);
    }

    for(i = 6; i < 22; i++)
    {
        gotoxy(29,i);
        printf("%c",186);
    }

    return 0;
}


int clear_screen(void)
{
    int i,j;

    for(i = 30; i < 65; i++)
    {
        for(j = 7; j < 21; j++)
        {
            gotoxy(i,j);
            printf(" ");
        }
    }

    return 0;
}


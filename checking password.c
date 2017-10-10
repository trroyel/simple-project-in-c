
                                                  /*SECURITY CHEAK
                                            MY FIRST ASSAIGNMENT PROJECT */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>
int cheak_pass(char* pass_);
int change_pass();
int encrypt_password(char* pass);
int set_pass();
int user_doc();
int show_data();
int menu();
int reset_data(void);

int main()
{

    FILE* pass_file;
    if( (pass_file = fopen("pass.txt", "r")) == NULL)
         printf("\n\t\t FILE \"pass.txt\" NOT FOUND\n");

    int i = 1,result = -1,d = -1;
    char ch ;
    char* str = (char*) malloc (sizeof(char));

    *str = EOF;

    fgets(str,15,pass_file);


    fflush(stdin);

    printf("\n\t\t\t    |-*-*-*-*-*-*-*-*-|");
    printf("\n\t\t\t    | SECURITY CHEAK  |");
    printf("\n\t\t\t    |-*-*-*-*-*-*-*-*-|");

    user_doc();

    if(*str == EOF )
    {

        set_pass();
        return main();

    }

    encrypt_password(str);

     //puts(str);

    result = cheak_pass(str);


     if(result == 0)
     {
         printf("\n\n \t\t WHO R U?? U HAVE NOT RIGHT TO ENTER THIS ROOM.\n");
         //play an alarm
         //put the file location of the audio file
         system ("%WINDIR%\\Media\\Alarm01.wav");
         //
         printf("\a\a\a\a\a\a\a\a\a\a\a\a\a");
     }

     else
     {

         printf("\n\n\t\t\t           WELCOME     ");
         printf("\n\n\t\t\t      YOU ARE PERMITTED.\n\n");
        while(d!=0)
        {
             menu();

             printf("\n\n\t\t\t      SELECT YOUR CHOICE:  ");
             fflush(stdin);
             ch = getch();

             printf("\n\n");

             switch(ch)
             {
             case '1':
                change_pass();
                break;

             case '2':
                show_data();
                break;

            case '3':
                reset_data();
                break;

             case '0':
                 printf("\n\n\t\t\t    THANKS !!!TERMINATING....\n\n");
                 exit(0);


             default:
                 printf("\n\n\t\t\t   YOU PRESS WRONG KEY!!!!!! ");
                 break;

             }
        }

     }

     getch();

     return 0;

}


int change_pass()
{
    FILE *pass_cnge;

    int i;
    char new_pass[15],con_pass[15];

    while(1)
    {

        printf("\n\t\t\t   ENTER NEW PASSWORD: ");
        gets(new_pass);

        printf("\n\t\t\t   CONFIRM NEW PASSWORD: ");
        gets(con_pass);

        if(strcmp(new_pass,con_pass)==0)
        {
            encrypt_password(con_pass);

            pass_cnge = fopen("pass.txt","w+");

            fputs(con_pass,pass_cnge);

            fclose(pass_cnge);

            printf("\n\n\t\t       YOUR PASSWORD IS SUCCESSFULLY CHANGED.\n");

            return 0;

        }

        else
        {
            if(i>2)
            {
                 printf("\n\t\t\t\tTIME OUT!!!\n");
                 return 0;
            }


            else
            {
                printf("\n\t\t\tPASSWORD DONT MATCH.");
                i++;
            }
        }
    }


    return 0;

}

int cheak_pass(char* pass_)
{
    int i = 0;
    char* new_pass = (char*) malloc (sizeof(char));

    while(i<=3)
    {
        printf("\n\t\t\t   ENTER YOUR PASSWORD: \a");
        //disable console input display
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
       //
        gets(new_pass);

        if(strcmp(new_pass,pass_)==0)
            return 1;

        else
        {
            if(i>2)
                return 0;

            else
            {
                 printf("\n\n\t\t   SORRY,WRONG PASSWORD!!! TRY AGAIN PLEASE..\n\n ");
                 i++;
            }

        }
    }

}

int user_doc()
{
    FILE* fp;
    time_t time_val;
    char *time_string,*name = (char*) malloc(sizeof(char));

    fp = fopen("data.txt","a+");
    time(&time_val);

    time_string= ctime(&time_val);

    printf("\n\n\t\t\t   ENTER YOUR NAME: ");
    gets(name);

    //printf("\n     %s",time_string);

    fprintf(fp, "%-10s    %-25s \n",name,time_string);

    fclose(fp);

    return 0;

}

int menu()
{
    printf("\n\n\n\t\t\t            MENU \n");
    printf("\n\t\t\t   1.CHANGE PASSWORD.");
    printf("\n\n\t\t\t   2.SHOW HISTORY.");
    printf("\n\n\t\t\t   3.RESET HISTORY.");
    printf("\n\n\t\t\t   0.EXIT.\n");

    return 0;

}


int show_data()
{
    FILE* fp;
    fp = fopen("data.txt","r");

    int i = 0;

    char  get_time[30];// = (char*) malloc(sizeof(char));
    char*  get_name = (char*) malloc(sizeof(char));

    while(fscanf(fp, "%s  %[^\n] ",get_name,&get_time)!= EOF)
    {
        printf("\n\t\t    %-10s    %-25s\n",get_name,get_time);
        i++;
    }

    if(i == 0)
        printf("\n\n\t\t\t   DATA FILE IS EMPTY!!!\n\n");

    free(get_name);
     //free(get_time);
    fclose(fp);

    return 0;

}

int encrypt_password(char* pass)
{
    while(*pass)
    {
        *pass++ ^=001;//mask value is 52;
    }

    return 0;
}


int set_pass()
{
    FILE* set_pas;
    char *pass_ =(char*) malloc(sizeof(char));

    set_pas = fopen("pass.txt","r+");

    printf("\n\t\t\t    ******************");
    printf("\n\t\t\t    |     WELCOME    |");
    printf("\n\t\t\t    ******************");


    printf("\n\n\t\t\tSET YOUR PASSWORD PLEASE:  ");
    gets(pass_);

    encrypt_password(pass_);

    fputs(pass_,set_pas);

    fflush(stdin);

    free(pass_);

    fclose(set_pas);

    printf("\n\t\t  CONGRATS!!! YOUR PASSWORD SET SUCCESSFULLY..\n\n");

    return 0;

}

int reset_data(void)
{
    FILE* fp;
    fp = fopen("data.txt","w+");

    fclose(fp);
    printf("\n\t\t  CONGRATS!!! ALL DATA SUCCESSFULLY DELETED..\n\n");

    return 0;
}




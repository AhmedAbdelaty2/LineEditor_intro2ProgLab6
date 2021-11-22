#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

void gotoxy1(int x, int y);

int main()
{
    int x=0,y=0;
    char in;
    char arr[11]={'\0'};
    int i,len;

    while(in != 13)
    {
        gotoxy1(x,y);

        in=getch();
        if(in==-32)
        {
            in=getch();

            if(in==77)
            {
                if(x>10)
                    x=0;
                else
                    x++;
            }
            else if(in==75)
            {
                if(x<1)
                    x=10;
                else
                    x--;
            }
            else if(in == 79)
                x = 10;

            else if(in == 71)
                x = 0;

            else if(in == 82)
            {
                len = strlen(arr);

                for(i=len;i>x;i--)
                {
                    arr[i]=arr[i-1];
                }
                arr[x]=' ';
                system("cls");
                printf("%s",arr);
            }

            else if(in == 83)
            {
                arr[x]=' ';
                system("cls");
                printf("%s",arr);
            }

        }

        else if(in == 8)
        {
            len = strlen(arr);

            for(i=x;i<len;i++)
            {
                arr[i-1]=arr[i];
            }
            arr[len-1]=' ';
            system("cls");

            if(x!=0)
                x--;
            printf("%s",arr);
        }

        else if(in>=32 && in<=127)
        {
            len = strlen(arr);

            for(i=len;i>x;i--)
                {
                    arr[i]=arr[i-1];
                }

            arr[x] = in;

            system("cls");
            printf("%s",arr);

            if(x==9)
                x=0;
            else
                x++;
        }

    }

    len = strlen(arr);
    gotoxy1(20,20);
    printf("%s",arr);

    return 0;
}

void gotoxy1(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

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

    while(in != 13) //Press Enter to End The Program
    {
        gotoxy1(x,y);

        in=getch();
        if(in==-32)
        {
            in=getch();

            if(in==77) //Right Arrow
            {
                if(x>10)
                    x=0;
                else
                    x++;
            }
            else if(in==75) //Left Arrow
            {
                if(x<1)
                    x=10;
                else
                    x--;
            }
            else if(in == 79) //End key
            {
                len = strlen(arr);
                x = len;
            }

            else if(in == 71) //Home key
                x = 0;

            else if(in == 82) //Insert Key
            {
                len = strlen(arr);

                if(len==10)
                    arr[len-1] = '\0';

                for(i=len;i>x;i--)
                {
                    arr[i]=arr[i-1];
                }
                arr[x]=' ';
                system("cls");
                printf("%s",arr);
                gotoxy1(x,y);
                in = getch();
                arr[x] = in;
                system("cls");
                printf("%s",arr);
            }

            else if(in == 83) //Delete Key
            {
                arr[x]=' ';
                system("cls");
                printf("%s",arr);
                gotoxy1(x,y);
                in = getch();
                arr[x] = in;
                system("cls");
                printf("%s",arr);
            }

        }

        else if(in == 8) //BackSpace Key
        {
            len = strlen(arr);

            if (x>0)
            {
                for(i=x;i<len;i++)
                {
                    arr[i-1]=arr[i];
                }

                arr[len-1]='\0';
                x--;

                system("cls");
                printf("%s",arr);
            }

        }

        else if(in>=32 && in<=127) //Normal Insert
        {
            len = strlen(arr);
            if(len==10)
                arr[len] = '\0';

            if (len < 10)
            {
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

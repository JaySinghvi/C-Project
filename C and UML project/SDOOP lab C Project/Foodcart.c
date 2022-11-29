#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include<time.h>

void readall()
{
   int sum = 0;
   int a, i = 0;
   FILE *menu;
   char c;
   printf("               ==============================          \n");
   printf("                        Food Menu   \n");
   printf("               ==============================          \n\n");
    menu = fopen("Menu.txt", "r");
    if (menu == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    int k=0;
    while((c = getc(menu))!= EOF)
    {

        if(c == '~')
        {
            i++;
            printf("\t\t%d. ", i);
            sum = 0;
            continue;
        }
        if(c == '#')//|| c=='\n')
        {

            while(k<30)
            {
                printf(" ");
                k++;
            }
            printf("\t%d", sum);
            k=0;
            continue;

        }
         if(isdigit(c))
        {
            a = c-'0';
            sum = sum*10+a;

        }
        else
        {
             printf("%c", c);
             k++;
        }


    }
    fclose(menu);
}

void readsingle(char *s,int n)
{
    int sum = 0;
   int a, i = 0;
    char c;
   for(i=0;i< strlen(s);i++)
    {
        c=s[i];
        if(c == '~')
        {
            printf("%d. ", n);
            sum = 0;
            continue;
        }
        if(c == '#')
        {

            printf("\t%d ", sum);
            break;

        }
         if(isdigit(c))
        {
            a = c-'0';
            sum = sum*10+a;
        }
        else
        {
             printf("%c", c);
        }


    }
}

void write()
{
    char s[20], pr[5];
    int p;
    char sentence[20];
    FILE * fp;
    fp = fopen("Menu.txt", "a+");

    printf("\nEnter Dish name: ");
    fflush(stdin);
    scanf("%104[^\n]",s);

    printf("\nEnter price: ");
    scanf("%d", &p);

    fputs("\n~", fp);
    fputs(s, fp);
    itoa(p, pr, 10); //Converting String to int
    fputs(pr, fp);
    fputs("#",fp);
    fclose(fp);
}





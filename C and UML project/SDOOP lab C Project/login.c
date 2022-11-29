#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include<time.h>

#import "menu.c"
#import "managermenu.c"4

char userpass[4][20]={"Manager","1","Clerk","1"};

void main()
{
  char id[20], p[20];
  int n=1;
  int choice ;
  while(choice!=2)
  {
      system("CLS");
      printf("              ==============================          \n");
      printf("          Welcome to RESTAURANT AUTOMATION SYSTEM         \n ");
      printf("             ==============================          \n");
      printf("\t\tEnter [1] -> Sign in\n");
      printf("\t\tEnter [2] -> Exit\n");
      printf("              ==============================          \n");
      time_t t;   // not a primitive datatype
      time(&t);
      printf("\t\t %s", ctime(&t));
      printf("              ==============================          \n\n");
      printf("\t      Please Enter Your Choice: ");
      scanf("%d", &choice);
      if(choice==1)
      {
        do{
             printf("\nRestaurant Username:");
             scanf("%s", &id);
             fflush(stdout); //to clear output buffer

             printf("\nPassword:");
             scanf("%s", &p);
             fflush(stdout);

             if(strcmp(id, userpass[0])==0 && strcmp(p, userpass[1])==0)
            {
               printf("\nSuccessfully Logged In\n");
               system("CLS"); //clear screen
               managermenu();
               break;
             }
             else if(strcmp(id, userpass[2])==0 && strcmp(p, userpass[3])==0)
            {
               printf("\nSuccessfully Logged In\n");
               system("CLS");
               salesmenu();
               break;
             }
             else {
               printf("\nWrong Credentials, please try again\n", 5-n);
                //getch(); //getch() method pauses the Output Console until a key is pressed.
                n++;}

             if(n>5){
              printf("\nAccess Denied\n");
              getch();
              }

           }while (n<=5);
      }
      else
      {
          printf("\n\t\t\tThank you\n");
          exit(1);
      }
    }
}




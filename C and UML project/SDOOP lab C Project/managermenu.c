#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include<time.h>

void managermenu()
{
  int choice;
  while(choice!=6)
  {
      system("CLS");
      printf("              ==============================          \n");
      printf("          Welcome Manager to RESTAURANT AUTOMATION SYSTEM         \n ");
      printf("             ==============================          \n");
      printf("\t\tEnter [1] ->View Statistics\n");
      printf("\t\tEnter [2] ->View Sales Receipt\n");
      printf("\t\tEnter [3] ->View Employee Details\n");
      printf("\t\tEnter [4] ->Manage Menu\n");
      printf("\t\tEnter [5] ->Change Password\n");
      printf("\t\tEnter [6] ->Log Out\n");
      printf("              ==============================          \n");
      time_t t;   // not a primitive datatype
      time(&t);
      printf("\t\t %s", ctime(&t));
      printf("              ==============================          \n\n");
      printf("\t      Please Enter Your Choice: ");
      scanf("%d", &choice);



     switch (choice)
        {
            case 1: {
                        system("CLS");
                        stats();
                        break;
                    }
            case 2: {
                        system("CLS");
                        salesR();
                        break;
                    }
            case 3: {
                        break;
                    }



           case 4: {
                        menu();
                        break;
                    }
            case 5: {
                        break;
                    }
            case 6: {
                       printf("Logging Out\n");
                       break;
                    }



           default:
                {
                    printf("Incorrect Input");
                }
        }
}
}



void stats()
{
    int choice;
    while(choice!=3)
    {
        system("CLS");
      printf("              ==============================          \n");
      printf("                       VIEW STATISTICS         \n ");
      printf("              ==============================          \n");
      printf("\t\tEnter [1] ->Dish Expense Report\n");
      printf("\t\tEnter [2] ->Ingredient Expense Report\n");
      printf("\t\tEnter [3] ->Exit to Manager Menu\n");
      printf("              ==============================          \n");
      time_t t;   // not a primitive datatype
      time(&t);
      printf("\t\t %s", ctime(&t));
      printf("              ==============================          \n\n");
      printf("\t      Please Enter Your Choice: ");
      scanf("%d", &choice);
      switch (choice)
        {
            case 1: {
                        system("CLS");
                        break;
                    }
            case 2: {
                        system("CLS");
                        break;
                    }



           case 3: {
                       printf("Redirecting to Manager Menu\n");
                       break;
                    }



           default:
                {
                    printf("Incorrect Input");
                }
        }
    }
}

void salesR()
{
    int choice, billID;
    while(choice!=2)
    {
        system("CLS");
      printf("              ==============================          \n");
      printf("                       SALES RECEIPT         \n ");
      printf("              ==============================          \n");
      printf("\t\tEnter [1] ->Find Receipt with Bill ID:\n");
      printf("\t\tEnter [2] ->Exit to Manager Menu\n");
      printf("              ==============================          \n");
      time_t t;   // not a primitive datatype
      time(&t);
      printf("\t\t %s", ctime(&t));
      printf("              ==============================          \n\n");
      printf("\t      Please Enter Your Choice: ");
      scanf("%d", &choice);
      switch (choice)
        {
            case 1: {
                        printf("\nEnter Bill ID: ");
                        scanf("%d",billID);
                        break;
                    }



           case 2: {
                       printf("Redirecting to Manager Menu\n");
                       break;
                    }



           default:
                {
                    printf("Incorrect Input");
                }
        }
    }
}



void menu()
{
    int choice;
  while(choice!=5)
  {
      system("CLS");
      printf("              ==============================          \n");
      printf("                       MANAGE MENU         \n ");
      printf("              ==============================          \n");
      printf("\t\tEnter [1] ->View Menu\n");
      printf("\t\tEnter [2] ->Add Dish to Menu\n");
      printf("\t\tEnter [3] ->Delete Dish from Menu\n");
      printf("\t\tEnter [4] ->Edit Menu\n");
      printf("\t\tEnter [5] ->Exit to Manager Menu\n");
      printf("              ==============================          \n");
      time_t t;   // not a primitive datatype
      time(&t);
      printf("\t\t %s", ctime(&t));
      printf("              ==============================          \n\n");
      printf("\t      Please Enter Your Choice: ");
      scanf("%d", &choice);



     switch (choice)
        {
            case 1: {
                        system("CLS");
                        stats();
                        break;
                    }
            case 2: {
                        break;
                    }



           case 3: {
                       printf("Redirecting to Manager Menu\n");
                       break;
                    }



           default:
                {
                    printf("Incorrect Input");
                }
        }
}
}

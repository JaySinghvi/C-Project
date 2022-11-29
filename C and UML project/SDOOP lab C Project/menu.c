#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include<time.h>

#import "Foodcart.c"

struct NODE
{
    char dishname[30];
    int qty;
    float price;
    float netamt;
    int itemcode;
    struct NODE *next; };
typedef struct NODE node;
node *head=NULL;

void salesmenu()
{
  int choice;
  while(choice!=5)
  {
      system("CLS");
      printf("              ==============================          \n");
      printf("          Welcome Clerk to RESTAURANT AUTOMATION SYSTEM         \n ");
      printf("             ==============================          \n");
      printf("\t\tEnter [1] ->Register Purchase\n");
      printf("\t\tEnter [2] ->Manage Ingredients Ordered\n");
      printf("\t\tEnter [3] ->Update Threshold\n");
      printf("\t\tEnter [4] ->Change Password\n");
      printf("\t\tEnter [5] ->Log Out\n");
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
                        register_purchase();
                        break;
                    }
            case 2: {
                        break;
                    }
            case 3: {
                        break;
                    }

            case 4: {

                    }
            case 5: {
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
void register_purchase()
{

    int choice;
  while(choice!=5)
  {
      system("CLS");
      readall();
      printf("\n");
      display(head);
      printf("\n\n\n");
      printf("               ==============================          \n");
      printf("                   Register Purchase         \n ");
      printf("               ==============================          \n");
      printf("\t\tEnter [1] ->New Customer\n");
      printf("\t\tEnter [2] ->Add Item to Cart\n");
      printf("\t\tEnter [3] ->Delete Item from Cart\n");
      printf("\t\tEnter [4] ->Place Order\n");
      printf("\t\tEnter [5] ->Return To Clerk Menu\n");
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
                        head->next=NULL;
                        head=NULL;
                        break;
                    }
            case 2: {
                        insertLast(&head,"Pizza", 22.0,5,3030.0,1);
                        insertLast(&head,"Pasta", 22.0,5,3030.0,2);
                        printf("\nThe List after insertlast :\n");
                        display(head);
                        getch();
                        system("CLS");
                        break;
                    }
            case 3: {
                        deletee(&head, 1);
                        display(head);
                        getch();
                        break;
                    }

            case 4: {
                        storebill();
                    }
            case 5: {
                       printf("Redirecting to Clerk Menu\n");
                       break;
                    }

            default:
                {
                    printf("Incorrect Input");
                }
        }
 }

}

void insertLast(node **head,char *dn, float p, int q, float ta, int ic)
     {
         node *temp = ( node *) malloc( sizeof(node));
        if(temp==NULL)
            {
                printf("\nMemory allocation fails");
                return;
            }

        memcpy(temp->dishname,dn, 30);
        temp->price=p;
        temp->qty=q;
        temp->netamt=ta;
        temp->itemcode=ic;
        temp->next=NULL;
        if(*head==NULL)
            {
                *head=temp;
                return;
            }
        node *cur=*head;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
         cur->next=temp;
      }



void display(node *head)
{
    if(head==NULL)
    {
        printf("\nEmpty List");
        return;
    }
    node *temp=head;
    int i=1,c=0;
    while(temp->next!=NULL)
    {
        printf("%d. %s\t %f\t %d\t %f\t %d\t\n",i,temp->dishname,temp->price,temp->qty,temp->netamt, temp->itemcode);
        temp=temp->next;
        i++;
    }
    printf("%d. %s\t %f\t %d\t %f\t %d\t\n\n",i,temp->dishname,temp->price,temp->qty,temp->netamt,temp->itemcode);
    c=0;
}

void deletee(node **head, int ele)
  {   if(*head==NULL)
      {
          printf("\nEmpty List");
          return;
      }
      node *cur,*pre;
      cur=*head;
      pre=NULL;
      while(cur->itemcode!=ele)
      {
          pre=cur;
          cur=cur->next;
      }
      if(cur==NULL)
           printf("\nElement Not Found");
      else
          {
            if(pre==NULL)// if the data is at first node
               {
                 *head=cur->next;
                 cur->next  =NULL;
                 free(cur);
               }
            else
                {
                  pre->next=cur->next;
                  cur->next=NULL;
                  free(cur);
                }
          }

  }

void storebill()
{
    char name[25];
    long long int phno;

    printf("\nEnter Customer Name: ");
    scanf("%s",name);
    printf("\n%s",name);
    printf("\nEnter Mobile Number: ");
    scanf("%lld",phno);
    //printf("\n%lld",phno);
    FILE * fp;
    fp = fopen("Receipts.txt", "a+");
    fputs("\n~", fp);
    fputs(name, fp);
    fputs("&",fp);
    fputs(phno,fp);


    if(head==NULL)
    {
        printf("\nEmpty Cart, Nothing to Store");
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        insertbillitems(temp->itemcode, temp->dishname, temp->qty, temp->price, temp->netamt);
        temp=temp->next;
    }
    insertbillitems(temp->itemcode, temp->dishname, temp->qty, temp->price, temp->netamt);

    fclose(fp);
}

void insertbillitems(int itemcode, char dishname[], int qty, float price, float total)
{
    FILE * fp;
    char p[30],t[30];
    fp = fopen("Receipts.txt", "a+");
    fputs("^",fp);
    fputs(itemcode,fp);
    fputs("%",fp);
    fputs(dishname,fp);
    fputs("*",fp);
    fputs(qty,fp);
    fputs("-",fp);
    sprintf(p, "%g", price);
    fputs("&",fp);
    sprintf(t, "%g", total);
    fputs("#",fp);
    fclose(fp);
}


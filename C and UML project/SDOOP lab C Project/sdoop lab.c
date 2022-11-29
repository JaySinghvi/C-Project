#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>

int main()
{
    char id[20], p[20];
    int n=1, x1, y1, x2, y2;
    printf("\nWELCOME TO THE RESTAURANT AUTOMATION SYSTEM\n");
    do{
         printf("\nRestaurant Username:");
         scanf("%s", &id);
         fflush(stdout); //to clear output buffer

         printf("\nPassword:");
         scanf("%s", &p);
         fflush(stdout);

         x1=strcmp(id, "Clerk");
         x2=strcmp(id, "Manager");
         y2=strcmp(p, "12345");
         y1=strcmp(p, "123");

         if(x1==0 && y1==0){
           printf("\nSuccessfully Logged In\n");
           system("CLS"); //clear screen
            salesmenu();
           break;
         }
         else if(x2==0 && y2==0){
           printf("\nSuccessfully Logged In\n");
           system("CLS");
            managermenu();
           break;
         }
         else {
           printf("\nWrong Credentials, please try again\n", 5-n);
            getch(); //getch() method pauses the Output Console until a key is pressed.
            n++;}

         if(n>5){
          printf("\nAccess Denied\n");
          getch();
          }

       }while (n<=5);

}

void managermenu()
{
    printf("Welcome Manager\n");

    printf("1. Manage menu\n");
    printf("2. \n");
    printf("3. Update Threshold\n");
    printf("4. Change Password\n");
    printf("5. Log Out\n");
}

void salesmenu()
{
    int ch=0;
    do
    {
        printf("Welcome Clerk\n");
        printf("1. Register Purchase\n");
        printf("2. Manage Ingredients Ordered\n");
        printf("3. Update Threshold\n");
        printf("4. Change Password\n");
        printf("5. Log Out\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: {
                    system("CLS");
                     register_purchase();
                    ch=4;
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
    }while(ch!=5);
}

void register_purchase()
{
    int choice = 0;
    do
    {
        printf("Select your choice:\n\n");
        printf("1. Add new item\n");
        printf("2. Display Menu\n");
        printf("3. Delete a item\n");
        printf("4. Generate bill\n");
        printf("\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

    switch(choice)
    {
        case 1: {
                   system("CLS");
                   additem();
                   choice=4;
                   break;
                }
        case 2: {
                   system("CLS");
                   display_menu();
                   break;
                }
        case 3: {
                   system("CLS");
                   //delete_item();
                   break;
                }
        case 4: {
                   system("CLS");
                   //generate_bill();
                   break;
                }

    }
    }while(choice!=5);


}

 struct product
    {
        char name[100];
        int price;
    };

void additem()
{
    int ch;
    struct product p;
    printf("Enter product name: \n");
    scanf("%s", p.name);
    printf("Enter price: \n");
    scanf("%d", &p.price);
    printf("Do you want to add more items(1/2): \n");
    scanf("%d", &ch);

    if(ch == 1)
    {
        additem();
    }
    else
    {
        system("CLS");
        register_purchase();
    }

}

void display_menu()
{
 struct product p;
 printf("%s\t", p.name);
 printf("%d\t\n", p.price);


  /*printf("\t            ==============================          \n");
  printf("\t                    Breakfast Menu   \n");
  printf("\t            ==============================          \n\n");

  printf("\t   [1] Pancakes                           - Rs.210 \n");
  printf("\t   [2] Avocado Toasts                     - Rs.299 \n");
  printf("\t   [3] Granola                            - Rs.185 \n");
  printf("\t   [4] Sausage Gravy Breakfast Lasagna    - Rs.379 \n");
  printf("\t   [5] Instant Pot Mini Frittatas         - Rs.185 \n");
  printf("\t   [6] Scrambled Eggs with Herbs          - Rs.145 \n");
  printf("\t   [7] Breakfast Bread Pudding            - Rs.155 \n");
  printf("\t   [8] Blueberry Scones with Lemon Glaze  - Rs.465 \n");
  printf("\t   [9] Sheet-Pan Bacon Egg Sandwiches     - Rs.500 \n");
  printf("\t   [10] Burritos with Chorizo             - Rs.410 \n");
  printf("\t   [11] Add New One             \n");
  printf("\t   [12] Back To Main-Menu         ");

  printf("\n\n \t   Enter your choice here : ");
  scanf("%d", &choice);

  if (choice == 1)
	   {
           printf("\nIngredient : All-Purpose Flour,Sugar,Baking Powder,Teaspoon Salt,Ground Nutmeg,Eggs,Unsalted Butter,\n\n");
	       printf("Enter Quantity : ");
	       scanf("%d", &quantity);
           total = 210 * quantity ;
           printf("Your order is %d Pancakes\n", quantity);
           printf("===================================          ");
           printf("\nYour total bill amount is Rs.%.2f,\nPayment: CASH\n", total);
           printf("====================================          \n");
	       printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
           scanf("%d", &again);
           system("cls");

			 if (again == 1 )
				display_menu();
			 else if (again == 2 )
                 salesmenu();
			 else if (again != 1 , 2)
				{
				   printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
				   exit(0);
				}
       }
       //codeastro.com
	else if ( choice == 2)
       {
		  printf("\nIngredient : Ripe Avocado, Fine Salt, Ground Black Pepper, Slices of Whole Grain, Clove Garlic, Extra-Virgin Oil, Flaky Sea Salt, Red Pepper Flakes\n\n");
		  printf("Enter Quantity : ");
		  scanf("%d", &quantity);
		  total = 299 * quantity ;
		  printf("===================================          ");
          printf("\nYour total bill amount is Rs.%.2f,\nPayment: CASH\n", total);
          printf("====================================          \n");
          printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
          scanf("%d", &again);
          system("cls");

			 if (again == 1 )
				display_menu();
			 else if (again == 2 )
				salesmenu();
			 else if (again != 1 , 2)
				{
				   printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
				   exit(0);
				}
        }
    else if ( choice == 3 )
        {
			  printf("\nIngredient : Oats, Slivered Almonds, Cashews, Sweet Coconut, Dark Brown Sugar, Vegetable Oil, Salt, Raisin\n\n");
			  printf("Enter Quantity : ");
			  scanf("%d", &quantity);
			  total = 185 * quantity ;
			  printf("===================================          ");
              printf("\nYour total bill amount is Rs.%.2f,\nPayment: CASH\n", total);
              printf("====================================          \n");
              printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
              scanf("%d", &again);
              system("cls");

			  if (again == 1 )
				{
				   display_menu();
                }
			  else if (again == 2 )
				{
				   salesmenu();
				}
              else if (again != 1 , 2)
                {
					 printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
					 exit(0);
                }
        }
    else if ( choice == 4 )
        {
			  printf("\nIngredient : Kosher Salt, Ground Black Pepper, Lasagna Noodles, Olive Oil, Sausage, Scallions, Flour, Milk, Grated Nutmeg, Mozzarella Cheese, Cheddar, Parmesan, Spinach, Parsley Leaves\n\n");
			  printf("Enter Quantity : ");
			  scanf("%d", &quantity);
			  total = 379 * quantity ;
			  printf("===================================          ");
              printf("\nYour total bill amount is Rs.%.2f,\nPayment: CASH\n", total);
              printf("====================================          \n");
              printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
              scanf("%d", &again);
              system("cls");

			  if (again == 1 )
				{
				   display_menu();
                }
			  else if (again == 2 )
				{
				   salesmenu();
				}
              else if (again != 1 , 2)
                {
					 printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
					 exit(0);
                }
        }
    else if ( choice == 5 )
        {
			  printf("\nIngredient : Bacon, Mushrooms, Thyme Leaves, Kosher Salt, Baby Spinach, Cheddar, Eggs, Cream, Grated Nutmeg \n\n");
			  printf("Enter Quantity : ");
			  scanf("%d", &quantity);
			  total = 185 * quantity ;
			  printf("===================================          ");
           	  printf("\nYour total bill amount is Rs.%.2f,\nPayment: CASH\n", total);
              printf("====================================          \n");
              printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
              scanf("%d", &again);
              system("cls");

			  if (again == 1 )
				{
				   display_menu();
                }
			  else if (again == 2 )
				{
				   salesmenu();
				}
              else if (again != 1 , 2)
                {
					 printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
					 exit(0);
                }
        }
    else if ( choice == 6 )
        {
			  printf("\nIngredient : Eggs, Milk, Heavy Cream, Fresh Chives, Parsley Leaves, Tarragon Leaves, Black Pepper, Unsalted Butter \n\n");
			  printf("Enter Quantity : ");
			  scanf("%d", &quantity);
			  total = 145 * quantity ;
			  printf("===================================          ");
              printf("\nYour total bill amount is Rs.%.2f,\nPayment: CASH\n", total);
              printf("====================================          \n");
              printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
              scanf("%d", &again);
              system("cls");

			  if (again == 1 )
				{
				   display_menu();
                }
			  else if (again == 2 )
				{
				   salesmenu();
				}
              else if (again != 1 , 2)
                {
					 printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
					 exit(0);
                }
        }
    else if ( choice == 7 )
        {
			  printf("\nIngredient : Eggs, Honey, Vanilla Extract, Orange Zest, Kosher Salt, Brioche Leaf, Golden Raisins, Maple Syrup \n\n");
			  printf("Enter Quantity : ");
			  scanf("%d", &quantity);
			  total = 155 * quantity ;
			  printf("===================================          ");
              printf("\nYour total bill amount is Rs.%.2f,\nPayment: CASH\n", total);
              printf("====================================          \n");
              printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
              scanf("%d", &again);
              system("cls");

			  if (again == 1 )
				{
				   display_menu();
                }
			  else if (again == 2 )
				{
				   salesmenu();
				}
              else if (again != 1 , 2)
                {
					 printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
					 exit(0);
                }
        }
    else if ( choice == 8 )
        {
			  printf("\nIngredient : Flour, Baking Poweder, Salt, Unsalted Butter, Blueberries, Heavy Creams, Lemon Juice, Zest finely Grated\n\n");
			  printf("Enter Quantity : ");
			  scanf("%d", &quantity);
			  total = 465 * quantity ;
			  printf("===================================          ");
              printf("\nYour total bill amount is Rs.%.2f,\nPayment: CASH\n", total);
              printf("====================================          \n");
              printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
              scanf("%d", &again);
              system("cls");

			  if (again == 1 )
				{
				   display_menu();
                }
			  else if (again == 2 )
				{
				   salesmenu();
				}
              else if (again != 1 , 2)
                {
					 printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
					 exit(0);
                }
        }
    else if ( choice == 9 )
        {
			  printf("\nIngredient : Bacon, Eggs, Scallions, Black Pepper, Vegetable Oil, Plum Tomatoes, Cheddar, Potato Sandwich Rolls, Hot Sauce \n\n");
			  printf("Enter Quantity : ");
			  scanf("%d", &quantity);
			  total = 500 * quantity ;
			  printf("===================================          ");
              printf("\nYour total bill amount is Rs.%.2f,\nPayment: CASH\n", total);
              printf("====================================          \n");
              printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
              scanf("%d", &again);
              system("cls");

			  if (again == 1 )
				{
				   display_menu();
                }
			  else if (again == 2 )
				{
				   salesmenu();
				}
              else if (again != 1 , 2)
                {
					 printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
					 exit(0);
                }
        }
    else if ( choice == 10 )
        {
			  printf("\nIngredient : Jalapeno Pepper, Red Onion, Cilantro, Lime Juice, Kosher Salt, Pepper, Chorizo, Hash Brown Potatoes, Eggs, Refried Beans, Tortillas, Mozzarella Cheese \n\n");
			  printf("Enter Quantity : ");
			  scanf("%d", &quantity);
			  total = 410 * quantity ;
			  printf("===================================          ");
              printf("\nYour total bill amount is Rs.%.2f,\nPayment: CASH\n", total);
              printf("====================================          \n");
              printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
              scanf("%d", &again);
              system("cls");

			  if (again == 1 )
				{
				   display_menu();
                }
			  else if (again == 2 )
				{
				   salesmenu();
				}
              else if (again != 1 , 2)
                {
					 printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
					 exit(0);
                }
        }*/
}

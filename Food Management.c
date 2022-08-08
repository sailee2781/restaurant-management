#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

//Struct node

struct Node{

    char foodname[30];
    int data,stock;
    float price;
    struct Node *next;

};

typedef struct Node node;

//Global Type Variale
node *head , *menu; //pointers


int credit_card[20];
float total_paisa[20];
char problem_box[20];


/// Function for print any word
void print(char list[])
{
    printf("%s",list);
}


/// Function to print a new line
void line(int cnt)
{
    int i;
    for(i=1;i<=cnt;i++);
    printf("\n");
}


// Function for print a new tab
void tab(int cnt)
{
    int i;
    for(i=1;i<=cnt;i++);
    printf("\t");
}


/// Function for clear windows screen
void scr()
{
    system("cls");
}



// Function for main menu
fooodlist()
{
    line(10); tab(20); print("1. \"* Food Menu           |\"");line(2);Sleep(350);system("color 4F");
    line(10); tab(20); print("2. \"* Admin Log In        |\"");line(2);Sleep(350);
    line(10); tab(20); print("3. \"* Rules & Reg         |\"");line(2);Sleep(350);
    line(10); tab(20); print("4. \"* Problem % suggestion|\"");line(2);Sleep(350);
    line(10); tab(20); print("5. \"* Exit                |\"");line(2);Sleep(350);
}


/// Function for insert food list
void insertfood(char foodname[30] , int data , int stock , float price)
{
    node *temp; //pointer to the node object

    temp=(node*)malloc(sizeof(node)); //Allocates sizeof byes,and returns a void pointer to it

    temp->data=data;

    temp->stock=stock;

    temp->price=price;

    strcpy(temp->foodname,foodname); //1st source then destination

    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
        menu=head;
    }

     else
    {
      while(head->next!=NULL)
        {
            head=head->next;
        }
        head->next=temp;
    }

}

/// Function for print foodlist
void foodlist()
{
    node *start;

    start=menu;

    printf("--------------------------------------------\n");system("color 5A");
    printf(" Item Number |  Food name  |  Price  |  Stock   \n");

    while(start != NULL)
    {

        printf("--------------------------------------------\n");

        line(30); tab(30);

        printf("%d    |  %s    | %d     | %.2f    \n",start->data , start->foodname , start->stock , start->price);Sleep(200);line(3);

        printf("----------------------------------------\n");

        start=start->next;
    }
}


// Function for count the total food item
int count()
{
    int cnt=0;

    node *temp;
    temp=menu;

    while(temp != NULL)
    {
        temp=temp->next;
        cnt++;
    }

    return cnt;
}


//Total take for order
int total_money(int foodchoice, int much)
{
    scr();

    node *temp;

    temp=(node*)malloc(sizeof(node));

    temp=menu;

    while(temp->data != foodchoice)
    {
        temp=temp->next;
    }

        if(temp->data==foodchoice)
        {
            int o;
            float total=temp->price*much;

            line(3);tab(2); printf("Total money for your order : ");line(2);system("color 7C");
            line(3);tab(2); printf("%.2f",total); line(2);
            line(10);tab(20); printf(" Enter your table number :"); line(2);
            line(10);tab(70); scanf("%d",&o);line(2);

            return total ;
        }

}



// Function for payment
void payment(float money)
{
    scr();


    back_option:

        line(10);tab(20); printf("How you pay this money :"); line(2);system("color 9F");
        line(10);tab(70); printf("1. cash");line(2);
        line(10);tab(70); printf("2. Credit Card");line(2);

        int choose;
        float take;

        line(5);tab(3); scanf("%d",&choose);line(2);

        if(choose==1)
        {
            scr();

            give :
            line(5);tab(5); print( " How much you give :");line(2);system("color 69");
            line(5);tab(5); scanf("%f",&take);line(2);

            if(money>take)
            {
                scr();
                line(10);tab(10); printf("Please give %.2f some also",money-take);line(2);
                goto give;
            }

            else
            {
                scr();
                  line(5);tab(5); printf("you paben %.2f",take-money);line(2);
            }

        }

        else if(choose==2) {

            scr();

            int card_num[20], i=0;
            line(5);tab(5); print("please give your card number :");line(2);
            line(5);tab(10); scanf("%d,&card_num[i]");line(2);
            credit_card[i]=card_num[i];
            i++;

            scr();

            line(2);tab(2); printf("Thank you Sir");line(2);

        }
        else
        {
            line(10);tab(5); printf("Please enter correct password");line(2);
            goto back_option;
        }

}



//Function for food order
int orderlist()
{
    int foodchoice, much, i, j, k;

    food_choice :
    line(2); print("Which product !"); line(3);

    tab(5); scanf("%d",&foodchoice);
    i=count();

    if(foodchoice>=1 && foodchoice<=i)
    {
        line(2);tab(2); print("How much you need : ");
        tab(3);scanf("%d",&much);

        k=total_money(foodchoice,much);
        payment(k);
        return k;
    }
    else
    {
        scr();
        line(5);tab(3);print("Enter correct item number please : ");line(2);
        foodlist();
        goto food_choice;
    }
}


// Function for inser a new food into the list
/*void insertfood(int fooddata, char addfood[30] , float foodprice , int foodstock)
{
    node *temp , box;
    temp=(node*)malloc(sizeof(node));
    temp->data=fooddata;
    temp->foodname=addfood;
    temp->stock=foodstock;
    temp->price=foodprice;
    temp->next=NULL;
    box=temp;
    head->next=box;
    box->next=NULL;

}*/



// Function for windows size
void windows()
{
    system("title ....Restaurant Management....");
    system("mode con: lines=35 cols=120");
}



// Main Function


int main()
{

    windows();

    line(30); tab(20); print("***********");line(2);
    line(30); tab(20); print("* WELCOME TO OUR RESTAURANT *");line(2);
    line(30); tab(20); print("***********");line(2);Sleep(3000);

    main_menu:

    line(5); tab(5); print("Enter Your Choice :");line(4);

    fooodlist();

    head=NULL;

    insertfood("Beef",1,50,150);
    insertfood("Chicken",2,45,50);
    insertfood("shing",3,30,60);
    insertfood("Utkol",4,45,70);
    insertfood("gojal",5,430,50);

    int choose , foodstock , fooddata , backmenu ;
    float foodprice;
    char choice,addfood[30];
    char problem[2000],problem_box[2000];

    line(5);tab(3);print("--> "); scanf("%c",&choice);

    if(choice>='1' && choice<='5')
    {
        if(choice=='1')  // Food Menu
        {
            food_list:
            scr();
            line(30); tab(20); print("Enter Your Choice : ");line(3);

            foodlist();
            orderlist();

            line(10); tab(5); printf("Thank you for choosing");line(2);

            another_food :

            line(10);tab(5); printf("Do you want to order something else ? ");line(2);
            line(3);tab(2); printf("press 1 for main menu 2 for foodlist or 0 for exit =>");
            tab(5);   fflush(stdin);scanf("%d",&backmenu);

            switch(backmenu)
            {
                case 1:

                        scr();
                        goto main_menu;
                        break;

                case 2:

                        scr();
                        goto food_list;
                        break;

                case 0:

                        scr();
                        line(10);tab(5); printf("....Thank you Sir....");line(5);
                        break;

                default:

                    printf("Enter correct press :");
                    goto another_food;
            }

        }

        else if(choice=='2')
                // Admin Panel
        {
            scr();
            int pass;

            admin_log:

            line(5);tab(5);print("Enter 0 for go to the main menu");line(2);system("color 9F");

            line(10); print(" Enter The Password : ");line(4);

            line(3);tab(2); fflush(stdin);scanf("%d",&pass);

            if(pass==00000)
            {
                choose_option:
                scr();

            line(5);tab(5); print("1. Total Money"); line(2);system("color 1E");
            line(5);tab(5); print("2. Problem and Suggestion"); line(2);
            line(5);tab(5); print("3. Add Food"); line(2);
            line(5);tab(5); print("4. Delete Food"); line(2);
            line(5);tab(5); print("5. All card number"); line(2);
            line(5);tab(5); print("6. Total Item"); line(2);
            line(5);tab(5); print(" Enter 0 for go to the main menu "); line(2);


            line(5);tab(5); scanf("%d",&choose);

            if(choose>=0 && choose <=7)
            {

                if(choose==1)
                {
                    scr();
                    int k;
                    line(5);tab(5);
                    orderlist(k);
                    printf("%d",k);

                    line(2);
                }

                else if(choose==2)
                {
                    scr();
                    int q=0;
                    line(5);tab(5); printf("%s",problem_box[q]);line(2);
                    q++;
                }

                else if(choose==3)
                {
                    scr();

                    printf(" Enter list Number : ");

                    scanf("%d",&fooddata);

                    printf(" Enter the food name : ");

                    scanf("%s",&addfood);

                    printf(" Enter food price: ");

                    scanf("%f",&foodprice);

                    printf(" Enter food stock: ");

                    scanf(("%d",&foodstock));
                    //insertfood();

                    line(5);tab(5); print("sorry....we work for improving this software:) Thank You");line(2);
                }

                else if(choose==4)
                {
                    scr();
                    line(5);tab(5); print("sorry....we work for improving this software:) Thank You");line(2);
                }

                else if(choose==5)
                {
                    int k=0;
                    scr();
                        line(5);tab(5);printf("%d",credit_card[k]);line(2);
                        k++;


                }

                else if(choose==0)
                {
                    scr();
                    goto main_menu;
                }

                else if(choose==6)
                {
                    scr();

                    int total,k;

                    total=count();
                    line(20);tab(20);printf("Our Total Food %d item",total);line(20);

                    admin_panel:

                    line(5);tab(5); print(" Enter 0 for back \n");
                    line(5);tab(5); fflush(stdin);scanf("%d",&k);

                    if(k==0)
                    {
                        scr();
                        goto choose_option;
                    }

                    else {

                        scr();
                        line(5);tab(5); print("Please enter the correct pass"); line(2);
                        goto admin_panel;

                    }
                }

            }

            else
            {
                line(10);tab(5); print("Enter between 1 and 7");
                goto choose_option ;
            }

            }

            else

            {
                scr();

                line(10); print(" Wrong Password....Enter Correct Password");line(5);
                line(10); tab(5); print(" Enter 0 for go the main menu ");line(2);

                if(pass==0)
                {
                    scr();

                    goto main_menu ;
                }

                else
                    goto admin_log;
            }

        }

        else if(choice=='3')    //Rules and Regulations
        {
            scr();
            int rules;

            rules_option:

            line(5);tab(30); print("....Rules and Regulations....");line(5);system("color 2F");
            line(10);tab(10); print("1.Food safety at kitchen");line(5);Sleep(700);
            line(5);tab(10); print("2.Staff attire and hygiene");line(5);Sleep(700);
            line(5);tab(10); print("3.Food safety at inventory");line(5);Sleep(700);
            line(5);tab(10); print("4.Transportation vehicle guidelines");line(5);Sleep(700);
            line(5);tab(10); print("5.Customer service area");line(5);Sleep(700);
            line(5);tab(10); print("6.General food safety measures");line(5);Sleep(700);
            line(10);tab(20); print("....Keep smiling and enjoy your food....");line(5);
            line(10);tab(10); print("press 0 for back :");scanf("%d",&rules);

            if(rules==0)
            {
                scr();
                fflush(stdin);
                goto main_menu;
            }

            else
            {
                scr();
                line(5);tab(5); print("Enter correct press");
                goto rules_option;

            }


        }

        else if(choice=='4')  // Problems and suggestion box
        {
            scr();

            int back,m=0;

            line(10);tab(10);print("Please write your problem and solution ");line(5);system("color 8E");
            line(10);tab(5); fflush(stdin);
            gets(problem);line(5);
            problem_box[m]=problem;
            m++;

            scr();
            line(5);tab(5);print(" THANK YOU ");line(5);

            back_option:

            line(5);tab(5);print("--> 0 for back");
            tab(3);scanf("%d",&back);

            if(back==0)
            {
                scr();
                fflush(stdin);
                goto main_menu;
            }

            else
            {
                scr();
                line(5);tab(5);print("enter correct pass");line(5);
                goto back_option;
            }
        }

        else if(choice=='5')  // Exit option
        {
            scr();
            line(20);tab(3); print(".....THANK YOU.....");line(20);
        }

    }
    else if(choice>='a' && choice<='z')
    {
        scr();
        line(20);tab(5); printf("Please, Enter a number between 1 and 5");line(3);
        goto main_menu;
    }

     else
     {
        scr();
        line(20);tab(5); print("Please, Enter your choice between 1 and 5");line(3);
        goto main_menu;
     }

    return 0;
}

//Name:Anurag
//Roll no:1601CS05
//PROGRAM: TO MANAGE A BOOK IN LIBRARY
//Date:31/7/17


#include<stdio.h>                      //deceleration of header files
#include<stdlib.h>
#include<string.h>

struct node{                        //create a  node
int sn;
char title[100];
char author[100];
char status[100];
struct node *next;

};

struct node *head=NULL,*prev;                           //global variables root node

void status();                                       //deceleration of all function
void serial();
void author();
void title();
void display();
void entry();
void issue();
void rebook();

int main()                                  //main function
{
    char  check;
    int n;

    printf("a. Make a new entry\nb. View Details of a Book\nc. Show list of avaliable Books\nd. Issue a book\ne. Return a Book\nf. Exit\n");

    while(1)                                         //loop to manage all process infinite while return
    {
         printf("\nEnter your Choice = ");                         //read your choice
        scanf(" %c",&check);

       switch(check)                        //switch case
       {
           case  'a': printf("\nMAKE A NEW ENTRY OF BOOK\n");

                        entry();//calling entry function
                   break;

           case  'b': printf("VIEW DETAILS OF A BOOK\n\n");
                      printf("1).By serial no\n2).By title \n3).By Author\n");
                          scanf("%d",&n);
                          if(n==1)
                            {serial();}

                          else

                           if(n==2)
                          {title();}

                          else

                            if(n==3)
                          {author();}
                   break;

           case 'c':
                          status(); //calling status function

                   break;

           case 'd':
                          issue(); //calling issue function

                   break;

           case 'e':
                          rebook(); //calling rebook function

                   break;

           case 'f': printf("\nExit\n");
                      return 0;
                   break;

            default:
                printf("\nWrong input\nEnter a option given below:\n");
                printf("\na. Make a new entry\nb. View Details of a Book\nc. Show list of avaliable Books\nd. Issue a book\ne. Return a Book\nf. Exit\n");


 }}}


void entry()                      //function take entry
{
    int se;                                     //deceleration of variables
    char title[100],author[100],status[100]="Not Issued";

    struct node *p;                                   //create a node
    p=(struct node *)malloc(sizeof(struct node));            //allocate memory space to node
    printf("\nEnter s.no =");
    scanf("%d",&se);
    printf("Enter Title =");
    scanf("\n");
    scanf ("%[^\n]%*c", title);
    printf("Enter Author=");
    scanf("\n");
    scanf ("%[^\n]%*c", author);
    printf("\nNew Entry Successful..\n");


    p->sn=se;                                    //coping of all things in node variables
    strcpy(p->title,title);
    strcpy(p->author,author);
    strcpy(p->status,status);

    p->next=NULL;

    if(head==NULL)
        head=p;
    else
        prev->next=p;

      prev=p;

}

void serial()                            //function to print list by serial number
{
     int sea;                                        //deceleration of variables
     struct node *p=head;

     if(head==NULL){
        printf("\nNO BOOK FOUND\n");                  //return if head is NULl
       return ;}

       else{

 printf("\nEnter a serial no =");
     scanf("%d",&sea);

     int flag=1;
     while(p!=NULL)
    {
           if(p->sn==sea)                    //condition to  print
            {
        printf("\nS.no = %d\n",p->sn);
        printf("Title = %s\n",p->title);
        printf("Author = %s\n",p->author);
        printf("Status = %s\n",p->status);
           flag=0;
           }
        p=p->next;
    }
    if(flag==1)
    printf("\nBook not Found\n");
}
}

                                   //function to print list by author number
void author()
{
     char ch[100];
    struct node *p=head;
     if(head==NULL){
        printf("\nNO BOOK FOUND\n");                  //return if head is NULl
       return;}

       else{                      //deceleration of variables
    printf("\nEnter author name =");
    scanf("%s",ch);
    int flag=1;
    while(p!=NULL)
    {
           if(strcmp(p->author,ch)==0){             //condition to  print
        printf("\nS.no = %d\n",p->sn);
        printf("Title = %s\n",p->title);
        printf("Author = %s\n",p->author);
        printf("Status = %s\n",p->status);
           flag=0;
           }
        p=p->next;
    }
    if(flag==1)
        printf("\nBook not found with this author name\n");
}
}



void title()                    //function to print list by title number
{
     char ch[100];
    struct node *p=head;                  //deceleration of variables

     if(head==NULL){
        printf("\nNO BOOK FOUND\n");                   //return if head is NULl
       return ;}

       else{
         printf("\nEnter title of book =");
    scanf("%s",ch);
    int flag=1;
    while(p!=NULL)
    {
           if(strcmp(p->title, ch)==0){              //condition to  print
        printf("\nS.no = %d\n",p->sn);
        printf("Title = %s\n",p->title);
        printf("Author = %s\n",p->author);
        printf("Status = %s\n",p->status);
                flag=0;
           }
        p=p->next;

    }

    if(flag==1)
        printf("\nBook not found with this title\n");

}
}


void status()               //function to print list by status number
{
    char ch[100]="Not Issued";
    struct node *p=head;
    if(head==NULL)
     {  printf("\nSORRY,NO BOOK FOUND \nMAKE A NEW ENTRY\n");               //return if head is NULl

         return;
     }
     else
      {                //deceleration of variables
    int flag=1;
    while(p!=NULL)
    {
           if(strcmp(p->status,ch)==0)
            {                           //condition to  print
        printf("\nS.no = %d\n",p->sn);
        printf("Title = %s\n",p->title);
        printf("Author = %s\n",p->author);


            flag=0;
           }
        p=p->next;
    }
    if(flag==1)
     printf("\nBooks not available . All books are issued\n");
}
}

void issue()                         //function to issue book
{    int se,sea;
      char ch[100]="Not Issued";
      char ch1[100]="Issued";
      struct node *p=head,*r=head;

     if(head==NULL)                                            //return if head is nULL
     {  printf("\nSORRY,NO BOOK FOUND \nMAKE A NEW ENTRY\n");
         entry();
         return;
     }
     else
      {


      printf("\nEnter Serial no of book = ");
      scanf("%d",&se);                         //deceleration of variables
      int flag=1;

    while(p!=NULL)
    {
           if(p->sn==se){
                                    //condition to  print
                if(strcmp(p->status,ch1)==0)
           {
               printf("\nBooks is all ready Issued\n");
                        return ;
           }
           else
           {


              strcpy(p->status,ch1);
              flag=0;
              break;
           }
     }
        p=p->next;
    }
    if(flag==0)
    printf("\nYour book is Issued \n");
    else
    printf("\nBooks not avaliable with serial no.  %d\n",se);
  }
}

void rebook()                         //function to issue book
{    int se,sea;
      char ch[100]="Not Issued";
      char ch1[100]="Issued";
      struct node *p=head,*r=head;


      printf("\nEnter Serial no of book = ");
      scanf("%d",&se);                         //deceleration of variables
      int flag=1;

    while(p!=NULL)
    {
           if(p->sn==se){
                                          //condition to  print
                if(strcmp(p->status,ch)==0)
           {
               printf("\nBooks is all ready returned\n");
                        return ;
           }
           else
           {


              strcpy(p->status,ch);
              flag=0;
              break;
           }
     }
        p=p->next;
    }
    if(flag==0)
    printf("\nYour book is Returned \n");
    else
    printf("\nBooks not issued with serial no.  %d\n",se);
  }



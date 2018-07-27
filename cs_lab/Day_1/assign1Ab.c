//Name:Anurag
//Roll no:1601CS05
//Date:31/07/17
//PROGRAM: ARRANGE A NAMES IN DICTONARY ORDER

#include<stdio.h>                                //HEADER FILES
#include<string.h>
#include<stdlib.h>

struct node{                                     //CREATING  A NODE
char ch;
struct node *next;
};
                                //DECELERATION OF  All FUNCTION
void display();
void isPalindrome1();
void isPalindrome2();
struct node *arrangelist1();
struct node *arrangelist2();
int check(char x);
int print(int a, int b);
int print2(int a,int b);

struct node *head1=NULL,*head2=NULL, *head3=NULL,*head4=NULL;                         //ROOT POINTER and global variables

char  arrlist1[100];
char  arrlist2[100];

  int main()
  {                                          //MAIN
  char name0[100][100],name1,name2[100][100],name3;                                   //DECELERATION OF VARIABLES
  int n,i,x,y;

  struct node *prev;
  struct node *list1,*list2;
  printf("ENTER NUMBER = ");
  scanf("%d",&n);

  if(n%2 == 0)
  { x=n/2;
    y=n/2;
  }

  else
  { x=n/2;
    y=n-n/2;
  }

  printf("Enter a names \n");
   for(i=0;i<x;i++)                                                //LOOP FOR READ NUMBER OF STUDENT AND NAMES for x
{


         list1=(struct node* )malloc(sizeof(struct node));
         scanf("%s",name0[i]);
         name1=name0[i][0];
         list1->ch=name1;
         list1->next=NULL;
          if(head1==NULL)
            head1=list1;
         else
            prev->next=list1;
            prev=list1;
   }



    for(i=0;i<y;i++)                                                //LOOP FOR READ NUMBER OF STUDENT AND NAMES for y
   {
         list2=(struct node* )malloc(sizeof(struct node));
         scanf("%s",name2[i]);
         name3=name2[i][0];
         list2->ch=name3;
         list2->next=NULL;

          if(head2==NULL)
            head2=list2;
             else
          prev->next=list2;
           prev=list2;
  }


head3=arrangelist1();
head4=arrangelist2();                                      //CALLING A FUNCTION
display();


isPalindrome1();

isPalindrome2();                               //calling palindrome function

}


struct node *arrangelist1()                               //function to arrange list1 in given manner
{
    struct node *newHead = head1,*lv,*curr = head1;
    if (head1 == NULL)
        return 0;

    if (check(head1->ch))
        lv = head1;                    //make a  new link list of vowels and constant
    else
       {
         while (curr->next != NULL &&
               !check(curr->next->ch))
                curr = curr->next;

         if (curr->next == NULL)
            return head1;

        lv = newHead = curr->next;
        curr->next = curr->next->next;
        lv->next = head1;
    }

     while (curr != NULL && curr->next != NULL)                  //to join  list
    {
        if (check(curr->next->ch))
        {
            if (curr == lv)
            {lv = curr = curr->next;}
            else
            {struct node *temp = lv->next;
            lv->next = curr->next;
            lv = lv->next;
            curr->next = curr->next->next;
            lv->next = temp;
            }
        }
        else
        {curr = curr->next;}
    }
    return newHead;                    //return new list
}

struct node *arrangelist2()                       //function to arrange list2 in given manner
{
    struct node *newHead = head2,*lv,*curr = head2;
    if (head2 == NULL)
        return 0;

    if (check(head2->ch))
        lv = head2;
    else
       {
         while (curr->next != NULL &&                        //make a  new link list of vowels and constant
               !check(curr->next->ch))
                curr = curr->next;

         if (curr->next == NULL)
            return head2;

        lv = newHead = curr->next;
        curr->next = curr->next->next;
        lv->next = head2;
    }

     while (curr != NULL && curr->next != NULL)               //to join  list
    {
        if (check(curr->next->ch))
        {
            if (curr == lv)
            {lv = curr = curr->next;}
            else
            {struct node *temp = lv->next;
            lv->next = curr->next;
            lv = lv->next;
            curr->next = curr->next->next;
            lv->next = temp;
            }
        }
        else
        {curr = curr->next;}
    }
    return newHead;                         //return new list
}


 int check(char x)                                      //function to check vowels and return
{
    if(x == 'a'|| x == 'e' || x == 'i' || x == 'o' || x == 'u'||x == 'A'|| x == 'E' || x == 'I' || x == 'O' || x == 'U')
     return 1;
  else
     return 0;
}


void isPalindrome1()                                  //function to find palindrome
{
    int n=strlen(arrlist1);
    int n1=strlen(arrlist2);               //deceleration of function
    int i,j,k,flag;

   for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
            {
                flag=0;

               if(arrlist1[i]==arrlist1[j])
                {

                 flag=1;

                  int h=j,l=i;

                   while(l<h)
                  {
                    if(arrlist1[l]!=arrlist1[h])
                   {
                      flag=0;
                      break;
                   }
                      l++;
                       h--;
                   }
                   }

               if(flag==1)
                {

                   print(i,j);

                }}}}


void isPalindrome2()                                  //function to find palindrome
{
    int n=strlen(arrlist2);
                                            //deceleration of function
    int i,j,k,flag;

   for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
            {
                flag=0;

               if(arrlist2[i]==arrlist2[j])
                {

                 flag=1;

                  int h=j,l=i;

                   while(l<h)
                  {
                    if(arrlist2[l]!=arrlist2[h])
                   {
                      flag=0;
                      break;
                   }
                      l++;
                       h--;
                   }
                   }

               if(flag==1)
                {

                   print2(i,j);

                }}}}
int print(int a, int b)                 //function to print palindrome
{
     int i;
     for(i=a;i<=b;i++)
     printf("%c",arrlist1[i]);
     printf("  is palindrome\n");
}

int print2(int a,int b)
{
    int i;
     for(i=a;i<=b;i++)
     printf("%c",arrlist2[i]);
       printf("  is palindrome\n");

}

void display()
{                                              //FUNCTION TO DISPLAY
       struct node *r,*p;
       r=head3;
       p=head4;
    int i=0;
     printf("\nFirst list:  ");
      while(r!=NULL)                                  //LOOP WHILE POINTER GOES TO NULL
         {
            printf("%c->",r->ch);
            arrlist1[i++]=r->ch;
            r=r->next;
         }
     printf("\nSecond list:  ");
   i=0;
      while(p!=NULL)                                  //LOOP WHILE POINTER GOES TO NULL
         {
            printf("%c->",p->ch);
             arrlist2[i++]=p->ch;
            p=p->next;
         }
         printf("\n");
}






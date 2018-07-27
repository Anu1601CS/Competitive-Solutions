//Name:Anurag
//Roll no:1601CS05
//Date:31/7/17
//PROGRAM: ARRANGE A NAMES IN DICTONARY ORDER





#include<stdio.h>                                //HEADER FILES
#include<string.h>
#include<stdlib.h>

struct node{                                     //CREATING  A NODE
char ch[100];
char ch2[100];
struct node *next;

};

void sort();                                   //DECELERATION OF FUNCTION
void display();

struct node *head=NULL;                           //ROOT POINTER

  int main()

  {
                                                //MAIN
  char name[100];                                   //DECELERATION OF VARIABLES
  int n,i;
  int k,l;
  int d=0;
  char ch[999][999];
  char ch1[999][999];
  char newchar[100][100];
  int j,l1,l2,c=0,count;

  struct node *prev;
  struct node *p;

  printf("ENTER NUMBER OF STUDENT = ");
  scanf("%d",&n);

   for(i=0;i<n;i++)
    {
       printf("Enter a name %d: ",i+1);
       scanf("%s",&ch[i]);                              //read all names
       strcpy(ch1[i],ch[i]);

    }

      for(i=0;i<n;i++)                        //for loop to find  max index of equal character
        {

            l1=strlen(ch[i]);

             for(j=0;j<n;j++)
                {

           count=0;

                 if(j==i)
                    continue;



                    for(k=0;k<l1;k++)
                        {

                         if( ch[i][k]!=ch[j][k] )
                            {
                                            break;
                              }
                           count++;


                    }
                    if(count>d)
                        d=count;

             }
                    ch[i][d+1]='\0';
               strcpy(newchar[c++],ch[i]);                   //copy all shorted string in  new array
              d=0;

       }



   for(i=0;i<n;i++)                                                //LOOP FOR READ NAMES OF STUDENT
   {
         p=(struct node* )malloc(sizeof(struct node));
         strcpy(p->ch,ch1[i]);
         strcpy(p->ch2,newchar[i]);
         p->next=NULL;
         if(head==NULL)
            head=p;
             else
         prev->next=p;
         prev=p;
   }


    sort();                                         //CALLING A sort  FUNCTION
    display();                                                 //calling display function

}



void sort()                                              //FUNCTION TO SORT A NAMES IN DICTONARY ORDER
 {
   char temp[100];
   char temp2[100];
   int i, j;
   struct node *prev=head;
   struct node *curr=prev;
   curr=curr->next;

   while(prev!=NULL)
  {
   curr=prev->next;
      while(curr!=NULL)
       {

        if (strcmp(prev->ch, curr->ch) > 0)                                    // CONDITION FOR SWAPING OF DATA

          {

            strcpy(temp, prev->ch);                                            //SWAPING  of data
            strcpy(prev->ch, curr->ch);
            strcpy(curr->ch, temp);

            strcpy(temp2, prev->ch2);                                            //SWAPING of data
            strcpy(prev->ch2, curr->ch2);
            strcpy(curr->ch2, temp2);

          }
            curr=curr->next;
        }
     prev=prev->next;
    }
   }


  void display()
  {                                               //FUNCTION TO DISPLAY
       struct node *r,*p;
       p=r=head;
       int count=0,count1=0;
       printf("\nList of student in short name\n");
       while(r!=NULL)                                  //LOOP WHILE POINTER GOES TO NULL
         {

            printf("Student no.%d =",++count);
            printf("%s",r->ch2);
            r=r->next;
            printf("\n");

        }
        printf("\nList of student in full name\n");

        while(p!=NULL)                                  //LOOP WHILE POINTER GOES TO NULL
         {

            printf("Student no.%d =",++count1);
            printf("%s",p->ch);
            p=p->next;
            printf("\n");

        }

}






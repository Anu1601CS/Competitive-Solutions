//NAME:ANURAG
//ROLL NO:1601CS05
//DATE:07/02/1999
//PROGRAM :FIND MEDIAN

#include <stdlib.h>   //DECELERATION OF HEADER FILES
#include <stdio.h>


int i, *arr;                            //DECELERATION OF GLOBAL VARIABLES

int partition(int left, int right);                       //DECELERATION OF VARIABLES
int  median(int left, int right, int y);
void swap(int* c, int* b);

int main()                   //MAIN  FUNCTION
  {

  int n,y,value;                             //deceleration of variables
  printf("Enter number:= ");
  scanf("%d",&n);                //read number
  printf("\nEnter the array:=  ");
  arr = (int*)malloc(n*sizeof(int));          //calculate size of array

    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

        y = (n+(n%2))/2 - 1;

        printf("y= %d\n",y );


     value =  median(0,n-1,y);               //calling a median function

  printf("\nThe median of the data is:= %d\n",value);


  return 0;
}


                                            //Function  for partition the array

int partition(int left, int right)
{

    int pivot,j;
    pivot = arr[right];
    i = left-1;
    for(j=left;j<=right-1;j++)
        {

    if(arr[j]<=pivot)           //condition for swap function
        {
           i++;
          swap(&arr[i],&arr[j]);
        }
    }

  swap(&arr[i+1],&arr[right]);             //calling swap function

  return i+1;
}


void swap(int* a, int* b)               //swap function
{
  int temp;

   temp = *a;
   *a = *b;
   *b = temp;
}


int  median(int left, int right, int index)                    //median finding function
{
 if(left<right)                                //condition until program runs
    {
        int num,p;

       num = rand()%(right-left+1);              //rand function to generate a rand number between

       swap(&arr[left+num],&arr[right]);

       p = partition(left,right);

       if(p==index)
         return arr[index];                         //condition to return



       if(p<index)
         return  median(p+1,right,index);
            else                                      //condition to left travel or right travel
         return  median(left,p-1,index);


   }
}


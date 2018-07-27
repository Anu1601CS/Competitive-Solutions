//Name:ANURAG
// ROll no:1601CS05
//DATE:37/8/17
//program :To print binary equivalent

#include<stdio.h>
#include<string.h>            //deceleration of all header files
#include<stdlib.h>


int  arr[100];            //deceleration of all variables and array
int i=0;

int binary(int num)         //function to store binary in array
{
    int p;

    if(num>0)
    {
        arr[i++]=num%2;

          p=num/2+arr[i];


      binary(p);                 //passing value to function
    }
    else
    {
        return 0;
    }
}




int main()                          //main function
{
    int num,j;

    printf("\nEnter a number: ");          //read a number
    scanf("%d",&num);

    binary(num);

     printf("Binary form : ");
      for(j=i;j>=0;j--)         //print in reverse order
    printf("%d ",arr[j]);


    return 0;
}

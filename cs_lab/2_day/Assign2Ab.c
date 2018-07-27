//Name:ANURAG
// ROll no:1601CS05
//DATE:37/8/17
//program :Find largest and smallest digits


#include<stdio.h>                  //deceleration of all header files
#include<string.h>
#include<stdlib.h>


 int max=0 ;           //global variables
  int p;

int count_max(int num)       //function to find max digits
{


    if(num>0)                     //condition to execute a program at specific length
    {
        p=num%10;

        if(max<p)      //condition to update max value
        {
        max=p;
        }

      count_max(num/10);        //recursive part
    }
    else                           //return statement
    {
        return;
    }
}


int count_min (int num, int min){         //function to find min digit

    if (num==0)                       // condition  to return
        return min;

    if (min>num%10)           //condition to update min value
        min=num%10;

    count_min(num/10,min);            //recursive part
}

int main()                           //main function
{
    int num,min;        //deceleration of varabiles
    int count=0;

    printf("\nEnter a number: ");         //read  number
    scanf("%d",&num);

    count_max(num);                //calling max function
   min= count_min(num,9);           //calling min function
    printf("\nLargest =%d\n",max);    //print max
   printf("Smallest =%d\n\n",min);  //print min

    return 0;
}

//Name:ANURAG
//Roll no:1601CS05
//DATE:7/08/17
//program :COUNT number of odd digits in number


#include<stdio.h>                     //deceleration of all header files
#include<string.h>
#include<stdlib.h>

int count=0;

int count_odd(int num)                 //function to count odd digits
{


    if(num>0)                             //condition to execute a program at specific length
    {
        if(num%2!=0)               //condition increment count
         {
        count++;
        }
        count_odd(num/10);       //recursive part
    }
    else                            //condition on which program return
    {
        return count;
    }
}
int main()                //main function
{
    int num;
    int count=0;

    printf("\nEnter a number: ");        //read number
    scanf("%d",&num);

    count=count_odd(num);

    printf("\nNumber of odd digits in a given number = %d\n",count);   //print number

    return 0;
}

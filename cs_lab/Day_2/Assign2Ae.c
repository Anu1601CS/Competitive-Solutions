//Name:ANURAG
// ROll no:1601CS05
//DATE:37/8/17
//program :  recursive sum of a given number

#include<stdio.h>                 //deceleration of all header files
#include<string.h>
#include<stdlib.h>

void fun(int num)             //function to find sum
{
    int p;
    if(num/10!=0)
    {
     int sum=0;
  while(num>0)                //loop to find  sum of two digits
    {
        p=num%10;
        sum=sum+p;
        num=num/10;
    }
    printf("%d ",sum);
    fun(sum);                     //recursive function

    }
}

int main()                      //main function
{
  long long int num,j;                //deceleration of variables
    printf("\nEnter a number: ");
    scanf("%lld",&num);                  //read value
    fun(num);                      //pass value
    return 0;
}

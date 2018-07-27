//Name:ANURAG
//Roll no:1601CS05
//Date:07/08/17

#include<stdio.h>            //deceleration of all function
#include<string.h>
#include<stdlib.h>

int count=0;                //global variable

int fun(int n)                            // recursion function
{
    if(n!=1){

   if(n%2==0)                //condition if number is even
   {
       n=n/2;
       if(n==1)
        printf("Final value is = %d\n",n);
       else
       printf("Next value = %d\n",n);
       count++;
       fun(n);
 }
  else                          //condition for odd case
   {
         n=3*n+1;
         if(n==1)
        printf("Final value is = %d\n",n);
       else
        printf("Next value = %d\n",n);
          count++;
          fun(n);
}}
  else
    {return 0;}}


int main()                 //main function
{
    int num;
    printf("Initial value is = ");         //read number
    scanf("%d",&num);
if(num<1)
{

    printf("Error");
    return 0;
}
else
{

    fun(num);                         //passing a value to function
    printf("Number of steps = %d",count);

    }                               //print number of steps
     return 0;

}



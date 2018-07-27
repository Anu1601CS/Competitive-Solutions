//Name:Anurag
//Roll no:1601CS05
//Date:25/08/17
//Program on :top down manner using recursion

#include<stdio.h>           //Decleration of header files 
#include<stdlib.h>

int count=0;

long long int reduce(long long int num)         //function  to reduce number and count steps
{  

  
  
   if(num==1)
      return 0;    
   
   if(num%2==0)
   {   count++;
      reduce(num/2);
     
    }  
    else
   if(num%3==0)
   {       count++;
      reduce(num/3);

   } 
    else
   if(num%5==0)
    {  
         count++;
      reduce(num/5);
   
    }  
    else
    if(num%7==0)
     {   
          count++;
      reduce(num/7);
     
     }
      else
     { 
          count++;
          reduce(num-1);         
     
     }
}




int main()             //main function
{
    long long int num;
    
    printf("Enter number to reduce: ");
    scanf("%lld",&num);
    reduce(num);        
    printf("Steps= %d\n",count);

return 0;
}












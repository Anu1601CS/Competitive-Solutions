//Name:Anurag
//Roll:1601cs05
//Date:31/7/17
//program to find max sum in array


#include<stdio.h>                   //deceleration of header files
#include<stdlib.h>
#include<string.h>

int n,max1=0;       //global variables

int find(int arr[])        //function to find max sum
{
  int in = arr[0],e1 = 0,e2,i;           //deceleration of variables

  for (i = 1; i < n; i++)
  {
     e2 = max(in,e1);
     in = e1 + arr[i];
     e1 = e2;
  }
     return max(in,e1);                //return max sum
}

  int max(int a ,int b)                    //function to find max between two number
  {
     if(a>b)
        return a;
       else
        return b;
        }

int getMax(int arr)        //function to find max digits in number
 {
    int p=arr%10;                       //store one by one digits
     if(max1<p){                               //condition to update max
          max1=p;
     }
    if(arr==0)                                 //base condition of recursion
     return;
   getMax(arr/10);


}

int main()                               //main function
{
    int i,arr2,max;
  int arr[100];
  printf("Enter a number =");                        //read number
  scanf("%d",&n);
  for(i=0;i<n;i++){                            //loop to read values
    scanf("%d",&arr[i]);
  }
  arr2=find(arr);
  printf("%d",arr2);

   max=getMax(arr2);                    //calling of function

    printf("\nLargest digit is: %d",max);

    return 0;
}

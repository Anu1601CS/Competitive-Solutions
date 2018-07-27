//Name:Anurag
//Roll no :1601cs05
//Date:4/8/17


#include <stdio.h>             //decleration af all header files
#include <string.h>
#include <limits.h>

int s1[1000];        //global variables
int s2[1000];

int findMin(int arr[], int n);
void subset(int arr[],int n) ;

int main()         //main function
{   
    
    int arr[1000];
    int n,i;

     printf("\nEnter number : ");
    scanf("%d",&n);

    printf("Enter value:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

   
    printf("\nMinimum difference %d\n",findMin(arr, n));
    
    subset(arr,n);  


    return 0;
}






int findMin(int arr[], int n)           //function to find mindifference
{
       int sum = 0,i,j; 
       int new[100][100];

    for (i=0;i<n;i++)
        sum =sum+arr[i];
   
     int dp[n+1][sum+1];
 
   for (i=0;i<=n;i++)
        dp[i][0]=1;
 
   for (i=1;i<=sum;i++)
        dp[0][i]=0;
     
   for (i=1;i<=n;i++)
    {
        for (j=1;j<=sum;j++)
        {
             dp[i][j]=dp[i-1][j];
               
                if (arr[i-1] <= j)
                  {
                   
                   dp[i][j] |= dp[i-1][j-arr[i-1]];
        
                  }      
 
        }
    }

  int diff = INT_MAX;
     
    
    for (j=sum/2; j>=0; j--)
    {
        
        if (dp[n][j] == 1)
        {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}

void subset(int arr[],int n)             //function to find sub set
{   
    int i,j;
    int temp;
 if(n%2==0)
{
  for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (arr[i] > arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
else
{

      for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (arr[i] < arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }


}
int a=0,b=0; 
s1[0]=0;
s2[0]=0;
   
    
        for(i=0;i<n;i=i+2)
        {
          
             if(s1[a]==s2[b])
        
           {
             s1[++a]=arr[i];
             s2[++b]=arr[i+1];
           }
           else
           {  
               if(s1[a]<s2[b])
               {   
                   if(arr[i]<arr[i+1])
                   {
                     s1[++a]=arr[i+1];
                     s2[++b]=arr[i];
                   }
                   else
                   {
                     s1[++a]=arr[i];
                     s2[++b]=arr[i+1];

                   }
                  
               }
               else
               {
                    if(arr[i]<arr[i+1])
                   {
                     s1[++a]=arr[i];
                     s2[++b]=arr[i+1];
                   }
                   else
                   {  

                     s1[++a]=arr[i+1];
                     s2[++b]=arr[i];

                  }}}}

printf("Set1: ");   //print set1

for(i=1;i<=a;i++)
 {  
 if(s1[i]!=0)
    printf("%d ",s1[i]);
}
printf("\n");

printf("Set2: ");       //print set2

for(i=1;i<=b;i++)
{ 
   if(s2[i]!=0)
    printf("%d ",s2[i]);
}


}


 









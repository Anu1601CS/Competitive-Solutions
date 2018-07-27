//Name:Anurag
//Roll no:1601CS05
//Date:4/8/17


#include <stdio.h>             //decleration of all header files
#include <string.h>  
#include <limits.h>

int coins[10000];           //globle variables
int minCoins(int m, int sum)  ;

int main()           //main function
{     
	
	int num,sum,i;
	
	printf("\nEnter number of coins: ");        //read number of coin
	scanf("%d",&num);

	printf("Enter coins value:\n");     //read coins
	for(i=0;i<num;i++)
		scanf("%d",&coins[i]);
    
        printf("\nEnter a Sum of coins : ");  //read coin to sum
        scanf("%d",&sum);
    
        printf("\nMinimum number of coins : %d\n\n", minCoins(num, sum));     //print
     
        return 0;
}



int minCoins(int m, int sum)              //function to find minimum coin recuired
{
    
    
    int table[sum+1],re[sum+1],i,j,sub,s;
 
    
    table[0]=0;
 
    for (i=1; i<=sum; i++)              
    {
         table[i] = INT_MAX;
         re[i]=-1;
    }
 
        
    for (i=1; i<=sum; i++)
    {
          for (j=0; j<m; j++)
           
             if (coins[j] <= i)
              {
                 sub= table[i-coins[j]];
                if (sub != INT_MAX && sub + 1 < table[i])
                {
                  table[i] = sub + 1;
                  re[i]=j;
                }
              }
    }


     if(re[sum]==-1)                                   //loop to print pair of coin
     {
     	printf("SUM NOT POSSIBLE\n");
     	return 0;
     }
     else
     {   
     	  s=sum;

     	  while(s!=0)
     	  {

     	  	 j=re[s];
     	  	printf("%d ",coins[j]);
     	  	s=s-coins[j];
     	  }

     	  printf("\n");
      }
 
 return table[sum];
}
 








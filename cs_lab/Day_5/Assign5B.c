//Name:Anurag
//Roll no:1601CS05
//Date:28/7/17



#include <stdio.h>                               //decleration of all header files 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{                     //structure 

	char name[1000];
	int score;

};


struct node players[1000];              //structure array

void countSort(int n, int exp)                      //counting sort function
{
    struct node  output[n]; 
    int i, count[10] = { 0 };
 
    
    for (i = 0; i < n; i++)
        count[(players[i].score / exp) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    
    for (i = n - 1; i >= 0; i--) {
        output[count[(players[i].score / exp) % 10] - 1] = players[i];
        count[(players[i].score / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        players[i] = output[i];
}
 

void radixsort( int n)                //radix sort function
{    
  int m = players[0].score,i,exp;

    for (i = 1; i < n; i++)
        
        if (players[i].score > m)
            m = players[i].score;

  for (exp = 1; m/exp > 0; exp *= 10)
        countSort(n, exp);
  

}
 

void swap(int a,int b)                          //function to arrange accoring to names
{
     int i,j;
     char temp[1000];

     for(i=a;i<=b;i++)
        {

        	for(j=i+1;j<=b;j++)
        	{   
        		  if( strcmp( players[i].name , players[j].name) > 0 )
                       {
                            strcpy(temp ,players[i].name);
                            strcpy(players[i].name ,players[j].name);
                            strcpy(players[j].name,temp);

                       }
                    
        	}
        }

}


void string_arr(int n)                       //calculate range 
{   

	printf("YES\n");
	int a,b,i;

	int match;
    match=players[0].score;
	a=0;
	b=0;
    
    int flag=0;
  
 for(i=0;i<n;i++)
    {     
        if( match == players[i].score )
        {   
        	b=i;
        	flag=0;
            continue;
        }
        else
        {    
        	flag=1;
        
             match=players[i].score;
             swap(a,b);

             a=i;
             b=i;
             
        }

        
    }

         if(b==n-1 && flag==0)
        	swap(a,b);
 
      

}


 
int main()                       //main function
{   
	
    int i,n;
    printf("\nEnter a Number of players:");                       //read number of players
    scanf("%d",&n);
        
    printf("\nEnter a Names And Score \n");
    
    for(i=0;i<n;i++)
    {    
    	printf("\nData of players :%d",i+1 );                        //read name and score 
    	printf("\nName:");
      	scanf("%s",players[i].name);
      	printf("Score:");
      	scanf("%d",&players[i].score);
    }

  
    radixsort(n);                    //calling of function
    string_arr(n);

   
    printf("\n--------LIST--------\n");
    printf("\n  NAME\t\tSCORE\n");
    for (i = 0; i < n; i++)                          //loop for printing of list
    {
        printf("  %s\t\t%d\n",players[i].name,players[i].score);
       
    }
   

}

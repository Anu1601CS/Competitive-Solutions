//Name:Anurag
//Roll no:1601CS05

#include<stdio.h>          //Decleration of all header files
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define INF 99999

int V;                               //global variables
int th;
char name[100][100];
int graph[100][100];
int dist[100][100];
int allow[100][100];
int list[100][100];
int size[100]={0};
int acc[100][100];
int size1[100]={0};


int cost(int a,int b);
int check_edge(int a,int b);
void floydWarshall ();                     //decleration of functions
int check(int a,int b);
void dfs(int u,int a,int b);
int search(int a,int b);



int main()                            //main function
{   
	int i,j,value;

	printf("Enter number of student:  ");
	    scanf("%d",&V);

    printf("\n");
    for(i=0;i<V;i++)
    { 
      printf("Enter name %d :",i+1);
      scanf("%s",name[i]);
    }

    for(i=0;i<V;i++)
    {
    	for(j=0;j<V;j++)
    	{   

        		 if(i==j)
        		 	graph[i][j]=0;
        		 else
    		       graph[i][j]=INF;
    	}
    }
  

    for(i=0;i<V;i++)                     //fill graph
        {
        	for(j=i+1;j<V;j++)
        	{    

                   if( check_edge(i,j) )
                   {  
                   	 value=cost(i,j);
                   	 graph[i][j]=value;
                   	 graph[j][i]=value;
                   }
                   
        	}
        }
   
    printf("\nEnter threshold distance :  ");
        scanf("%d",&th);

printf("\n--------Edge Matrix-----\n\n");
  
  for(i=0;i<V;i++)
  {                                           //print matrix
  	for(j=0;j<V;j++)

  	{   
  		if(graph[i][j]==INF)
  			printf("INF\t");
  		  else
  		    printf("%d\t",graph[i][j]);
  	}
  	printf("\n");
  }


 floydWarshall ();               //calling function

 
 for(i=0;i<V;i++)
 	{

 		for(j=0;j<V;j++)
 		{    
 			  if(i==j)
 			  	continue;
 			  else
 			  {
 			
 			 if( dist[i][j]<th && check(i,j) )
 			 {
 			 	   allow[i][j]=1;
 			 	    list[i][size[i]++]=j;
 			 }
 			     else
 			      allow[i][j]=0;
 			
 			  }

 		}
 	}
  
printf("\n---Access between pairs---\n\n");

for(i=0;i<V;i++)
{
	for(j=0;j<V;j++)
	{
		printf("%d\t",allow[i][j]);          //print access pair graph 
		  
    }

	printf("\n");
}

	for (i=0;i<V;i++)    
	{ 
		

		 if(size[i]==0)
		 	continue;
	       else
	       {
	    	dfs(i,0,0);
	       }
	}


printf("\nNumber Denote :\n");
 for(i=0;i<V;i++)
    { 
        printf("%d. %s\n",i+1,name[i]);
    }


printf(" \nWho would be able to access whose account.\n");         //print final answer

for(i=0;i<V;i++)
{   
	  
	    
	  	 printf("(%d) can access these accounts: %d ",i+1,i+1);
	  	  for(j=0;j<size1[i];j++)
	  	  	printf("%d ",acc[i][j]);

	 
	
	printf("\n");
}

return 0;	
}



int cost(int a,int b)              //function to find cost
{    
	 int i,sum=0;
	   
     for(i=0;i<5;i++)
     {
          sum=sum+abs(name[a][i]-name[b][i]);

     }	    

return sum;
	  
}


int check(int a,int b)           //function check valaidty
{   
	  int i,sum1=0,sum2=0;
	   
     for(i=0;i<5;i++)
     {
          sum1=sum1+name[a][i];
          sum2=sum2+name[b][i];

     }	 

     if(sum2>sum1)
        return 1;
        else
        return 0;  
    

}

int check_edge(int a,int b)          //function to check edge 
{   
   
   int count=0;
   int i,j;
   char first[1000],second[1000];

    strcpy(first,name[a]);
    strcpy(second,name[b]);

	for(i=0;i<5;i++)
	{

		  for(j=0;j<5;j++)
		  {
                if(first[i]==second[j])
                {    
                	second[j]='@';
                	count++;
                	break;
                }
		  }
	}
      
      if(count==4)
      	return 1;
      else
      	return 0;
}


void floydWarshall ()           //floydwaeshall function
{ 
  
   
    int  i, j, k;
 
        for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
      

    for(k=0;k<V;k++)
    {
       for(i=0;i<V;i++)
        {
            
            for(j=0;j<V;j++)
            {
                 if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }


printf("\n\n-------Final matrix-----\n\n");
 
for(i=0;i<V;i++)
{
	for(j=0;j<V;j++) 
		 {   
              if(dist[i][j]==INF)
              	printf("INF\t");
              else
                   printf("%d\t",dist[i][j]);
		 }
		 printf("\n");
} 

}

void dfs(int u,int a,int b)             //dfs
{
     int i,next;

for(i=0;i<size[u];i++)
	{   
         next = list[u][i];

         if(search(next,u+1))
   	       	 acc[next][size1[next]++]=u+1;
   	     
   	     if(b==u+1)
	     {  
	     	if(search(next,a))
                  acc[next][size1[next]++]=a;
	     }

	     a=u+1;
	     b=next+1;
        
         dfs(next,a,b);
	     
    }
}

int search(int a,int b)           //search function
{
    int i;
  
   for(i=0;i<size1[a];i++)
    {   
    	 if(b==acc[a][i])
    	 	return 0;
    }

  	return 1;
}






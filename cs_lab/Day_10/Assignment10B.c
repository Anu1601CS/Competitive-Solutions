#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define V 8
#define INF 999999

int minarr[100]={0};
int path[100][100];
bool visited[100];
int dist[V][V];
int count=0;
int minI=0;


void floydWarshall(int graph[][V]);
int find(int a,int b);

int main()
{     
	int i;
	 char city[V][10000]={
		                
		         {"MA Chidambaram Stadium, Chennai"},
                         {"Eden Gardens, Kolkata"},
                         {"Holkar Cricket Stadium, Indore"},
                         {"M.Chinnaswamy Stadium, Bengaluru"},
                         {"Vidarbha Cricket Association Ground, Nagpur"},
                         {"JSCA International Stadium Complex, Ranchi"},
                         {"Barsapara Cricket Stadium, Guwahati"},
                         {"Rajiv Gandhi International Stadium, Hyderabad"}
                        
                        };
 
 printf("\nInitially the matches were planned to be held at following cricket stadium in following order by BCCI.\n");
             printf("\nSNo.\tStadium\n");
                     
   for(i=0;i<V;i++)
   	  printf("%d\t%s\n",i+1,city[i]);

   int graph[V][V] = {  {0,1678,1172,284,910,1234,1885,520},
                        {1678,0,1286,1559,980,325,528,1180},
                        {1172,1286, 0,1100,383,973,1697,653},
                        {284,1559,1100,0,925,1415,2075,499},
                        {910,980,383,925,0,891,1392,423},
                        {1234,325,973,1415,891,0,713,973},
                        {1885,528,1697,2075,1392,713,0,2447},
                        {520,1180,653,499,423,973,2447,0}
                      };
 
   floydWarshall(graph);



   int min=INF;
int f=0;
for(i=0;i<V;i++)
  {  
  	  if(min>minarr[i])
  	  {
  	    	min=minarr[i];
  	       	f=i;
      }
  }


  printf("\nSNo.\tStadium\n");
 for(i=0;i<V;i++)
 {
 	printf("%d\t%s\n",i+1,city[path[f][i]]);

 }
 printf("\nWith total distance : %d\n",minarr[f]);
  
    return 0;
}

void floydWarshall (int graph[][V])
{
   int  i, j, k;
   for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];	
 
  for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
           for (j = 0; j < V; j++)
            {
                 if (dist[i][k] + dist[k][j] < dist[i][j])
                      dist[i][j] = dist[i][k] + dist[k][j];
            }     
        }
    }
 

for (i = 0; i < V; i++)
 {  
    	for (j = 0; j < V; j++)
        {     
              if(i==j)
               dist[i][j]=INF; 
        }
        
 }
printf ("\nAfter Changes plan to make the schedule in most economical way.\n\n");
  
 for(i=0;i<V;i++)
  {   
        count=0;
        minI=0;   
    for(j=0;j<V;j++)
	    visited[j]=false; 
   
   path[i][0]=i;
   	find(i,i);
  }



}
 
int find(int a,int b)
{    
     int min=INF;
     int j;
 
 if(count==V-1)	
   	return 0;
  
  for(j=0;j<V;j++)
    	{   
             if( min>=dist[a][j] &&  visited[j]==false )
             {
             	min=dist[a][j];
             	minI=j;
             }
             
    	}

 minarr[b]=minarr[b]+min;
 path[b][count+1]=minI;
 visited[minI]=true;
 visited[b]=true;
 
 ++count;
  
  find(minI,b);

}

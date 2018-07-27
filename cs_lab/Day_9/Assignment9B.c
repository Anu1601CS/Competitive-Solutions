
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>  
#include <stdlib.h>

int V;
int source,target;
 
int maxDistance(double dist[], bool sptSet[]);
int printSolution(double dist[], int n);
void dijkstra(double  graph[V][V], int src);
int Path[1000],p=0;
int c[1000];

 int main()
{   

    int E,v,u,i;
    int j;
    double w;
    printf("Enter number of Vertex :  ");
    scanf("%d",&V);

    double graph[V][V];
    
    printf("Enter Edges: ");
    scanf("%d",&E);
    
   for(i=0;i<V;i++)
    {
      for(j=0;j<V;j++)
         {
          graph[i][j]=0.0;
         }
        
    }
    
  

    
    for(i=0;i<E;i++)  
    {    
         printf("Enter edges pairs(u-->v): ");
         scanf("%d %d",&u,&v);
         printf("Enter there weight : ");
         scanf("%lf",&w);

         graph[u-1][v-1]=w;
    }



    printf("\nEnter The Source: ");
    scanf("%d", &source);
       --source;
    printf("\nEnter The target: ");
    scanf("%d", &target);
    


    dijkstra(graph, source);
  
    return 0;
} 




int maxDistance(double dist[], bool sptSet[])
{
   
   int  max_index,v,i;
   double max= INT_MIN;
   
   for (v = 0; v <V; v++)
     if (sptSet[v] == false && dist[v] >= max)
     {
         max = dist[v], max_index = v;

    

        
     }
   return max_index;
}
  

int printSolution(double dist[], int n)
{    
  int i;
   
   for (i = 0; i <V; i++)
    {   
    	if(target==i+1)
    	
    	{
    	
       if(dist[i]<=1 && dist[i]>=0.0)
       {
       printf("\nPath\tDistance\n");
       printf("%d-->%d\t%.2lf\n",source+1, i+1, dist[i]);
        
        }
        
        else
       printf("Path not Possible\n"); 
     }
}
}
  

void dijkstra(double graph[V][V], int src)
{
     double dist[V];     
  
     bool sptSet[V]; 
  
      int i;
     for (i = 0; i < V; i++)
        dist[i] = INT_MIN, sptSet[i] = false;

     
  
 
     dist[src] = 1;

     int count;
     for (count = 0; count < V-1; count++)
     {

       int u = maxDistance(dist, sptSet);
  
    
       sptSet[u] = true;
    
    int v;
       for (v = 0; v <V; v++)
  
     
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MIN
                                       && dist[u] * graph[u][v] > dist[v])
         {  

            dist[v] = dist[u] * graph[u][v];
            

         }
     }
  

   

  
     printSolution(dist, V);



        
}
  


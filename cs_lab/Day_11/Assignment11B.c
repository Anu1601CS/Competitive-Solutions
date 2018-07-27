#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>


int V;


int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

bool bfs(int rgraph[V][V],int s,int t ,int parent[])
{   
	int i;
    
    bool visited[V];
   for(i=0;i<V;i++)
      visited[i]=false;

    int v;
    int queue[1000];
    int rear=-1;
    int front=-1;

    front=0;
    ++rear;
    queue[rear]=s;
    
    visited[s]=true;
    parent[s]=-1;
    
//bfs
    while(front<=rear)
    {  
    	
        int u=queue[front];
        front++;

        for(v=0;v<V;v++)
        {
        	if(visited[v]==false && rgraph[u][v]>0)
        	{
        		 queue[++rear]=v;
        		 parent[v]=u;
        		 visited[v]=true;
             

        	}
        }

    }
  

return (visited[t]==true);

}


int fordFulkerson(int graph[V][V],int s,int t)
{
        int u,v;
        int rgraph[V][V];

        
        for(u=0;u<V;u++)
        {
             for(v=0;v<V;v++)
             {
             	rgraph[u][v]=graph[u][v];
             }
        }


        int parent[V];
        int max_flow=0;

        while(bfs(rgraph,s,t,parent))
        {  
        	
        	int flow=INT_MAX;
        	
        	for(v=t;v!=s;v=parent[v])
        	{
        		u=parent[v];
        		flow=min(flow,rgraph[u][v]);
        	}

        	for(v=t;v!=s;v=parent[v])
        	{
        		u=parent[v];
        		rgraph[u][v]=rgraph[u][v]-flow;
        		rgraph[v][u]=rgraph[v][u]+flow;
        	}
        	max_flow+=flow;

        }


        return max_flow;


}


int main()
{   
	
  int w,i,j;
  int n;
  printf("Enter a number of Vertices : ");
  scanf("%d",&n);
  V=n+2;
  
  int graph[n+2][n+2];


  for(i=0;i<=n+1;i++)
  {
    for(j=0;j<=n+1;j++)
    {
        graph[i][j]=0;
    }
  }


 for(i=1;i<=n;i++)
 {   
 	 for(j=1;j<=n;j++)
 	 {    
        if(i!=j)
          {
         int check=j-i;
         if(0<check && check<=3)
             graph[i][j]=i+j;
          }   	  
 	 }
     
 }  

     int  s=0;
     int t=n+1;

     for(i=1;i<=n;i++)
     {   
          if(1<=i && i<=n/4)
            graph[0][i]=i; 
           
           if(i>=3*n/4 && i<=n)
               graph[i][t]=i;          

     }

/*
printf("Matrix : \n");

    for(i=0;i<=n+1;i++)
     {
     for(j=0;j<=n+1;j++)
      {
         printf("%d\t",graph[i][j]);
      }
      printf("\n");
     }*/

   printf("\nAns=%d\n",fordFulkerson(graph,s,t));

	return 0;
}






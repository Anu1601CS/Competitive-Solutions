//Name:Anurag
//Roll no:1601CS05

#include<stdio.h>         //decleration of all header files
#include<stdlib.h>
#include<string.h>

int size[500]={0};
int num[500]={0};
int color[500];
int list[500][500];

void dfs(int u,int a);      //decleration of function

//main function

int main()
{
        int i,n,m,u,v,count=1,ans;
        
	printf("Enter the number of vertices: ");  //read number of vertices
	scanf("%d",&n);

	printf("Enter the number of edges: ");   //read number of edges
	scanf("%d",&m);
        
        printf("Enter the edge pairs : \n");   //read edge pairs

        for (i=0;i<m;i++)                     //make adjancey list
	{
		  scanf("%d %d",&u,&v);
		
		  list[u][size[u]++]=v;
		  list[v][size[v]++]=u;
	}
        
        for (i = 1; i <= n;i++)     //color initilazation 
	{color[i]=-1;}
		
	for (i=1;i<=n;i++)     //calling dfs each node
	{
		if (color[i] == -1)
		{
			dfs(i,count++);
		}
	}


	ans=num[1];
	
	for (i = 1;i<=count;i++)   //find max edge
	{    
             if(ans<num[i])
	        ans=num[i];
		  
	}
	

	printf("The maximum number of edges in a single connected component of graph are: %d\n",ans/2);
	return 0;
}

//dfs function

void dfs(int u,int a)
{
        int i,next;
        color[u]=1;     //color node
    
    for (i=0;i<size[u];i++)
	{
	    
	    num[a]++;
            next = list[u][i];
	     
	     if (color[next] == -1)
		      dfs(next,a);
         }
}
















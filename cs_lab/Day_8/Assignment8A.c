//Name:Anurag
//Roll no:1601CS05

#include<stdio.h>    //decleration of all header files 
#include<stdlib.h>

int size[500]={0};  //global variables
int color[500];
int list[500][500];
int check=1;

void dfs(int u,int a);

//main function
int main()
{

	int i,n,m;
	
	printf("Enter the number of Players: ");
	scanf("%d",&n);

        printf("Enter the number of pairs: ");
	scanf("%d",&m);


	printf("Enter the edge pairs one by one: \n");
	int u,v;

        for(i=1;i<=n;i++)   //initilization of color
	{color[i]=-1;}

      	//adjency list
	for(i=0;i<m;i++)
	{
		  scanf("%d %d",&u,&v);
		 
		  list[u][size[u]++]=v;
		  list[v][size[v]++]=u;
	}


  for (i=1;i<=n;i++)   //caling dfs function 
	{
		if (color[i] == -1)
		{
			dfs(i,0);
		}
	}


  if (!check)
	{
		printf("Not, Divide into to Team\n");
	}
	else
	{

		
		printf("Team 1: ");            //print team 1
		for (i=1;i<=n;i++)
		{
			if (color[i]==0)
			{
				printf(" %d ",i);
			}
		}
		printf("\n");
		printf("Team 2: ");                //print team 2
		for (i=1;i<=n;i++)
		{
			if (color[i]==1)
			{
				printf(" %d ",i);
			}
		}
		printf("\n");
	}
	

	
	return 0;
}

//dfs function

void dfs(int u,int a)
{
  int i,next;
      
 if(check!=1)
  {
	return;
  }
    color[u]=a;
   
    for (i=0;i<size[u];i++)
	{
	    next=list[u][i];
		
		if (color[next] == -1)
		{  dfs(next,1-a);}
		else
			if(color[next]==a)
			{
				check=0;
				return;
			}
		
	}
}














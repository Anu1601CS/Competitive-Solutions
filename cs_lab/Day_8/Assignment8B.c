//Name:Anurag
//Roll no:1601CS05

#include<stdio.h>  //decleration of all header files
#include<stdlib.h>
#include<string.h>

int size[500]={0};           //global variables
int color[500];
int list[500][500];
int check=0;
char ch[1000][1000];

void dfs(int u,int start);      //decleartion of function
int check_edge(int a,int b);

int main()               //main function
{
   int i,n,u,v,j;

   printf("Enter the number of words: ");   //enter number of words
      scanf("%d",&n);

   int matrix[n][n];
   for(i=1;i<=n;i++)                       //initilize matrix to 0
	    {
	 	for(j=1;j<=n;j++)
	 	{
	 		matrix[i][j]=0;
	 	}
	    }

    for (i = 1; i <= n; ++i)          //initilize color
	{color[i]=-1;}


    for(i=1;i<=n;i++)
    {
    	printf("Enter %d word : ",i);
    	scanf("%s",ch[i]);
    }


 for(u=1; u<=n; u++)                 //make adjency list
    {

    	 for(v=1; v<=n; v++)
    	 {
    	 	if(v!=u)
    	 	{

               if(u<v)
               {
                  if(check_edge(u,v))
                  {
           	      	list[u][size[u]++]=v;
           	     	matrix[u][v]=1;
                  }
               }
             else
               {
                  if(check_edge(u,v))
                 {

           	     	list[v][size[v]++]=u;
           	     	matrix[u][v]=1;
                 }
               }
             }
        }
    }


for (i=1;i<=n;++i)
	{
	    if (color[i] == -1)
		{
			dfs(i,0);
		}
	}

  if(check)
    printf("\nGRAPH IS CYCLIC\n");
     else
    printf("\nGRAPH IS ACYCLIC\n");

 //print final matrix
printf("\nFinal matrix :\n\n");


   for(i=1;i<=n;i++)
	 {
	 	for(j=1;j<=n;j++)
	 	{
	 		printf("%d ",matrix[i][j]);
	 	}
	 	printf("\n");
	 }




	return 0;
}

//function to check edges

int check_edge(int a,int b)
{

   int count=0;
   int i,j;
   char first[1000],second[1000];

    strcpy(first,ch[a]);
    strcpy(second,ch[b]);

	for(i=1;i<5;i++)
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

//dfs function

void dfs(int u,int start)
{
      int i,next;
      color[u]=1;

	for (i = 0; i < size[u]; ++i)
	{
	      next =  list[u][i];

	   if (color[next] == -1)
		{
	            dfs(next,u);
		}
		else if (next!=start)
		{
			check=1;
			return;
		}

	}
}

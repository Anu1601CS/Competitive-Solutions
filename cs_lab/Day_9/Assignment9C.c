//Name:Anurag
//Roll no:1601CS05


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char name[500][500];
double graph[500][500];   //global variables
double dist[500][500];
bool visited[1000];
double sum[100]; 
int size[100]={0};

int V,E;

#define INF 99999

double min(double a, double b);                 //decletation of fuction
double edit_distance(char a[], char b[]);
void floydWarshall ();

int main()           //main function
{   
	int i,j;
  
	printf("Enter number of Vertices: ");
	scanf("%d",&V);

	printf("\nEnter their names: \n\n");

	for(i=0;i<V;i++)
	{  
		 printf("Enter name %d: ",i+1);
		 scanf("%s",name[i]);

	}



	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			if(i!=j)
				graph[i][j]=INF;
			  else
			  	graph[i][j]=0;
		}
	}



	printf("\nEnter number of Traffic (Edges): ");  //read edges
	scanf("%d",&E); 
    int u,v;
     double temp1,temp2;

    printf("\nEnter Edge and There Traffic : \n\n"); 
       
       for(i=0;i<E;i++)
       	 {        
       	           printf("Enter Edge(u v): ");
       	           scanf("%d %d",&u,&v);

       	      	   printf("Enter Traffic between %d <--> %d : ",u,v);

                  
                   scanf("%lf",&temp1);
                   
                   temp2=edit_distance(name[u-1],name[v-1]);

       	           graph[u-1][v-1] = temp2*temp1;
			       graph[v-1][u-1] = graph[u-1][v-1];	
                   
                   printf("\n");
       	        


       	 }
   


printf("Traffic matrix : \n\n");
for(i=0;i<V;i++)
{
	for(j=0;j<V;j++) 
		 {   
              if(graph[i][j]==INF)
              	printf("INF\t");
              else

		 	  printf("%.2lf\t",graph[i][j]);
		 }
		 printf("\n");
}




   for(i=0;i<V;i++)
   {
   	   visited[i]=false;
   }

   	printf("\n");

floydWarshall();


return 0;
}

double min(double a, double b)      //function to find min
{
	if (a>b)
	{
		return b;
	}
	return a;
}

double edit_distance(char a[], char b[])    //edit distance function
{
	int m,n;
	m = strlen(a);
	n = strlen(b);
	double dp[m+1][n+1];

	int i,j;
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <=n; j++)
		{
			if (i==0)
			{
				dp[i][j] = j;
			}

			else if (j==0)
			{
				dp[i][j]= i;
			}
			else if (a[i-1] == b[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = 1 + min(dp[i][j-1] , min(dp[i-1][j] , dp[i-1][j-1]));
			}
		}
	}
  
  	return dp[m][n];
}


 
void floydWarshall ()           //function to calculate
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


printf("Final matrix: \n\n");
 
for(i=0;i<V;i++)
{
	for(j=0;j<V;j++) 
		 {   
              if(dist[i][j]==INF)
              	printf("INF\t");
              else

		 	  printf("%.2lf\t",dist[i][j]);
		 }
		 printf("\n");
} 

double temp=0.0;

for(i=0;i<V;i++)
{  
	 for(j=0;j<V;j++)
	 {      
	 	  if(i!=j)
	 	  {
	 	   if(dist[i][j]<30.0)
               
               
	 	  	   size[i]++;
           }
            else
            	continue;
      	    

	 }


}

int max=size[0];
int ind;
   
    for (i = 0; i < V; i++)
    {
        if (size[i]>= max)
        {   
        
            max = size[i];
            ind=i;
        }
    }

printf("\nLocation and Delivery: \n\n");

for(i=0;i<V;i++)
{   
	if(dist[ind][i]!=INF)
	{   
		visited[i]=true;
		printf("(Restaurent at Location - %d sends food to location - %d)\n",ind+1,i+1);
	}


}

int count=0;
int un[100];
for(i=0;i<V;i++)
{
   if(visited[i]==false)
   	{   
   		un[count++]=i+1;

    }
}

for(i=0;i<count;i++)
{

if(count==1)
	printf("(Restaurent at Location - %d sends food to location - %d)\n",un[i],un[i]);
 else
 printf("(Restaurent at Location - %d sends food to location - %d)\n",un[0],un[i]);

}
}






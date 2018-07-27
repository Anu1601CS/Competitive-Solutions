//Name:Anurag
//Roll no:1601CS05
//date:13-Nov


#include<stdio.h>            //decleration of all header files
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int V;
char cities[1000][1000];           //decleration of global variables
int size[500]={0};  
int color[500];
int list[500][500];

int check_edge(int a,int b)         //function to check edge
{  
   int count=0,i,j,l1,l2;
   char ch1,ch2,first[1000],second[1000];
   int l;
   
   l1=strlen(cities[a]);
   l2=strlen(cities[b]);

   strcpy(first,cities[a]);
   strcpy(second,cities[b]);
  
  if(l1>l2)
   	l=l1;
   else
   	l=l2;

  for(i=0;i<l;i++)
  { 
    for(j=0;j<l;j++)
      {      
           ch1=tolower(first[i]);
           ch2=tolower(second[j]);
            
            if(ch1==ch2)
                {    
                  second[j]='@';
                  count++;
                  break;
                }
      }
  }
      
if(count>=1)
return 1;
else
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
			else
			{
				dp[i][j] = 1 + min(dp[i][j-1] , min(dp[i-1][j] , dp[i-1][j-1]));
			}
		}
	}
  
  	return dp[m][n];
}


void m(double A1[][V], double A2[][V], double A3[][V])  //helper function
{  
    int i,j,k;
    
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            A3[i][j] = 0;
            for (k = 0; k < V; k++)
                A3[i][j] += A1[i][k]*A2[k][j];
        }
    }
}
 

double get(double graph[][V])
{  
    int i;
    
    double t= 0;
    
    for (i = 0; i < V; i++)
        t += graph[i][i];
        
    return t;
}
 
 
double triangle(double graph[][V])       //function to find a triangle
{
    double arr2[V][V];  
    double arr3[V][V]; 
    
    int i,j;
    
    for (i = 0; i < V; ++i)
     {
        for (j = 0; j < V; ++j)
        {
            arr2[i][j] = arr3[i][j] = 0.0;
         }
     }
    
    m(graph, graph, arr2);
    m(graph, arr2, arr3);
    
    double t= get(arr3);
    
    return t / 6;
}



void dfs(int u)        //dfs
{
  int i,next;
   
   color[u]=1;
   
  for (i=0;i<size[u];i++)
	{
	    next=list[u][i];
	    	
		if (color[next] == -1)
		{
		  dfs(next);
		}
    }
}


int check_visited()       //check visited
{
  int i;
  int flag=1;
  
  for(i=0;i<V;i++)
  {
     if(color[i]==1)
       continue;
       else
       {
         flag=0;
         break;
       }
  }
  
  
  for(i=0;i<V;i++)
     color[i]=-1;
    
  if(flag==1)
    return 1;
    else
    return 0;

}


int main()       //main  function
{

int i,j;

printf("Enter number of cities: ");
scanf("%d",&V);
printf("Enter there names :\n");

double graph[V][V];

for(i=0;i<V;i++)
scanf("%s",cities[i]);

for(i=0;i<V;i++)
{
   for(j=i+1;j<V;j++)
   {   
       if(i!=j)
       {
        
        if(check_edge(i,j))
           {
              
            graph[i][j]=edit_distance(cities[i],cities[j]);
            graph[j][i]=edit_distance(cities[i],cities[j]);
            
                       list[i][size[i]++]=j;
		       list[j][size[j]++]=i;
           }
        
       }
   
   }

}

printf("\n---------Edge matrix-------\n\n");

for(i=0;i<V;i++)
{

  for(j=0;j<V;j++)
  {
      printf("%.2lf\t",graph[i][j]);
  }
  printf("\n");

}


int n;
//connected graph part
for(i=0;i<V;i++)   
	{color[i]=-1;}
int flag=0;



char ch='y';

while(ch=='y')
{
printf("\n--------------Menu------------ \n\n(1): Is the graph connected.?\n(2): Is the graph having triangle.?\n(0): Exit\n"); 
 
 printf("==>");
 scanf("%d",&n);
 
 if(n==1)
 {
  for (i=0;i<V;i++)  
	{
		if (color[i] == -1)
		{    
		      dfs(i);
		      
		      if(check_visited())
		      {
		          flag=1;
		          break;
		      }  
		           
		}
	 }  


if(flag==1)
printf("\nYes ,graph is connected.\n");
else
printf("\nNo , graph is not connected.\n");

}
 else
 if(n==2)
 {
  //Finding triangle part
int c=triangle(graph);

if(c>=1)
printf("\nYes , graph has traingle.\n");
else
printf("\nNo, graph does not have any triangle.\n");
}
 else
 if(n==0)
 {
    return 0;
 }

printf("\nYou want to check more:  (y/n)\n==>");
scanf(" %c",&ch);

}

return 0;
}


















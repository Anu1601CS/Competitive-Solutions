//Name:ANurag
//Roll no:1601CS05

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int V;
char ch[1000][1000];
double boring[100];               //gloabl variables
double totalcost=0.00;
double key[1000];
double t=0.00;
                              
int check_edge(int a,int b);            //decleartion of header files
int cost(char word[]);
void primMST(double graph[V][V]);
int minKey(double key[], bool mstSet[]);

int main()               //main function
{
  int i,j;


printf("Enter the number of House : ");   
      scanf("%d",&V);
 
 double graph[V][V];


 for(i=0;i<V;i++)
    {
      for(j=0;j<V;j++)
          {
          graph[i][j]=0;
          }
    }

      for(i=0;i<V;i++)
    {  
        printf("Enter %d word : ",i+1);
        scanf("%s",ch[i]);

        boring[i]=cost(ch[i]);
        boring[i]/=1.0*strlen(ch[i]);
        key[i]=boring[i];
           
     }
   
   int u,v;  

 for(u=0; u<V; u++)                 
    {    
 
       for(v=1+u; v<V; v++)
       {   
       
           if( check_edge(u,v) ) 
                  {    
                      int c1=cost(ch[u]);
                      int c2=cost(ch[v]);

                       int w = abs( c1 - c2 );
                       
                       graph[u][v]=w;
                       graph[v][u]=w;
                  }
       }
    }     
 
  
 
  primMST(graph);   //calling function
  
 return 0;
}




int check_edge(int a,int b)         //function to check edge
{   
    
    int i,j;
    int count=0;
    
    char first[1000],second[1000];

    strcpy( first,ch[a] );
    strcpy( second,ch[b] );

    int l1=strlen(first);
    int l2=strlen(second);

    if( l1-l2 == 1 || l1-l2 == -1 )
    { 

       for(i=0;i<l1;i++)
            {
                for(j=0;j<l2;j++)
                {      
                    if( first[i]==second[j] )
                    {   
                        second[j]='@';
                         ++count;
                         break;
                    }
                       

                }

            }      
     }


     if(count == l1 || count== l1-1)
      return 1;
        else
      return 0;

}


int cost(char word[])         //function to calculate cost 
{
     int sum = 0, i, len;
    
     len = strlen(word);
    
    for (i=0;i<len;i++)
    {
        sum = sum + word[i];
    }
     
     return sum;

}



int min(double key[], bool visited[])       //funcion to  find minimum
{
   
   int v,min = INT_MAX, min_index;
 
   for (v = 0; v < V; v++)
     if (visited[v] == false && key[v] < min)
          min = key[v], min_index = v;
 
   return min_index;
}
 
 
void primMST(double graph[V][V])             //prims algorithum
{   

    
     int parent[V];   
     bool visited[V];  
     int count,v,i;
      
     for (i = 0; i < V; i++)
     {    
          parent[i] = -1;  
          visited[i] = false;
      }
    
         
   
    
     for (count = 0; count < V-1; count++)
     {
        
        int u = min(key, visited);
 
    
        visited[u] = true;
 
        
        for (v = 0; v < V; v++)
        {
        
          if (graph[u][v] && visited[v] == false && graph[u][v] <  key[v])
          {   
             parent[v]  = u;
             key[v] = graph[u][v];

          
          
          }
          
         
        }
  
   }


printf("\n**Note** Water Supply: Number Denote House names given Above \n");  //print ans

printf("\nSource---->Node   :   Cost\n\n");

for (int i = 0; i < V; i++)
{ 
   if(parent[i]!=-1) 
      printf("    %d---->%d\t  :  %.2lf\n",parent[i]+1,i+1,key[i]);
    else
       printf("    %d---->%d\t  :  %.2lf\n",i+1,i+1,boring[i]);
}

}




 
 


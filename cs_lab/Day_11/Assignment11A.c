//Name:Anurag
//Roll no:1601CS05
//Program : Find shortest path using   Heap to reduce time   

#include<stdio.h>         //Decleration of all header files 
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
#include<time.h>

int size[500]={0};            //global variables
int h,V;
int minv=0;
int minkey=0; 
int pos[10000];
char name[1000][1000];
int home,office;

void printPath(int parent[], int j);

struct graph{
  int next,weight;
};

struct heapnode{
  int v,dist;
};

struct graph list[1000][1000];
struct heapnode arr[1000];

int slope(int a,int b)         //function to find slope
{
int l1,l2;
l1=strlen(name[a]);
l2=strlen(name[b]);
return l2-l1;
} 

int check_edge(int a,int b,int least)          //function to check edge 
{   
   int l1=strlen(name[a]);
   int l2=strlen(name[b]);

   int count=0;
   int i,j;
   char first[1000],second[1000];

    strcpy(first,name[a]);
    strcpy(second,name[b]);

	for(i=0;i<l1;i++)
	{

		  for(j=0;j<l2;j++)
		  {
                if(first[i]==second[j])
                {    
                	second[j]='@';
                	count++;
                	break;
                }
		  }
	}
      
      if(count>=least)
      	return 1;
      else
      	return 0;
}

int cost(int a,int b)              //function to find cost
{    
	   int i,j,sum=0;
     int l1,l2,l;
     
     l1=strlen(name[a]);
     l2=strlen(name[b]);
      
  if(l2>l1)
    l=l2;
     else
    l=l1;
	    
     for(i=0;i<l;i++)
       sum=sum+abs(name[a][i]-name[b][i]);
  return sum;
	  
}

void minheapify(int i)               //function to min heapify heap
{
    int smallest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  

   if (l < h && arr[l].dist < arr[smallest].dist)
         smallest = l;
  
   if (r < h && arr[r].dist < arr[smallest].dist)
        smallest = r;
 
   if (smallest != i)
    {     
        
        pos[arr[smallest].v]=i;
        pos[arr[i].v]=smallest;

         struct heapnode temp;

         temp=arr[i];
         arr[i]=arr[smallest];
         arr[smallest]=temp;
        
         minheapify(smallest);
    }
}

int extractMin()             //function to extract min
{   
    if (h<= 0)
        return 0;
  
    minkey=arr[0].dist;
    minv=arr[0].v;
    arr[0].dist=arr[h-1].dist;
    arr[0].v=arr[h-1].v;
    pos[arr[0].v]=h-1;
    pos[arr[h-1].v]=0;
    h--;
   
    minheapify(0);
}


void dec(int v,int dist)            //functio to decrease value
{
    int i=pos[v];
    arr[i].dist=dist;
    while(i && arr[i].dist < arr[(i-1)/2].dist)
    {
           pos[arr[i].v]=(i-1)/2;
           pos[arr[(i-1)/2].v]=i;

           struct heapnode temp;

           temp=arr[i];
           arr[i]=arr[(i-1)/2];
           arr[(i-1)/2]=temp;

           i=(i-1)/2;
     }
} 


bool isminheap(int v)         //function to check 
{
    if(pos[v] <  h )
    	return true;
     return false;
}


void dijkstra(int src)                      //diskstra Adjancy list heap algorithum
{
    int dist[V];     
    int parent[V];
    int v;
  
    for (v = 0; v < V; ++v)
    {      
    	  parent[v]=-1;
          dist[v] = INT_MAX;
          arr[v].v = v;
          arr[v].dist=dist[v];
          pos[v] = v;
    }
 
  
     arr[src].v = src;
     arr[src].dist= dist[src];
     pos[src]=src;
     dist[src]=0;
    
     dec(src, dist[src]);
     h=V;

    while (h>0)
    {
        extractMin();
        int u = minv; 	
        int i=0;
        int  p = size[u];

        while (i<=p)
        {
            int v = list[u][i].next;
            if (isminheap(v) && dist[u] != INT_MAX && 
                                          list[u][i].weight + dist[u] < dist[v])
            {  

                parent[v]=u;
                dist[v] = dist[u] + list[u][i].weight;
                dec(v, dist[v]);
            }
            
            ++i;
        }
    }
 int i;
 
	printf("\nFrom-->To\t\t\tDistance");
	for (i = 0; i <V; i++)
	{   
		 if(office==i)
		{
          if(dist[i]!=INT_MAX)
			{
		printf("\n%s -> %s \t\t %d\n\nPath : %s ", name[src], name[i], dist[i], name[src]);
		printPath(parent, i);
         	}
         	else
         	 printf("\nPath not Possible\n");		
        }
   }
printf("\n\n");

}


void printPath(int parent[], int j)           //function  to print path  
{
   if (parent[j]==-1)
        return;
   printPath(parent, parent[j]);
   printf(" ---> %s", name[j]);
}

int main()                         //main function
{ 



int i,j,w;
printf("Enter number of locality: ");
scanf("%d",&V);

printf("Enter there names:\n");

for(i=0;i<V;i++)
{ 
    printf("(%d) : ",i+1);
    scanf("%s",name[i]); 
}

printf("\nSelect Home And Office( *NOTE* Only write Serial No. Given Above : \n");
printf("Home :  ");
scanf("%d",&home);
printf("Office: ");
scanf("%d",&office);

 --home;
--office;

int arr[999][999];

int temp;

for(i=0;i<V;i++)
{   
    for(j=0;j<V;j++)
   
     if(i==j)
     continue;
  else
     {   
         temp=slope(i,j);
         if( (temp==1 &&check_edge(i,j,1)) || (temp== 2 && check_edge(i,j,2)) )
          {
              struct graph n;
               w=cost(i,j);
               n.next=j;
               n.weight=w;
               list[i][size[i]++]=n;
               arr[i][j]=cost(i,j);
         
          }
           else
            if( (temp==-1 && check_edge(i,j,1)) || (temp==-2 && check_edge(i,j,2)) )
            {
                

                struct graph n;
                w=cost(i,j);
                n.next=i;
                n.weight=w;
                list[j][size[j]++]=n;
                arr[j][i]=cost(i,j);

            }
            
      }   

}

dijkstra(home);
return 0;
}





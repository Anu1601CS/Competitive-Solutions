//Name:Anurag
//Roll :1601CS05

#include<stdio.h>  //Decleration of all header files
#include<string.h>
#include<ctype.h>
#define INF 999999

int v = 71;
int eindex = 0,vindex=0;           //global variables
int source,sink;
int indeg[100]={0},outdeg[100]={0};

char cities[71][25] = {"Mumbai","Delhi","Bangalore","Hyderabad",
                       "Ahmedabad","Chennai","Kolkata","Surat",
                       "Pune","Jaipur","Lucknow","Kanpur","Nagpur",
                       "Visakhapatnam","Indore","Thane","Bhopal",
                       "Patna","Vadodara","Ghaziabad","Ludhiana",
                       "Coimbatore","Agra","Madurai","Nashik","Faridabad",
                       "Meerut","Rajkot","Varanasi","Srinagar","Aurangabad",
                       "Dhanbad","Amritsar","NaviMumbai","Allahabad","Ranchi",
                       "Howrah","Jabalpur","Gwalior","Vijayawada","Jodhpur",
                       "Raipur","Kota","Guwahati","Chandigarh","Thiruvananthapuram",
                       "Solapur","Tiruchirappalli","Bareilly","Moradabad",
                       "Mysore","Tiruppur","Gurgaon","Aligarh","Jalandhar",
                       "Bhubaneswar","Salem","Warangal","Guntur",
                       "Bhiwandi","Saharanpur","Gorakhpur","Bikaner",
                       "Amravati","Noida","Jamshedpur","Bhilai","Cuttack",
                       "Firozabad","Kochi","Goa"};

struct Edge{
	int flow,capacity;             //sructure
	int from,to;
};

struct Vertex{
	int h,e_flow;
};


struct Edge edges[20000];
struct Vertex vertices[100];

int Capacity(int a,int b)         //find edge capacity
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
            if(first[i]==second[j])
                {    
                  second[j]='@';
                  count++;
                  break;
                }
      }
  }
      
 return 2*count;
}

int check_edge(int a,int b)         //check edge
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
            if(first[i]==second[j])
                {    
                  second[j]='@';
                  count++;
                  break;
                }
      }
  }
      
 if (!count)
  {
  	return 0;
  }

if(l2-l1==1)
	return 1;
  else
  	return 0;
}
                                                       //add edge
void addEdge(int flow,int from,int to,int capacity)
{
	struct Edge p;
	p.flow = flow;
	p.from = from;
	p.to = to;
	p.capacity = capacity;
	edges[eindex++] = p;
}

int min(int a ,int b)
{
  if(a>b)
  	return b;
  else
  	return a;
}

void exceptions()                    //exception case
{
	int i;

	for (i = 0; i < v; ++i)
	{
		if(i==source) 
		   continue;

		if (!indeg[i] && !strcmp(cities[i],"Thiruvananthapuram"))
		{   
			printf("Goa-->%s\n",cities[i]);
			addEdge(0, source, i, 20);
			indeg[i]++;
			outdeg[source]++;
		}		
	}

	for (i = 0; i < v; ++i)
	{
		if (i==sink)
		  continue;
		

		if (!outdeg[i])
		{   
			printf("Tri-->%s\n",cities[i]);
			addEdge(0, i, sink, 20);
			outdeg[i]++;
			indeg[sink]++;
		}
	}
}


void build()               //build graph
{
	int i,j;
	for (i = 0; i < v; ++i)
	{
	   if (!strcmp(cities[i], "Goa"))
		{
			
			continue;
		}

	for (j = 0; j < v; ++j)
		{
			if (j!=i)
			{
			
			if (!strcmp(cities[j],"Thiruvananthapuram"))
			{
				sink = j;
		
				continue;
			}
            
            if (check_edge(i,j))
			{    
				
			
				indeg[j]++;
				outdeg[i]++;
				addEdge(0,i,j,Capacity(i,j));
			}
		    }
	        
	    }

	}

	exceptions();
}



void initialise()               
{
	int i;
	vertices[source].h = v;

	for (i = 0; i < eindex; ++i)
	{
	   if (edges[i].from == source)
		{
			edges[i].flow = edges[i].capacity;
            vertices[edges[i].to].e_flow += edges[i].flow;
			addEdge(-edges[i].flow, edges[i].to,edges[i].from,0);
		}
	}
}

int  Overflow()              //function to find overflow
{
	int i;
	for (i = 0; i < v; ++i)
	{
		if (i==source || i==sink)
		    continue;
	   
	   if (vertices[i].e_flow>0)
		    return i;
	}

	return -1;
}


void updateReverseFlow(int i,int flow)           //function to update reverse flow
{

	int from = edges[i].to , to = edges[i].from;

	int j;
	for (j = 0; j < v; ++j)
	{
		if (edges[j].to == to && edges[j].from == from)
		{
			edges[j].flow -= flow;
			return;
		}
	}

	struct Edge p;
	p.flow = 0;
	p.capacity = flow;
	p.from = from;
	p.to = to;
	edges[eindex++]=p;
}

int push(int u)             
{
	int i;

	for (i = 0; i < eindex; ++i)
	{
		if (edges[i].from == u)
		{
			
			if (edges[i].capacity == edges[i].flow)
			     continue;
			
			if (vertices[u].h> vertices[edges[i].to].h)
			{
				
				int flow = min(edges[i].capacity - edges[i].flow,vertices[u].e_flow);

				vertices[u].e_flow -= flow;
				vertices[edges[i].to].e_flow += flow;

				edges[i].flow += flow;
				updateReverseFlow(i,flow);
				return 1;
			}
		}	
	}
	return 0;
}

void relabel(int from)           //function to relabel 
{
	int max = INF;

	int i;
	for (i = 0; i < eindex; ++i)
	{
		if (edges[i].from == from)
		{
			
	    if (edges[i].flow == edges[i].capacity)
                continue;

      if (vertices[edges[i].to].h < max)
      {
      	max = vertices[edges[i].to].h;

      	vertices[from].h = max + 1; 
      }
		}
	}

}


int getMaxFlow()           //fucntion to find max flow
{
	initialise();

	while(Overflow() != -1)
	{
		int u = Overflow();
       
       if (!push(u))
		 relabel(u);
		
	}

	return vertices[sink].e_flow;
}

void push_relabel()                   
{
	int i,j;
	for (i = 0; i < v; ++i)
	{
		
		for (j = 0; j < eindex; ++j)
		{
	
			if (edges[j].from == source)
			{
				edges[j].flow = edges[j].capacity;

				vertices[edges[j].to].e_flow += edges[j].flow;
			}
		}
		struct Vertex v;
		v.e_flow = 0;
		v.h = 0;
	}

	 build();
}


int main()           //main function
{
  push_relabel();
  int max_flow = getMaxFlow();
  printf("The maximum flow from Goa to Thiruvananthapuram is : %d\n", max_flow);
  return 0;
}

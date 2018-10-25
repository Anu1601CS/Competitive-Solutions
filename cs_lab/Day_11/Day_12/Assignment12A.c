//Name:Anurag
//Roll no:1601CS05

#include<stdio.h>
#include<string.h>     //Decleration of all header files 
#include<ctype.h>
#define N 20

char name[100][100];
int V,flag = 0;                                       //global variables
char jobs[N][50]={       {"Microsoft"},
                         {"Google"},
                         {"Adobe"},
                         {"Mentor Graphics"},
                         {"Synopsis"},
                         {"IBM"},
                         {"Wipro"},
                         {"TCS"},
                         {"CTS"},
                         {"Goldman"},
                         {"Infosys"},
                         {"Candence"},
                         {"Texas Instrument"},
                         {"DRDO"},
                         {"HAL"},
                         {"ISRO"},
                         {"Capgemini"},
                         {"Ushacomm"},
                         {"Ericson"}};



int find(int graph[1000][1000],int u,int seen[], int match[]);               //decleration of function
void  appropiate(int graph[1000][1000]);
int check(int a,int b);
void print(int match[],int placed);

int main()            //main function
{
 
  printf("Enter the number of candidates: ");
  scanf("%d",&V);
  
  printf("Enter the name of candidates : \n");
  int i;
  
  for(i=0;i<V;i++){
    scanf("%s",name[i]);
  }
  
  int graph[1000][1000];    
  

  for(i=0;i<V;i++){
    int j;
    for(j=0;j<19;j++){
    
      if(check(i,j)){
        graph[i][j] = 1;
      }else{
        graph[i][j] = 0;
      }
    }
  }
  
  appropiate(graph);
  
  return 0;
}

int find(int graph[1000][1000],int u,int  visited[], int match[])             //find companies for student
{
  int i;
  
  for(i=0;i<19;i++)
  {
    if(graph[u][i] && !visited[i])
    {
      visited[i] = 1;
      
      if(match[i]<0 || find(graph,match[i],visited,match))
      {
        match[i] = u;
        return 1;
      }
    }    
  }

  return 0;
}


void  appropiate(int graph[1000][1000])
{
  int match[19];
  int i;
  int placed=0;
  
  for(i=0;i<19;i++)
    match[i] = -1;
  
 for(i = 0;i<V;i++)
  {
    int used[19] = {0};
    find(graph,i,used,match);
  }
  

  print(match,placed);

}

void print(int match[],int placed)
{
   
   int i;
    printf("\nCandidates offered a job by the companies are :\n\n");
    for(i=0;i<19;i++)
  {
    if(match[i] != -1)
    {
      
        
      
      flag = 1;
      ++placed;
      printf("%s -> %s\n",jobs[i],name[match[i]]);
    }
  }
  
  if(!flag)
  {
    printf("None of the candidates were offered a job.");
  }


  printf("Total student palced : %d ",placed);

}




int check(int a,int b)         //function to check edge
{    
   int count=0,i,j,l1,l2;
   char ch1,ch2,first[1000],second[1000];

   l1=strlen(name[a]);
   l2=strlen(jobs[b]);
   
   strcpy(first,name[a]);
   strcpy(second,jobs[b]);

  for(i=0;i<l1;i++)
  { 
    for(j=0;j<l2;j++)
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
      
      if(count>=2)
        return 1;
      else
        return 0;
}



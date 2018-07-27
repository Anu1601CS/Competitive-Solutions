//Name:Anurag
//Roll no:1601cs05
//Date:4/8/17


#include <stdio.h>             //decleration of all header files
#include <limits.h>

int m,n;
int dir[100][100];                 //decleration of global variables
int min(int x, int y, int z);

int minCost(int cost[m][n], int m1, int n1);

int main()
{
 
  int move[100],c=0,a,b,i,j;
  printf("\nEnter number of row: ");
  scanf("%d",&m);                                  //read col and row
  printf("Enter number of col: ");
  scanf("%d",&n);
  int cost[m][n];
  
 

 printf("\nEnter a cost for each room:\n");          //read cost of each room
  for(i=0;i<m;i++)
      {
        for(j=0;j<n;j++)
        {
          scanf("%d",&cost[i][j]);
        }
      }

    printf("\nMimimum cost = %d ", minCost(cost, m-1, n-1));   


 a = m-1;
 b = n-1;

  while(dir[a][b] != 0)
  {
    move[c++]=dir[a][b];
    
    if (dir[a][b]==1)
         b--;
      else if (dir[a][b]==2)
         a--;
    else
    {
      a--;
      b--;
    }
  }

   
  printf("\n\nDirection: ");
                                                     //print direction
  for (i = c-1; i >= 0; i--)
  {
  
    if (move[i]==1)
       printf("Rightward->");
     else if (move[i]==2)
       printf("Downwards->");
     else if(move[i]==3)
      printf("Diagonal->");
    
  }

  
   return 0;
}



int minCost(int cost[m][n], int m1, int n1)             //function  to find minimum path
{
     int i, j;
     int tc[m][n],com;
      
     tc[0][0] = cost[0][0];
 
     dir[0][0]=0;                    //direction are stored in this matrix

     for (i=1;i<=m1;i++)
     {
        tc[i][0]=tc[i-1][0]+cost[i][0];
            dir[0][i]=1;
     }
 
    
     for (j=1;j<=n1;j++)
     {
        tc[0][j]=tc[0][j-1]+cost[0][j];
            dir[i][0]=2;
     }
 
    
     for (i=1;i<=m1;i++)
     {
        for (j=1;j<=n1;j++)
        {
            tc[i][j]=min(tc[i-1][j-1],tc[i-1][j],tc[i][j-1]) + cost[i][j];

              com=tc[i][j];
         
             if (com==cost[i][j]+tc[i-1][j])
              dir[i][j] = 2;
             
             else if(com == cost[i][j] + tc[i-1][j-1])
                dir[i][j] = 3;
            
             else if(com == cost[i][j] + tc[i][j-1])
                dir[i][j] = 1;
            

        }
     }
 
     
     return tc[m1][n1];
}
 

int min(int x, int y, int z)
{  
   
   if (x < y)
   {   
      if(x<z)
            
      return x;
        else
      return z;
      
   }
   else
   {   
      if(y<z)
        
          return y;
           else
          return z;
   }
}
 






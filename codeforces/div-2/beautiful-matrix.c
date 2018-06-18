#include<stdio.h>
int main()
{
  int a[100][100],z=0,i,j,x=0,y=0,x1=0,y1=0;

  for(i=0;i<5;i++)
    {
      for(j=0;j<5;j++)
      {
        scanf("%d",&a[i][j]);
      }
      printf("\n");
    }

    for(i=0;i<5;i++)
    {
      for(j=0;j<5;j++)
      {
        if(a[i][j]==1)
        {
          x=i+1;
          y=j+1;
          break;
        }
      }
    }

    x1=abs(3-x);
    y1=abs(3-y);
    z=x1+y1;
    printf("%d\n",abs(z));
    return 0;
}

#include<stdio.h>
int main()
{
	int n,i,m,j,temp;
	int a[100],a1[100],min;

	scanf("%d %d",&n,&m);

	for(i=0;i<m;i++)
	{
    scanf("%d",&a[i]);
	}

  for(i=0;i<m;i++)
  {
    for(j=i+1;j<m;j++)
    {
      if(a[i]>a[j])
      {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    }
  }

  int count=0;

  for(i=0;n<=m;i++)
  {
    a1[i]=a[n-1]-a[i];
    count++;
    n++;
  }

  for(i=0;i<count;i++)
  {
    min = a1[0];

    for ( i = 1 ; i < count ; i++ )
    {
      if ( a1[i] < min)
      {
        min = a1[i];
      }
    }
  }

  printf("%d",min );
  
	return 0;
}

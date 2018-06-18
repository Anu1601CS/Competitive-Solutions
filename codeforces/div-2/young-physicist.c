#include<stdio.h>
int main()
{
	int i,n,sumx=0,sumy=0,sumz=0;
	int x[100],y[100],z[100];
	scanf("%d",&n);

  for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&x[i],&y[i],&z[i]);
    sumx=sumx+x[i];
    sumy=sumy+y[i];
    sumz=sumz+z[i];
  }

  if(sumz==0 && sumy==0 && sumx==0)
  printf("YES");
  else
  printf("NO");

  return 0;
}

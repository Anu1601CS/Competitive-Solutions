#include<stdio.h>
int main()
{
  int b[100],a[100],i,n;
  scanf("%d",&n);

  for(i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    b[a[i]]=i;
  }

  for(i=1;i<=n;i++)
  printf("%d ",b[i]);

  return 0;
}

#include<stdio.h>

int main()
{
  int n,i,count=0;
  int a[1000];

  scanf("%d",&n);

  for(i=0;i<n;i++)
  scanf("%d",&a[i]);

  int mini=a[0],maxm=a[0] ;
 	for(i=1 ; i<n ; i++)
 	{
    if(a[i]<mini)
    {
      count++ ;
      mini=a[i];
    }

    if(a[i]>maxm)
    {
      count++ ;
      maxm=a[i];
    }
  }

   printf("%d",count);
}

#include<stdio.h>
int main()
{
  int i,n,j,a[100],sum=0,sum1=0,count=0,temp=0;
  scanf("%d",&n);

  for(i=0;i<n;i++)
  scanf("%d",&a[i]);

  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(a[i]<a[j])
      {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    }
  }

  for(i=0;i<n;i++)
  sum=sum+a[i];

  sum1=a[0];
  while(sum1<=sum-sum1)
  {
    sum1=sum1+a[++count];
  }

  printf("%d",count+1);
  return 0;
 }

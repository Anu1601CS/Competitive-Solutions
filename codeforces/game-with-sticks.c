#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  int m,n;
  scanf("%d %d",&n,&m);

  if(m==1||n==1)
  {
    printf("Akshat");
    return 0;
  }

  if(m==n)
  {
    if(n%2==0)
    printf("Malvika");
    else
    printf("Akshat");
  }
  else
  if(n>m)
  {
    if(m%2==0)
    printf("Malvika");
    else
    printf("Akshat");
  }
  else

  if(n<m)
  {
    if(n%2==0)
    printf("Malvika");
    else
    printf("Akshat");
  }
  
  return 0;
}

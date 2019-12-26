#include <stdio.h>

int main()
{
  int n,n1;
  int flag,i=0,a[100],j;

  scanf("%d", &n);
  n1=n;

  while(n!=0)
  {
    a[i]=n%10;
    n=n/10;
    i++;
  }

  for(j=0;j<i;j++)
    {
      if(a[j]==4||a[j]==7)
      {
        flag=1;
      }
      else
      {
        flag=0;
        break;
      }
    }

    if(flag)
    printf("YES");
    else
    if(n1%4==0||n1%7==0||n1%47==0||n1%74==0)
    printf("YES");
    else
    printf("NO");

    return 0;
  }

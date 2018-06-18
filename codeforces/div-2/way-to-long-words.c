#include <stdio.h>
#include <string.h>
int main()
{
  char name[100][100];
  int i,n,l=0,a[100],l1=0;

  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    scanf("%s", name[i]);
    l=strlen(name[i]);
    a[i]=l;
  }

  for(i=0;i<n;i++)
  {
    if(a[i]>10)
    {
      l1=a[i]-1;
      printf("%c%d%c\n",name[i][0],a[i]-2,name[i][l1]);
    }
    else
    {
      printf("%s\n",name[i]);
    }
  }
  return 0;
}

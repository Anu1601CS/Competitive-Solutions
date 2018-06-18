#include <stdio.h>
#include <string.h>
int main()
{
  int a;
  char s1[100],s2[100];
  gets(s1);
  gets(s2);
  a=strcmp(strlwr(s1),strlwr(s2));
  printf("%d",a);
  return  0;
}

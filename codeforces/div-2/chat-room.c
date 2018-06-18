#include <stdio.h>
#include <string.h>

int c (char [], char[]);

int main ()
{
  int flag;
  char s1[]="hello", s2[1000];
  gets(s2);

  if (strlen(s1) <= strlen(s2))
  flag = c(s1, s2);
  else
  flag = 0;

  if (flag)
  printf("YES");
  else
  printf("NO");
  return 0;
}

int c(char a[], char b[])
{
  int c, d;
  c = d = 0;

  while (a[c] != '\0')
  {
    while ((a[c] != b[d]) && b[d] != '\0') {
      d++;
    }

    if (b[d] == '\0')
    break;
    d++;
    c++;
  }

  if (a[c] == '\0')
  return 1;
  else
  return 0;
}

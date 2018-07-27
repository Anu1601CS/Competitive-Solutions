//Name:Anurag
//Roll no:1601CS05
//date:21/07/17
//Program :Divide and Conquer rule in Karatsuba algorithm for  multiplication



#include <stdio.h>                                         //decleration of header files
#include <stdlib.h>
#include <string.h>

int makeEquallength(char *a, char *b);                            //decleration of function
char *fun(char *a,char *b, int l, int r);
char *add(char *x, char* y);
long long int multiplySinglebit(char *a, char *b);
long long int multiply(char *ch1, char *ch2);

int main()                   //main function
{

  char str1[100],str2[100];
  long long int result;
  
  printf("\nEnter the first number in Binary: ");                    //read binary number
  scanf("%s",str1);
  printf("\nEnter the second number  in Binary: ");
  scanf("%s",str2);
  result= multiply(str1,str2);
  printf("\nMultiplication of binary number in Decimal: %lld\n\n",result);      //print binary number in decimal

  return 0;
}


long long int multiplySinglebit(char *a, char *b)                           //function when size is 1
{
     return (a[0]-'0')*(b[0]-'0');
}


long long int multiply(char *ch1, char *ch2)                                  //function to find multiplication
{
    int n,a,b;
    long long int A,B,C;
    char *X1,*X2,*Y1,*Y2;
  
  n = makeEquallength(ch1,ch2);
  
  if(n==0) return 0;
  if(n==1) return multiplySinglebit(ch1,ch2);
   
  a = n/2;
  b = n-n/2;
 
  Y1 = (char*)malloc(a);
  Y1 = fun(ch2,Y1,0,a);
  Y2 = (char*)malloc(b);
  Y2 = fun(ch2,Y2,a,n);
  X1 = (char*)malloc(a);
  X1 = fun(ch1,X1,0,a);
  X2 = (char*)malloc(b);
  X2 = fun(ch1,X2,a,n);
  
  A = multiply(X1,Y1);
  B = multiply(X2,Y2);
  C = multiply( add(X1,X2) , add(Y1,Y2) );
  
  return A*(1<<(2*b)) + (C - A - B)*(1<<b) + B;

}



int makeEquallength(char *a, char *b)                   //function to make a equal size of binary number 
{  
   int i,l1,l2;
   l1 = strlen(a);
   l2 = strlen(b);
  
  if(l2>l1)                 //condition when l1<l2
  {
    char c[l1];
    
    for(i=0;i<l1;i++)
      c[i] = a[i];
      
    for(i=0;i<l2-l1;i++)
      a[i] = '0';
      
    for(i=l2-l1;i<l2;i++)
      a[i] = c[i-l2+l1];
   
    return l2;
  }
  
  else if(l1>l2)             //condition when l1>l2
  
  {
   
    char c[l2];
    
    for(i=0;i<l2;i++)
      c[i] = b[i];
      
    for(i=0;i<l1-l2;i++)
      b[i] = '0';
      
    for(i=l1-l2;i<l1;i++)
      b[i] = c[i-l1+l2];
  }
  
  return l1;
}




char *fun(char *a,  char *b,int l, int r)
 {   
    int i;
    
     for(i=l;i<r;i++)
 
        {
         b[i-l] = a[i];
        }
 
     return b;
 }



char *add(char *x, char* y)               //function for addition
{   

  int i;
  char *str,temp;
  int n = makeEquallength(x,y);
  str = (char*)malloc(n+1);
  
  temp = '0';
  
  for(i=n-1;i>=0;i--)
  {
    str[i+1] = x[i] + y[i] - '0' + temp - '0';
    
    if(str[i+1]>='2')
    {
      str[i+1] -= 2;
      temp = '1';
    }
    
    else temp = '0';
  }
  
  if(temp=='0')
  return str+1;
  
  str[0] = temp;
  
  return str;
}











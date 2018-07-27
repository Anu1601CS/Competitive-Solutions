//Name:Anurag
//Roll no:1601CS05
//Date:28/7/17
//performance of quic sort for very long input

#include<stdio.h>                  //decleration of all heder files 
#include<stdlib.h>
#include<math.h>
#include<time.h>

long int n,k,*arr;           //global variables
clock_t c1,c2;
double runtime;

void store_values();                            //decleration of function
long int median(long int r, long int s, long int t);
void swap(long int j, long int k);
long int partition(long int start,long int end,long int pivot_type);
void quickSort(long int start , long int end, long int pivot_type);
void swapFewElements();

int main()            //main  function
{

	srand((unsigned int)time(NULL));         //function to not repet rand value
	
	
	long int k,l;

	k=1;
	

	printf("\nN\t\tPivot-type\t\tRandom\tSorted\tAlmost-sorted\n\n");
	
	
	while(k<=4)
	 {   
	 
	     
	     
	     
	     switch(k)                       //switch case for value of n
	     {
	         case 1:
	         n=10000;
	         break;
	         
	         case 2:
	         n=100000;
	         break;
	         
	         case 3:
	         n=1000000;
	         break;
	         
	         case 4:
	         n=10000000;
	         break;  
	     
	     
	     }
	  
	         
	         arr=(long int*)calloc(n,sizeof(long int));             //allocate size to array

		
		for(l=0;l<4;l++)
		{
		
	
			store_values();             //calling to store values
			 
			
			 if(l==0  && n==1000000 )
			     { 
			    printf("1000000\t\t First\t\t\tTo slow\tTo slow\tTo slow\n");
			     continue;
			     }
			     
			     
			 if(l==2 && n==1000000 )
			     { 
			       printf("1000000\t    MEDIAN OF THREE 1\t\tTo slow\tTo slow\tTo slow\n");
			     continue;
			     }
			     
			 if(l==0  && n==10000000 )
			     { 
			      printf("10000000\t\t First\t\t\tTo slow\tTo slow\tTo slow\n");
			     continue;
			     }
			     
			     
			 if(l==2 && n==10000000 )
			     { 
                            printf("10000000\t    MEDIAN OF THREE 1\t\tTo slow\tTo slow\tTo slow\n");			     
			     continue;
			     }
			     
			
			c1 = clock();
			quickSort(0,n-1,l);               //calling quicksort
			c2 = clock();
			
			runtime = (double)(c2-c1)/(double)CLOCKS_PER_SEC;
			
		
			if(l==0)
			{
				printf("%ld\t\t FIRST\t\t\t%.3f\t",n,runtime);
				
			}
			else if(l==1)
			{
				printf("%ld\t\t RANDOM\t\t\t%.3f\t",n,runtime);
			
			}
			else if(l==2)
		        {
				printf("%ld\t    MEDIAN OF THREE 1\t\t%.3f\t",n,runtime);
				
			}
			else if(l==3)
			{
				printf("%ld\t    MEDIAN OF THREE 2\t\t%.3f\t",n,runtime);
				
			}

			c1 = clock();
			quickSort(0,n-1,l);
			c2 = clock();
			runtime = (double)(c2-c1)/(double)CLOCKS_PER_SEC;
			
			printf(" %.3f\t",runtime);
		
			
			swapFewElements();                  //calling swapfewelement
			
	
			c1 = clock();
			quickSort(0,n-1,l);
			c2 = clock();
			runtime = (double)(c2-c1)/(double)CLOCKS_PER_SEC;
			
			printf(" %.3f\n",runtime);
		
		}
		
		
		k++;
		
	
		printf("\n");
		
		int i;
		for(i=0;i<n;i++)
		   printf("%ld  ",arr[i]);
	}
	

	
	return 0;
}






void store_values()                    //function to store values

{
     int i;
	for(i=0;i<n;i++)
	{
		arr[i] = rand() % 1000000000;
	}
	
}



void quickSort(long int start , long int end, long int pivot_type)                    //function to sort array

{

	if(start < end)
	{
		long int pi = partition(start,end,pivot_type);
	
		quickSort(start,pi-1,pivot_type);
		quickSort(pi+1,end,pivot_type);
	}
	
}






long int partition(long int start,long int end,long int pivot_type)                 //function for partition
{
	long int pivot,random;
	long int r,s,t;
	
	
		if(pivot_type==0 )
		{
			pivot = start;
		}	
		
		else
		
		if(pivot_type==1)
		{
			pivot= start + rand() % (end - start + 1);
                }			
		
		else
		
		if(pivot_type==2)
		{
			r = start;
		 	s = (end-start+1)/2;
			t = end-start;
			
			pivot = median(r,s,t);
		
		}
		
		else
		
		if(pivot_type==3)
		{
			r = (end-start+1)/4;
		 	s = (end-start+1)/2;
			t = 3*(end-start+1)/4;
			
			pivot = median(r,s,t);
	        }
	
		
		swap(pivot,end);
		
		long int k = start-1,j;
		for(j=start;j<end;j++)
		{
			if(arr[j] <= arr[end])
			{
				k++;
				swap(k,j);
			}
		}
		swap(k+1,end);
		return k+1;
}



long int median(long int r, long int s,long  int t)             //function to find median
{
	long int a[3],temp;
	
	a[0]=r;
	a[1]=s;
	a[2]=t;
	
	long int i,j;
	
	 
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<3;j++)
		{
			if(a[i]>a[j])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	
	return a[1];
}



void swap(long int a, long int b)                       //function for swaping 
{
	long int temp;
	
	temp = arr[b];
	arr[b]=arr[a];
	arr[a] = temp;
}




void swapFewElements()              //function to swap few elements
{
	
	long int a1,b1,i,k=n/100;
	
	for(i=0;i<k;i++)
	{
		a1 = rand() %n;
		b1 = rand() %n;
	
		swap(a1,b1);
	}
	
}


















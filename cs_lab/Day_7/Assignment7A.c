//Name :Anurag
//Roll no :1601Cs05
//Date :25/08/17
//Program :Find ith smallest element in Unsorted  Array 

#include<stdio.h>            //Decleration Of All function
#include<limits.h>
#include<stdlib.h>

int partition(int arr[], int l, int r, int k);
void swap(int *a, int *b);
void sort(int arr[],int n);
int kthSmallest(int arr[], int l, int r, int k);
int findMedian(int arr[], int n);


int main()                              //Main function
{     
	  int n,i,k;
	  printf("Enter Number of element: ");          //Read number of Element
	  scanf("%d",&n);
	  int arr[n];
      printf("Enter Array element: ");                 //Read Array elemet
      for(i=0;i<n;i++)
      	scanf("%d",&arr[i]);
      printf("Enter a Kth element Position:  ");           //Read kth Element Position
        scanf("%d",&k);
      printf("kth Smallest is :%d\n",kthSmallest(arr, 0, n-1, k));
	
	return 0;
}



void sort(int arr[],int n)                          //Sort function
{
   int i,j;
        for(i=0;i<n;++i)
       	   {   
       	   	    for(j=i+1;j<n;++j)
       	   	    {
                         if(arr[i]>arr[j])
                         {
                             swap(&arr[i],&arr[j]);
                          }
                }
           }
}




int findMedian(int arr[], int n)              //Function to find median
{
	sort(arr, n);
    return arr[n/2]; 
}


int kthSmallest(int arr[], int low, int high, int k)                    //Function to find Kth smallest element
{
	
	if(k>0 && k<=high-low+1)
	{
		int n = high-low+1; 

		
		int i, median[(n+4)/5];                 //Allocate space to store median

		for (i=0; i<n/5; i++)
			median[i] = findMedian(arr+low+i*5, 5);

		if (i*5 < n) 
		{
			median[i] = findMedian(arr+low+i*5, n%5); 
			i++;
		} 

		
		int medians;

		if(i==1)
		{
			medians=median[i-1];
		}
		else
		{
			medians=kthSmallest(median,0,i-1,i/2);
		}						




		
		int pos = partition(arr, low, high, medians);           //Partition

		
		if (pos-low == k-1)
			return arr[pos];

		if (pos-low > k-1) 
			return kthSmallest(arr, low, pos-1, k);
            else
            return kthSmallest(arr, pos+1, high, k-pos+low-1);
	}


	return INT_MAX;
}

void swap(int *a, int *b)        //FUnction to swap
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int arr[], int l, int r, int x)          //partation function
{

	int i;
	for (i=l; i<r; i++)
		if (arr[i] == x)
		break;
	swap(&arr[i], &arr[r]);

	
	i=l;
	
	for (int j=l; j<=r-1;j++)
	{
		if (arr[j]<=x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	
	swap(&arr[i], &arr[r]);
	return i;
}



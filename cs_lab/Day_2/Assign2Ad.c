//Name:Anurag
//Roll no:1601CS05
//Date:31/8/17
//program to sort array element


#include<stdio.h>    //Deceleration of header files

int arr[100];                //deceleration of all variables 
int size;
int max_index;
int min_index;

void sort(int a,int b);                           //deceleration of all function
void swap_max(int max_index,int a);
void swap_min(int min_index,int b);
void swap(int a,int b);
int max(int low ,int high,int largest);
int min(int low ,int high,int smallest);



int main()                 //main function 
{
    int i;
    printf("Enter a number : ");                //read  size of list
    scanf("%d",&size);
    
    printf("\nEnter a list \n");            //read list 
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
       
       sort(0,size-1);                            //calling of sort function

printf("\nSorted list : \n");                 //print sorted list 

       for(i=0;i<size;i++)
        printf("%d ",arr[i]);
}




void sort(int a,int b)                          //sort function 
{
     int maxi,mini;
     int i;

    if(a<b){

  max_index=a;
  min_index=a;

  maxi=max(a,b,arr[max_index]);              //calling  of max and min function
  mini=min(a,b,arr[min_index]);

//printf("a=%d b=%d max=%d min=%d \n",a,b,maxi,mini);

 

  if(mini==a && maxi==b)                                         //all conditions to swap values
  {
        swap_min(mini,a);
        swap_max(maxi,b);

  }
    else

    if(mini==b && maxi==a)
    {      
          swap(mini,maxi);
      }

    else

    if(mini==a && maxi!=b)
    {
            swap_max(maxi,b);
    } 
     
     else
     
   if(mini!=a  && maxi==b)
   {
            swap_min(mini,a);         
            
   }
     else

    if(mini==b && maxi!=a)
    {
       swap_min(mini,a);
       swap_max(maxi,b);
    }

    else

      if(maxi==a && mini!=b)
          {
         swap_max(maxi,b);
         swap_min(mini,a);  
          }  

   else

    if(mini!=a && maxi!=b) 
     {
       swap_max(maxi,b);
       swap_min(mini,a);  
     }


  
  
 //printf("a=%d,b=%d \n %d %d\n",a,b,mini,maxi);
  
  sort(++a,--b);             //recursive call
  
     }

  


}


int max(int low ,int high,int largest)                //function to maxindex
{

    if(low<=high)
        {
            if(arr[low]>=largest)
            {
                   largest=arr[low];
                    max_index=low;

            }

                low++; 
             max(low,high,largest);
        }

          else

           return max_index;


}



int min(int low ,int high,int smallest)             //function to find  minindex
{

        if(low<=high)
        {
            if(arr[low]<=smallest)
            {
                   smallest=arr[low];
                    min_index=low;

            }

                low++;
             min(low,high,smallest);
        }

          else

           return min_index;


}


void swap_max(int max,int b)                 //function to swap max 
{   
     int temp;
    
    if(max==b)
      return;
     
     else
{
     temp=arr[b];
     arr[b]=arr[max];
     arr[max]=temp;
}

}


void swap_min(int min,int a)      //function to swap min
{
    
    int temp;
    
    if(min==a)
      return;
     
     else
{
     temp=arr[a];
     arr[a]=arr[min];
     arr[min]=temp;
}


}

void swap(int a,int b)        //simple swap
{
   int temp;

   temp=arr[a];
   arr[a]=arr[b];
   arr[b]=temp;

}


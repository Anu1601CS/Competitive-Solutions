//Name:Anurag
//Roll no:1601CS05
//Date:07/08/17
//FIND MAX SUBARRAY SUM


#include<stdio.h>                           //DECELERATION OF HEADER FILES 

int max1=0, max2=0, i=0,arr[100];                         //GLOBAL VARIABLES
int size;
int arr[100];

int max_sum(int ch);

int main()                            //MAIN FUNCTION
{ 
     int max,i;

     printf("ENTER A NUMBER = ");          //READ SIZE
     scanf("%d",&size);

    printf("\nENTER LIST \n");        //READ LIST
     for(i=0;i<size;i++)
     	scanf("%d",&arr[i]);
   

     max = max_sum(arr[0]);
    printf("\nMAX SUM = %d\n",max);         //PRINT MAX
    
    return 0;
}




int max_sum(int ch)                   //FUNCTION TO FIND MAX
{
    
    if(i<size)                           //CONDITION UNTIL PROGRAM RUN
   
    {
        max2 = max2 + ch;
        
        if (max1 < max2)
            max1 = max2;

        if (max2 < 0)
            max2 = 0;
          
          i++;

         max_sum(arr[i]);
    }

    else

    return max1;
}


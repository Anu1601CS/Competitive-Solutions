//Name:Anurag
//Roll no:1601CS05
//Date:7/8/17
//C Program to Perform Binary Search using Recursion

#include <stdio.h>                  //deceleration of all header files
#include<string.h>
#include<stdlib.h>

void search_ace(int [], int, int, int);
void search_des(int [], int, int, int);                                              //deceleration of function

int size;
int main()                 //main function
{
    int num, i;           //deceleration of all variables
    int list[100];

    printf("Enter size of a list: ");           //read size of list
    scanf("%d", &size);
    printf("Enter a sorted list :");
    for(i = 0; i < size; i++)                     //read number
    {
        scanf("%d",&list[i]);

    }

    printf("\n");
    printf("Enter number to search\n");             //read number to search
    scanf("%d", &num);

    if(list[0]<list[1])
    search_ace(list, 0, size, num);           //passing values to search function
     else
    search_des(list, 0, size, num);
}

void search_ace(int list[], int low, int high, int num)            //function to  search number
{
    int mid;             //middle element

    if (low > high)                                  //condition when number not found
    {
        printf("Number not found\n");
        return;
    }

    mid= 2*(high-low)/5+low;                            //calculate mid1 and mid 2


    if (list[mid] == num )
    {
        printf("Number found\n");
            printf("Position = %d",mid+1);
            return;
    }
    else if (list[mid] > num)                      //when number is greater than mid 2
    {
        search_ace(list, low, mid - 1, num);                     //recursive function
    }
    else if (list[mid] < num)                            //when number is greater than mid 2
    {
         search_ace(list, mid + 1, high, num);
    }

}


void search_des(int list[], int low, int high, int num)            //function to  search number
{
    int mid;              //middle element

    if (low > high)                                  //condition when number not found
    {
        printf("Number not found\n");
        return;
    }

                                                   //calculate mid
    mid = 2*(high-low)/5+low;

    if (list[mid] == num)
    {
        printf("Number found\n");
            printf("Position = %d",mid+1);

             return;
    }
    else if (list[mid] < num)                      //when number is greater than mid
    {
        search_des(list, low, mid - 1, num);                     //recursive function
    }
    else if (list[mid] > num)                            //when number is smaller than mid
    {
         search_des(list, mid + 1, high, num);
    }

}

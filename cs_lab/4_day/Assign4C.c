//Name:Anurag
//Roll no:1601CS05
//Date:21/08/17
//Program :  Matrix multiplication of square matrix using divide and conquer 


#include<stdio.h>              //decleration of all header files 
#include<ctype.h>
#include<stdlib.h>

struct node
{
    int arr[100][100];
};


  struct node form1(struct node ar,int a1)    //function of divide matrix in sub matrix and return  
     {

         int i,j;
         struct node a;
           for(i=0;i<a1;i++)
                for(j=0;j<a1;j++)
                     a.arr[i][j]=ar.arr[i][j];

                     return a;

     }


     struct node form2(struct node ar,int a1)  //function of divide matrix in sub matrix and return 
            {
                  int i,j;
                  struct node b;

           for(i=0;i<a1;i++)
                for(j=a1;j<2*a1;j++)
                     b.arr[i][j-a1]=ar.arr[i][j];

                   return b;

            }


     struct node form3(struct node ar,int a1)  //function of divide matrix in sub matrix and return 
            {
                struct node c;
                int i,j;

                for(i=a1;i<2*a1;i++)
                for(j=0;j<a1;j++)
                     c.arr[i-a1][j]=ar.arr[i][j];

                     return c;

            }


     struct node form4(struct node ar,int a1)  //function of divide matrix in sub matrix and return 
            {

            struct node d;
            int i,j;

            for(i=a1;i<2*a1;i++)
                for(j=a1;j<2*a1;j++)
                     d.arr[i-a1][j-a1]=ar.arr[i][j];

                  return d;

            }





   struct node add(struct node m1,struct node m2,int n)   //function to add to matrix 
        {

        int i,j;
        struct node addMatrix;

           for( i=0;i<n;i++)
                for(j=0;j<n;j++)
                     addMatrix.arr[i][j]=m1.arr[i][j]+m2.arr[i][j];

           return addMatrix;
        }





    void printMatrix(struct node a,int a1)      //function to print maxtrix
     {
         int i,j;
           
           printf("\nFinal matrix:\n");
           for(i=0;i<a1;i++)
           {
                for(j=0;j<a1;j++){
                    printf("%d ",a.arr[i][j]);
                 }
                 printf("\n");
           }
     }




    struct node MultiplyRecursive(struct node arr1,struct node arr2,int n)   //recursive function
     {
        struct node ma;
        struct node Aa,Ab,Ac,Ad,Ba,Bb,Bc,Bd;
        struct node a,b,c,d;

           if(n==1)
           {
                ma.arr[0][0]=arr1.arr[0][0]*arr2.arr[0][0];
                return ma;
           }


           else
           {


           Aa=form1(arr1,n/2);                   //all function to call divide matrix function
           Ab=form2(arr1,n/2);
           Ac=form3(arr1,n/2);
           Ad=form4(arr1,n/2);
           Ba=form1(arr2,n/2);
           Bb=form2(arr2,n/2);
           Bc=form3(arr2,n/2);
           Bd=form4(arr2,n/2);



           a=add(MultiplyRecursive(Aa,Ba,n/2),MultiplyRecursive(Ab,Bc,n/2),n/2);  //function to add
           b=add(MultiplyRecursive(Aa,Bb,n/2),MultiplyRecursive(Ab,Bd,n/2),n/2);
           c=add(MultiplyRecursive(Ac,Ba,n/2),MultiplyRecursive(Ad,Bc,n/2),n/2);
           d=add(MultiplyRecursive(Ac,Bb,n/2),MultiplyRecursive(Ad,Bd,n/2),n/2);



            int i,j;

            int a1=n/2;

           for(i=0;i<a1;i++)                  //make a final matrix
                for(j=0;j<a1;j++)
                     ma.arr[i][j]=a.arr[i][j];

           for(i=0;i<a1;i++)
                for(j=0;j<a1;j++)
                     ma.arr[i+a1][j]=c.arr[i][j];

           for(i=0;i<a1;i++)
                for(j=0;j<a1;j++)
                     ma.arr[i][j+a1]=b.arr[i][j];

           for(i=0;i<a1;i++)
                for(j=0;j<a1;j++)
                     ma.arr[i+a1][j+a1]=d.arr[i][j];


             return ma;
     }

     }
 
     int main()                //main function
     {
          int i,j,n;

          struct node A,B,ans;

          printf("Enter a Order of Matrix: \n");
          scanf("%d",&n);


          printf("\nEnter a elements of First matrix: \n");

          for(i=0;i<n;i++)
          {

              for(j=0;j<n;j++)
                scanf("%d",&A.arr[i][j]);
          }

          printf("\nEnter a elements of Second Matrix: \n");

          for(i=0;i<n;i++)
          {

              for(j=0;j<n;j++)
                scanf("%d",&B.arr[i][j]);
          }


   ans=MultiplyRecursive(A,B,n);

    printMatrix(ans,n);


}

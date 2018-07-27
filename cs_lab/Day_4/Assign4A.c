//Name:A21nurag
//Roll no:1601cs05
//Date:21/8/17

#include <stdio.h>                //decleration of all header files 
#include <string.h>
#include <ctype.h>

 
struct hospital               //structure  of patient
{
      char name[999];
      float time;
      int piro;
     
};
   
 int n;                          //decleration of variables
 float t2=8.00;
 int in=0; 

 struct hospital patient[999];                     //node
  
  
 void doctor();                                     //decleration of variables
 int priority(char ch[999],char doc[999]);
 void sort(int index2);
 int index1=0;
 int index2=0;
 
int main()                                       //main function
{
       int i,j,temp2;
       char doc[100],temp3[999];
       int p;
       float temp1;
       int k=0;
       char doc2[100];
       


    printf("\n------Enter a Data------ \n\n");
   
    printf("Enter a name of Doctor = ");                //read doctor name
        
        scanf("%[^\n]%*c",doc);
          
    
    printf("\nEnter a number of patient = ");        //read number of patient
    scanf("%d",&n);
     
 
    
    printf("\nEnter a name and time of patient.  (---IN 10.23 Format---)\n");     

    for(i=0;i<n;i++)                                          //take a input
    {    
          printf("\nEnter  patient %d  details : \n" ,i+1 );
          printf("Enter name : ");
          scanf("\n");
          scanf("%[^\n]%*c",patient[i].name);
          
          p=priority(patient[i].name,doc);
          patient[i].piro=p;

          printf("Enter time :  ");
          scanf("%f",&patient[i].time);
          
 
     }

        for(i=0;i<n;i++)
    {   
       for(j=i+1;j<n;j++)                          //sort according to time
        {
                if(patient[i].time > patient[j].time)

                {
                    temp1=patient[i].time;
                    patient[i].time=patient[j].time;
                    patient[j].time=temp1;


                    temp2=patient[i].piro;
                    patient[i].piro=patient[j].piro;
                    patient[j].piro=temp2;


                    strcpy(temp3,patient[i].name);
                    strcpy(patient[i].name,patient[j].name);
                    strcpy(patient[j].name,temp3);

                }
         }
     }


  doctor(0);      //calling doctor function
  
  printf("\nList of patient:\n");       //print order

    for(i=0;i<n;i++){
        printf("%s  ",patient[i].name);
        printf("%.2f ",patient[i].time);
        printf("%d ",patient[i].piro);
        printf("\n");
        
     }
       
     return 0;
}




int priority(char ch[999],char doc[999])            //function to find priority of each patient
{
    
    int count=0,count2=0, p=0, c=0, d=0, i,j;
    char ch1[100], ch2[100], temp;

    for(i=0;i<strlen(ch);i++)                      //to remove space
    {   
        if(ch[i]==' ')
            continue;

          else
          {
             ch1[c++] = tolower(ch[i]);
          }}
    
    
      for(i=0;i<strlen(doc);i++)
    {   
        if(doc[i]==' ')                       //to remove space
            continue;

          else
          {
             ch2[d++] = tolower(doc[i]);
          }}

    
   for(i=0;i<c;i++)
    {    
        for(j=i+1;j<c;j++)
        {
              if(  ch1[i] > ch1[j] )
              {       
                        temp=ch1[i];
                        ch1[i]=ch1[j];
                        ch1[j]=temp;
               }}}
    
    
    
  for(i=0;i<d;i++)
    {    
        for(j=i+1;j<d-1;j++)
        {
              if(  ch2[i] > ch2[j] )
              {       
                        temp=ch2[i];
                        ch2[i]=ch2[j];
                        ch2[j]=temp;
                               
              }}}  
                         
     
char match=ch1[0],new[100];
    
  new[0]=ch1[0];

   if(c!=0)
   count=1;   

      for(i=0;i<c;i++)
    {     
        if(match==ch1[i])
            continue;
        else
        {    
             new[count]=ch1[i];
             count++;
             match=ch1[i];
        }}   
           
     
      
 char match2=ch2[0], new2[100];
    
 new2[0]=ch2[0];

   if(d!=0)
   count2=1;   

      for(i=0;i<d;i++)
    {     
        if(match2==ch2[i])
            continue;
        else
        {    
             new2[count2]=ch2[i];
             count2++;
             match2=ch2[i];
        }}    
           
    
    
  
     for(i=0;i<count;i++)
         {
            for(j=0;j<strlen(new2);j++)
            {
                
                     if(new[i]==new2[j])
                      p++;

            }}

     return p;

  }




void doctor(int in)             //doctor function
{
         
     if(in<n)
     {
           if(patient[in].time<=t2 )
           { }
           else
           {
             index2=in;
             sort(index2);
             t2=t2+0.10;
           }
          in++;
          doctor(in);
      }
         else
       
       if( patient[--in].time < t2 )
          {
                index2=in+1;
                sort(index2);
           } else
           return;
  }



void  sort(int index2)           //sort accoring to doctor

{     
    int i,j,temp2;
    char temp3[999];
    float temp1;


        for(i=index1; i<index2; i++)
    {
        for(j=i+1; j<index2; j++)
        {
                if(patient[i].piro < patient[j].piro)

                {
                    temp1=patient[i].time;
                    patient[i].time=patient[j].time;
                    patient[j].time=temp1;


                    temp2=patient[i].piro;
                    patient[i].piro=patient[j].piro;
                    patient[j].piro=temp2;


                    strcpy(temp3,patient[i].name);
                    strcpy(patient[i].name,patient[j].name);
                    strcpy(patient[j].name,temp3);

              }}}              
    index1++;
}























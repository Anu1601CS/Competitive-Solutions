//Name:Anurag
//Roll no:1601CS05
//Date:07/08/17
//FIND ODD AND EVEN WORDS



#include<stdio.h>     //DECELERATION OF HEADER FILES
#include<stdbool.h>
#include<string.h>

int i=0,l,j=0,count=0;                        //GLOBAL VARIABLES
char ch[100];
int find(char match);


bool isEvenWord(char ch[100])                 //BOOL FUNCTION
{     

	   int num=0;

      if(l%2!=0)                                    //CONDITION FOR ODD WORDS
         return false;
         else
         {  

             if(i<l)                              //CONDITION UNTIL PROGRAMS RUN
             { 

            num=find(ch[i]);
            
                
                if(num%2!=0)                       //CHECK EVEN OR ODD
                  return false;
                   
                   
                 i++;
                 j=0;
                 count=0;

              return isEvenWord(ch);                     //calling of function
             }

             return true;


          }
          
    


}



int find(char match)                              //function to find number of character
{
     

     if(j<l)
     {
        if(match==ch[j])
          count++;
          
          j++;

         find(match);
     }


     else
     	return count;
    

}





int main()                                      //main function
{
      //char ch[100];
        
      printf("Enter a word \n");
      scanf("%[^\n]%*c",ch);
      l=strlen(ch);
      isEvenWord(ch)? printf("Even word") : printf("Not a Even word");              //terneary operator 
    
}

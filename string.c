#include<stdio.h>

int occurence(char str[] ,char ch)
{    int i,count=0;
 	  for(i=0;str[i]!='\0';i++)
  		 {
       			 if(str[i]==ch || str[i]==ch+32 ||str[i]==ch-32)
      				{
         				count++;
				}
               }
 
           return count;
           
}

       int main()
         {
	     char str[100], ch;
           
  		printf("Enter the string:\n");
                scanf(" %s",str);

                printf("Enter the character to count:");
                 scanf(" %c",&ch);
 
    		printf("Occurence=%d", occurence(str, ch));
      return 0;
}
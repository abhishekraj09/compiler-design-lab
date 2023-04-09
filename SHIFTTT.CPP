
#include<stdio.h>
#include<string.h>
int i,j,k,len;
char s[30],stack[30];
void reduce();
int main()
{
 scanf("%s",s);
 len = strlen(s);
 s[len]='$';
 stack[0]='$';
 for (i=1,j=0;j<len;i++,j++)
 {
  if(s[j]=='a')
  {
   stack[i]=s[j];
   stack[i+1]='\0';
   s[j]=' ';
   printf("\n%s\t%s\tshift->a",stack,s);
   reduce();
  }
  else
  {
   stack[i]=s[j];
   stack[i+1]= '\0';
   s[j]=' ';
   printf("\n%s\t%s\tshift->%c",stack,s,stack[i]);
   reduce();
  }
 }
 if(s[j]=='$')
 {
  reduce();
  if((stack[1]=='E')&&(stack[2]=='\0'))
   printf("\n%s\t%s\tAccept",stack,s);
  else
   printf("\n%s\t%s\tError",stack,s);
 }
 return 0;
}
void reduce()
{
 for(k=1;k<=len;k++)
  if (stack[k]=='a')
  {
   stack[k]='E';
   stack[k+1]='\0';
   printf("\n%s\t%s\tReduce by E->a",stack,s);
  }
 for(k=1;k<=len;k++)
  if(stack[k]=='E'&& stack[k+1]=='+'&& stack[k+2]=='E')
  {
   stack[k]='E';
   stack[k+1]='\0';
   stack[k+2]='\0';
   printf("\n%s\t%s\tReduce by E->E+E",stack,s);
   i=i-2;
  }
 for(k=1;k<=len;k++)
  if(stack[k]=='E'&& stack[k+1]=='*'&& stack[k+2]=='E')
  {
   stack[k]='E';
   stack[k+1]='\0';
   stack[k+2]='\0';
   printf("\n%s\t%s\tReduce by E->E*E",stack,s);
   i=i-2;
  }
 for(k=1;k<=len;k++)
  if(stack[k]=='('&& stack[k+1]=='E'&& stack[k+2]==')')
  {
   stack[k]='E';
   stack[k+1]='\0';
   stack[k+2]='\0';
   printf("\n%s\t%s\tReduce by E->(E)",stack,s);
   i=i-2;
  }
 }




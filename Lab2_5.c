#include<stdio.h>
#include<ctype.h>
#include<stdio.h>

char stack[100];
int top=-1;       
 
push(char elem)
{                       
    stack[++top]=elem;
}
 
char pop()
{                      
    return(stack[top--]);
}
 
int pr(char symbol)
{                 
   // if else if ladder has been designed in accordance of the precedenace of the operator 
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
void main()
{                        
    char infix[100],postfix[100],ch,elem;
    int i=0,k=0;
    printf("Enter Infix Expression : ");
    scanf("%s",infix);
    push('#');
    while( (ch=infix[i++]) != '\0')
    {
        if( ch == '(') push(ch);
        else
            if(isalnum(ch)) postfix[k++]=ch;
            else
                if( ch == ')')
                {
                    while( stack[top] != '(')
                        postfix[k++]=pop();
                    elem=pop();
                }
                else
                {     
                    while( pr(stack[top]) >= pr(ch) )
                        postfix[k++]=pop();
                    push(ch);
                }
    }
    while( stack[top] != '#')     
        postfix[k++]=pop();
    postfix[k]='\0';          
    printf("\nPostfix Expression =  %s\n",postfix);
}
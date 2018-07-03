#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
char stack[20],post[20];
int x=-1,y=-1,l=0,i=0,count=0;


void push(char s)
{
    if(x==19)
    {printf("Stack is full\n");}
    else
    {
    x=x+1;
    stack[x]=s;
    }
}
char pop()
{
    if(x==-1)
    {printf("Stack is Empty\n");return '\0';}
    else
    {
    return stack[x--];
    }
}
int precedance(char c)
{
    if(c=='('){return 1;}
    else if(c=='^'){return 5;}
    else if(c=='/'){return 4;}
    else if(c=='*'){return 4;}
    else if(c=='+'){return 2;}
    else if(c=='-'){return 2;}
    else {return 0;}
}
void check(int i)
{
    if(i==l)
    {
     while(x!=-1)
    {
	y=y+1;
	post[y]=pop();
    }
    }
}
int parenthesis()
{
	if(count==0)
	{
		printf("Fully Parenthesized\n");
		return 0;
	}
	else
	{
		printf("Not fully Parenthesized\n");
		return 1;
	}
}
void intopost(char ch)
{
char c,ch1;
    i=i+1;
    if(isalpha(ch))
    {
	y=y+1;           //alphabets
	post[y]=ch;
    }
    else if(ch=='(')
    {
	count+=1;
	push(ch);
    }
    else if(ch==')')
    {
	count-=1;
	while(ch!='(')
	{
	    ch=pop();
	    if(ch!='(')
	    {
		y=y+1;
		post[y]=ch;
	    }
	}
    }
    else
    {
	if(precedance(ch)>precedance(stack[x]))
	{
	    push(ch);
	}
	else if(precedance(ch)<=precedance(stack[x]))
	{
	    while(precedance(ch)<=precedance(stack[x]))
	    {
		ch1=pop();
		y=y+1;
		post[y]=ch1;
	    }
	    push(ch);
	}
	else
	{}
    }
    check(i);
}
void main()
{

    int i,go;
    char infix[20];
    clrscr();
    printf("Enter the expression:\n");
    gets(infix);
    l=strlen(infix);
    for(i=0;i<strlen(infix);i++)
    {
    intopost(infix[i]);
    }
    go=parenthesis();
    if(go==0)
    {
	printf("Postfix Expression:\n");
	puts(post);
    }
    else
    {}
    getch();

}



#include<stdio.h>
#include<conio.h>

int stack[50],top=-1;

void CreateStack()

{
printf("Stack is Created\n");
top=-1; //Top is not 0
}

void Push(int element)
{
if(top==49)
{
printf("Stack is Full\n");
}
else
{
stack[top+1]=element;
top+=1;
//then change top

}
//First put the element
}

int Pop()
{
int temp; //giving index of popped element
if(top==-1)
{
//Temp varible for
printf("Stack is Empty\n");
return '\0';
}
else
{
temp=top;
top-=1;
return stack[temp];
}

}

int IsEmpty()
{
if(top==-1)
{
return 1;	//Empty
}
else
{
return 0;
}
}

int IsFull()

{

if(top==49)

{

return 1;	//1 for Full

}

else

{

return 0;

}

}

void DisplayTop()

{

if(top==-1)

{

printf("Stack is Empty\n");

}

else

{

printf("Top Element:%d\n",stack[top]);

}

}

void main()

{

int i,c=1,element,result;

clrscr();

while(c)

{

printf("Choose From:\n1.CreateStack\t2.Push\n3.Pop\t\t4.IsEmpty\n");

printf("5.Is Full\t6.DisplayTop\n7.Exit\n");

scanf("%d",&i);

switch(i)

{

case 1:CreateStack();

break;

case 2:

printf("Enter the elment:");

scanf("%d",&element);

Push(element);

break;

case 3:

result=Pop();

if(result=='\0')

{}

else

{printf("Element Popped:%d\n",result);}

break;

case 4:

result=IsEmpty();

if(result==1)

{printf("Stack is Empty\n");}

else if(result==0)

{printf("Stack is Not Empty\n");}

else

{}

break;

case 5:

result=IsFull();

if(result==1)

{printf("Stack is Full\n");}

else if(result==0)

{printf("Stack is not Full\n");}

else

{}

break;

case 6:DisplayTop();

break;

case 7:c=0;

break;

default:printf("Case Not found\n");

}

}

}

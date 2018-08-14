#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5
int CircularQ[SIZE];
int front=-1,rear=-1,count=0;
void createQ()
{
    front=-1;
    rear=-1;
    printf("Queue Created\n");
}
void Enqueue(int data)
{
    //if((front==0 && rear==SIZE-1)||(rear+1==front))
    if(count==SIZE)
    {
        printf("Queue is Full\n");
    }
    else if(front!=0 && rear==SIZE-1)
    {
        rear=0;
        CircularQ[rear]=data;
        count++;
    }
    else if((front==-1) && (rear==-1))
    {
        front=0;
        rear=0;
        CircularQ[rear]=data;
        count++;
    }
    else
    {
        rear+=1;
        CircularQ[rear]=data;
        count+=1;
    }
}
int Dequeue()
{
    int temp;
    //if(front==-1)
    if(count==0)
    {
        printf("Queue is Empty\n");
        return '\0';
    }
    else if(front==rear)
    {
        temp=CircularQ[front];
        CircularQ[front]='\0';
        front=rear=-1;
        count-=1;
        return temp;
    }
    else if(front==SIZE-1)
    {
        temp=CircularQ[front];
        front=0;
        count-=1;
        return temp;
        //count-=1;
    }
    else
    {
        count-=1;
        return CircularQ[front++];
        //count-=1;
    }
}
void DisplayFront()
{
    if(front==-1)
    {
        printf("Queue has no elements\n");
    }
    else
    {
        printf("Front Element:%d\n",CircularQ[front]);
    }
}
void DisplayRear()
{
    if(rear==-1)
    {
        printf("Queue not found\n");
    }
    else
    {
        printf("Rear Element:%d\n",CircularQ[rear]);
    }
}
void Count()
{
    if(count<=0)
    {
        printf("Queue not created\n");
    }
    else
    {
        printf("Count:%d\n",count);
    }
}
void main()
{
int c,i=1,data,result;
clrscr();
while(i)
{
    printf("Choose from:\n1.CreateQ\t2.Enqueue\n3.Dequeue\t4.DisplayFront\n");
    printf("5.DisplayRear\t6.Count\n7.Exit\n");
    printf("Choice No.:");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        createQ();
        break;
        case 2:
        printf("Enter Number:");
        scanf("%d",&data);
        Enqueue(data);
        break;
        case 3:
        result=Dequeue();
        if(result!='\0')
        printf("Deleted Element:%d\n",result);
        break;
        case 4:
        DisplayFront();
        break;
        case 5:
        DisplayRear();
        break;
        case 6:
        Count();
        break;
        case 7:
        i=0;
        break;
        default:
        printf("Choice not found\n");
    }
}
getch();
}

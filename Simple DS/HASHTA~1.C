#include<stdio.h>
#include<conio.h>
#include<string.h>
#define SIZE 10
int s;
struct node
{
    int id;
    int age;
    char name[10];
 
}hashtable[SIZE];
void Insert(int i,char n[],int a)
{
    int index,flag=0,end=0;
    index=i%s;
    if(hashtable[index].id=='\0')
    {
        hashtable[index].id=i;
        strcpy(hashtable[index].name,n);
        hashtable[index].age=a;
    }
    else if(hashtable[index].id!='\0')
    {
        while(index<SIZE)
        {
            index+=1;
            if(hashtable[index].id=='\0')
            {
                hashtable[index].id=i;
                strcpy(hashtable[index].name,n);
                hashtable[index].age=a;
                //break;
                end=1;
                break;
            }
        }
    }
    else if(end==0)
    {
        index=0;
        while(index<SIZE)
        {
            if(hashtable[index].id=='\0')
            {
                hashtable[index].id=i;
                strcpy(hashtable[index].name,n);
                hashtable[index].age=a;
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("Table is Full\n");
        }
    }
    else
    {}
 
}
void Delete(int id)
{
    int i=0,flag=0,a;
    for(i=0;i<SIZE;i++)
    {
        if(hashtable[i].id==id)
        {
            a=hashtable[i].id;
            hashtable[i].id='\0';
            strcpy(hashtable[i].name,'\0');
            hashtable[i].age='\0';
            flag=1;
            s=s-1;
        }
    }
    if(flag==0)
    {
        printf("Id not found\n");
    }
    else if(flag==1)
    {
        printf("Id Deleted:%d\n",a);
    }
    else
    {}
}
void Search(int id)
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        if(hashtable[i].id==id)
        {
            printf("Found At Index:%d\n",i);
            break;
        }
    }
}
void Display()
{
    int i;
    printf("Id\tName\tAge\tHashindex\n");
    printf("--------------------------------\n");
    for(i=0;i<SIZE;i++)
    {
        if(hashtable[i].id!='\0')
        {
            printf("%d",hashtable[i].id);
            printf("\t%s",hashtable[i].name);
            printf("\t%d",hashtable[i].age);
            printf("\t%d",i);
            printf("\n");
        }
        else
        {}
    }
}
void main()
{
 
    int i,c,a;
    char n[10];
    clrscr();
    for(i=0;i<SIZE;i++)
    {
        hashtable[i].id='\0';
    }
    printf("Enter the size of HashArray:");
    scanf("%d",&s);
    i=1;
    while(i)
    {
        printf("Select from:\n");
        printf("1.Insert\t2.Delete\n3.Search\t4.Display\n5.Exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("Enter Id:");
                scanf("%d",&i);
                printf("Enter Name:");
                fflush(stdin);
                gets(n);
                fflush(stdin);
                printf("Enter Age:");
                scanf("%d",&a);
                Insert(i,n,a);
                break;
            case 2:printf("Enter Id:");
                scanf("%d",&i);
                Delete(i);
                break;
            case 3:printf("Enter Id:");
                scanf("%d",&i);
                Search(i);
                break;
            case 4:Display();
                break;
            case 5:i=0;
                break;
            default:printf("Case not found\n");
        }
    }
    //printf("%d",hashtable[2].id);
    getch();
}

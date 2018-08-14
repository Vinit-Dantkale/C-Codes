#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;        //Defined node
}*root='\0',*clist,*newlist,*temp;
 
void createSLL()
{
    int n,i=1,a;
    char choice;
    printf("Create Node?(y/n):");
    fflush(stdin);
    scanf("%c",&choice);
    if(choice!='y')
    {
        printf("Node not created\n");
    }
    while(choice=='y')
    {
        printf("Enter value:");
        scanf("%d",&a);
        if(root=='\0')           //For first node
        {
            clist=(struct node *)malloc(sizeof(struct node));
            clist->data=a;
            root=clist;
            clist->link='\0';//First node link is null
        }
        else                    //For later nodes
        {
            newlist=(struct node *)malloc(sizeof(struct node));
            newlist->data=a;
            clist->link=newlist;
            newlist->link='\0';       //Latest node's link is null
            clist=newlist;
        }
        i++;
        printf("Create Node?(y/n):");
        fflush(stdin);
        scanf("%c",&choice);
    }
}
void InsertBegin()
{
    int a;
    printf("Data:");
    scanf("%d",&a);
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=a;
    temp->link=root;           //Connected to 2nd node
    root=temp;
}
void InsertAfter()
{
    int val,a,count=0;
    if(root=='\0')
    {
        printf("List doesnt exist\n");
    }
    else
    {
        printf("Insert After?:");
        scanf("%d",&val);
        printf("Value:");
        scanf("%d",&a);
        for(clist=root;clist!= '\0';clist=clist->link)
        {
            if(clist->data==val)
            {
                temp=(struct node *)malloc(sizeof(struct node));
                temp->link=clist->link;//Connected to next node
                clist->link=temp;//Connected to previous node
                temp->data=a;
                count++;
            }
            else
            {}
        }
        if(count<=0)
            {
                printf("Search not found\n");
            }
    }
}
void DeleteEnd()
{
    if(root=='\0')
    {
        printf("List not found\n");
    }
    else
    {
        for(clist=root;clist!='\0';clist=clist->link)
        {
            if(clist->link=='\0')
            {
                root='\0'; //For 1 node
                break;
            }
            if(clist->link->link=='\0')
            {
                clist->link='\0';  //2nd last node's link is null
                break;
            }
            else
            {}
        }
    }
}
void Traverse()
{
    if(root=='\0')
        {
            printf("List not found\n");
        }
    else
    {
        printf("List:\n");
        for(clist=root;clist!='\0';clist=clist->link)
            {
                printf("%d\n",clist->data);
            }
    }
}
char display()
    {
        char choice='\0';
        printf("Display List?(y/n):");
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='y')
            {
                Traverse();
            }
        else{}
        printf("Continue?(y/n):");
        fflush(stdin);
        scanf("%c",&choice);
        return choice;
    }
void main()
{
    int a,c=1;
    char choice1='y';
    clrscr();
    restart:;
    while(choice1=='y')
    {
        printf("Choose from:\n");
        printf("1.CreateSLL\t2.InsertBegin\n3.InsertAfter\t4.DeleteEnd\n");
        printf("5.Traverse\n");
        printf("Choice No.:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:createSLL();
                choice1=display();
                break;
            case 2:InsertBegin();
                choice1=display();
                break;
            case 3:InsertAfter();
                choice1=display();
                break;
            case 4:DeleteEnd();
                choice1=display();
                break;
            case 5:Traverse();
                break;
            default:printf("Case not found!!!\n");
        }
 
    }
getch();
}

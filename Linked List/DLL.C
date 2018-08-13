#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
}*root='\0',*clist,*newlist;
int display()
{
    int c;
    printf("Choose from:\n");
    printf("1.CreateDLL\t2.InsertBegin\n3.DeleteElement\t4.DeleteBefore\n");
    printf("5.Traverse\t6.Quit\n");
    printf("Choice No.:");
    scanf("%d",&c);
    return c;
}
void createDLL()
{
    clist='\0';
    printf("Clist=NULL\n");
}
void InsertBegin()
{
    int a;
    printf("Element:");
    scanf("%d",&a);
    if(clist=='\0')
    {
        clist=(struct node *)malloc(sizeof(struct node));
        root=clist;           //for 1st entry
        clist->data=a;
        clist->prev='\0';
        clist->next='\0';
    }
    else
    {
        newlist=(struct node *)malloc(sizeof(struct node));
        root=newlist;
        newlist->next=clist;       //for next entry
        clist->prev=newlist;
        newlist->prev='\0';
        newlist->data=a;
        clist=newlist;
    }
}
void Traverse()
{
    clist=root;
    if(clist=='\0')
    {
        printf("Elements not found\n");
    }
    while(clist!='\0')
    {
        printf("%d\n",clist->data);
        clist=clist->next;
    }
}
void DeleteElement()
{
    int i=0,a;
    clist=root;
    if(root=='\0')
    {
        printf("Elements not found\n");
    }
    else
    {
        printf("Element:");
        scanf("%d",&a);
        while(clist!='\0')
        {
            if(clist->data==a)
            {
                if(clist->prev=='\0')
                {
                    root=clist->next;
                    clist->next->prev='\0';
                }
                clist->prev->next=clist->next;
                clist->next->prev=clist->prev;
                i++;
            }
            else{}
            clist=clist->next;
        }
        if(i<1)
        {
            printf("Element not found\n"); //search unsuccesful
        }
    }
}
void DeleteBefore()
{
    int i=0,a;
    clist=root;
    if(clist->next=='\0'||clist=='\0') //for 1 element and null list
    {
        printf("No element found\n");
    }
    else
    {
        printf("Delete Before:");
        scanf("%d",&a);
        while(clist!='\0')
        {
            if(clist->data==a)
            {
                if(clist->prev=='\0')
                {
                    printf("No elements\n");  //for 1st element in finite list
                }
                else if(clist->prev->prev=='\0')
                {
                    root=clist;
                    clist->prev='\0';  //for 2nd element
                }
                else
                {}
                clist->prev=clist->prev->prev;
                clist->prev->next=clist;
                i++;
            }
            else
            {}
            clist=clist->next;
        }
        if(i<1)
        {
            printf("Element not found\n");
        }
    }
}
void main()
{
    int i=1,a;
    int c;
    clrscr();
    c=display();
    while(i)
    {
        switch(c)
        {
            case 1:createDLL();
            c=display();
            break;
            case 2:InsertBegin();
            c=display();
            break;
            case 3:DeleteElement();
            c=display();
            break;
            case 4:DeleteBefore();
            c=display();
            break;
            case 5:Traverse();
            c=display();
            break;
            case 6:
                {
                    i=0;        //while bceomes false
                };
            break;
            default:printf("Case not found!!!\n");
            c=display();
            break;
        }
    }
}

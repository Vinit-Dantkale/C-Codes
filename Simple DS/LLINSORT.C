#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int n;
struct node
{
	int roll;
	char name[10];
	float gpa;
	struct node *prev,*next;
}*root='\0',*temp;

void read()
{
	struct node *data;
	int i;
	printf("Enter number of students:");
	scanf("%d",&n);
	while(n--)
	{
		data=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter Roll:");
		fflush(stdin);
		scanf("%d",&data->roll);
		printf("Enter Name:");
		fflush(stdin);
		gets(data->name);
		printf("Enter gpa:");
		scanf("%f",&data->gpa);
		if(root=='\0')
		{
			//printf("a\n");
			temp=data;
			root=data;
			data->prev='\0';
			data->next='\0';
		}
		else
		{
			data->prev=temp;
			temp->next=data;
			data->next='\0';
			temp=data;
		}

	}
}

void insertafter(struct node * temp,struct node * current)
{
	if(temp=='\0')
	{
		current->next=root;
		current->prev=root->prev;
		root->prev=current;
		root=current;
	}
	else
	{
		current->next=temp->next;
		current->prev=temp;
		temp->next->prev=current;
		temp->next=current;
	}
}

void deletenode(struct node * temp)
{
	if(temp->next=='\0')
	{
		temp->prev->next='\0';
	}
	else
	{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
	}
}

void with_roll_asc()
{
	struct node *temp1,*current;
	for(temp=root->next;temp!='\0';)
	{
		temp1=temp->prev;
		while((temp1!='\0')&&(temp1->roll>temp->roll))
		{
			temp1=temp1->prev;
		}
		current=temp;
		deletenode(temp);//check whether 1st node middle or last
		temp=temp->next;
		insertafter(temp1,current);//put in proper place
	}
}

void with_gpa_desc()
{
	struct node *temp1,*current;
	for(temp=root->next;temp!='\0';)
	{
		temp1=temp->prev;
		while((temp1!='\0')&&(temp1->gpa<temp->gpa))
		{
			temp1=temp1->prev;
		}
		current=temp;
		deletenode(temp);//check whether 1st node middle or last
		temp=temp->next;
		insertafter(temp1,current);//put in proper place
	}
}
void display()
{
	struct node *curr;
	curr=root;
	printf("\tRoll\tName\tGPA\n");
	printf("\t----------------------\n");
	while(curr!='\0')
	{
		printf("\t%d\t%s\t%f\n",curr->roll,curr->name,curr->gpa);
		curr=curr->next;
	}
}
void main()
{
	float c;
	int choice,i=1;
	clrscr();
	read();
	while(i)
	{
		printf("\nSort Format:\n1.Roll no\t2.gpa\n3.Display\t4.Exit\n");
		scanf("%f",&c);
		choice=(int)c;
		switch(choice)
		{
			case 1:with_roll_asc();
			printf("---Sorted as per Roll number\n---\n");
				break;
			case 2:with_gpa_desc();
			printf("---Sorted as per gpa\n---\n");
				break;
			case 3:display();
				break;
			case 4:i=0;
				break;
			default:printf("Case not found\n");
				break;
		}
	}
	getch();
}

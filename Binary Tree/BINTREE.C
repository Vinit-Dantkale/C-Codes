#include<stdio.h>
#include<conio.h>

struct node
{
	int data;
	struct node *left,*right;
}*root;
void Create()
{
	root='\0';
}

void insert(int d)
{
	struct node *t,*p;  //t for putting newnode,p for parent
	t=(struct node *)malloc(sizeof(struct node));
	t->data=d;
	t->left='\0';
	t->right='\0';
	p=root;
	if(root=='\0')
	{
		root=t;           //check 1st node
	}
	else
	{
		struct node *curr;
		curr=root;   //start with root
		while(curr)
		{                        //find the appropriate node
			p=curr;
			if(t->data>curr->data)
			{
				curr=curr->right;
			}
			else
			{
				curr=curr->left;
			}
		}
		if(t->data>p->data)
		{
			p->right=t;
		}
		else
		{
			p->left=t;
		}
	}
}
void delete(int key)
{
struct node *temp,*parent,*change;
	if(root==NULL)
	{
		printf("Tree has no nodes \n");
	}
	temp=root;
	while(temp->data!=key)
	{
		//printf("A\n");
		if(key>temp->data)
		{
			parent=temp;
			temp=temp->right;
		}
		else if(key<temp->data)
		{
			parent=temp;
			temp=temp->left;
		}
		else
		{}
	}
	if(temp->data==key)
	{
		//0 child
		if((temp->right=='\0')&&(temp->left=='\0'))
		{                                  //for leaf node
			if(parent->right==temp)
			{
				parent->right='\0';
			}
			else if(parent->left==temp)
			{
				parent->left='\0';
			}
			else
			{}
		}
		//1 child
		else if((temp->right=='\0'&&temp->left!='\0')||(temp->left=='\0'&&temp->right!='\0'))
		{
			if(parent->right==temp) //right of parent node
			{
				if(temp->right=='\0')//if right empty then connect left
				{
					parent->right=temp->left;
				}
				else //if left empty then connect right
				{
					parent->right=temp->right;
				}
			}
			else    //left of parent node
			{
				if(temp->right=='\0')
				{
					parent->left=temp->left;
				}
				else
				{
					parent->left=temp->right;
				}
			}
		}
		//2 child
		else if((temp->right!='\0')&&(temp->left!='\0'))
		{
			parent=temp;
			change=temp;
			temp=temp->left;
			while(temp->right!='\0')
			{
				parent=temp;
				temp=temp->right;
			}
			change->data=temp->data;
			if(parent==change)
			{
				change->left='\0';
			}
			else
			{
				parent->right='\0';
			}
		}
		else
		{}
	}
	else
	{
		printf("Data not Found\n");
	}
}
void search()
{
	struct node *curr;
	int flag=0,d;
	printf("Search Element:");
	scanf("%d",&d);
	curr=root;   //start with root
	if(root=='\0'){printf("No Elements in tree\n");}
	while(curr)
	{                        //find the appropriate node
		if(d==curr->data)
		{
			flag=1;
			printf("Element found\n");
			break;
		}
		else if(d>curr->data)
		{
			curr=curr->right;
		}
		else if(d<curr->data)
		{
			curr=curr->left;
		}
		else{}
	}
	if(flag==0)
	{
		printf("Element not found\n");
	}
}
void Traverse(struct node *tra)
{
	if(root=='\0'){printf("No elements in tree\n");}
	if(tra!='\0')
	{
		Traverse(tra->left);
		printf("%d ",tra->data);
		Traverse(tra->right);
	}
}
void main()
{
	int c,i=1,temp;
	clrscr();
	while(i)
	{
	printf("Choose from:\n");
	printf("1.Create\t2.Insert\n");
	printf("3.Search\t4.Traverse\n5.Delete\t6.Exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			Create();
			printf("Binary Tree Created\n");
			break;
		case 2:
			printf("Enter value:");
			scanf("%d",&temp);
			insert(temp);
			break;
		case 3:
			search();
			break;
		case 4:
			Traverse(root);
			break;
		case 5:
			printf("Delete Value:");
			scanf("%d",&temp);
			delete(temp);
			break;
		case 6:
			i=0;
			break;
		default:printf("Case not found\n");
	}
	}
	getch();
}

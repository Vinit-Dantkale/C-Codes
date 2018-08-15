#include<stdio.h>
#include<conio.h>
#define MAX 20
int v,e,queue[10],front,rear,mat[10][10];
struct Vertex
{
    int data;
    int visit;
}vertex[10];
void CreateQueue()
{
    front=rear=-1;
}
void Enqueue(int ele)
{
    if(rear==MAX-1)
    {printf("Queue is full\n");}
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=ele;
    }
    else
    {
        queue[++rear]=ele;
    }
}
int IsEmpty()
{
    if(front==-1)
    {return 0;}
    else
    {return 1;}
}
int IsFull()
{
    if(rear==MAX-1)
    {return 1;}
    else
    {return 0;}
}
 
int Dequeue()
{
    int temp;
    if(front==-1)
    {printf("Queue is Empty\n");}
    else if(front==rear)
    {
        temp=queue[front];
        front=rear=-1;
    }
    else
    {
        temp=queue[front];
        front+=1;
    }
    return temp;
}
int findelement(int ele)
{
    int i,index=-1;
    for(i=0;i<10;i++)
    {
        if(vertex[i].data==ele)
        {
            index=i;
        }
    }
    return index;
}
            
void bfs(int vi)
{
    int index,temp,temp1,i,j;
    
    CreateQueue();
    index=findelement(vi);
    vertex[index].visit=1;
    temp=vertex[index].data;
    Enqueue(temp);
    printf("%d",vertex[index].data);
    while(IsEmpty())
    {
        temp1=Dequeue();
        j=findelement(temp1);
        for(i=0;i<v;i++)
        {
            if(mat[j][i]==1&&vertex[i].visit==0)
            {
                temp=vertex[i].data;
                Enqueue(temp);
                vertex[i].visit=1;
                printf("->%d",vertex[i].data);
            }
        }
    }
}
void main()
{
 
    int i,j,c,k,n;
    int t;
    clrscr();
    printf("Number of vertices:");
    scanf("%d",&v);
    printf("Number of Edges:");
    scanf("%d",&e);
    printf("Enter vertices:");
    for(i=0;i<v;i++)
    {
        scanf("%d",&vertex[i].data);
        vertex[i].visit=0;
    }
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            mat[i][j]=0;
        }
    }
    for(i=0;i<v;i++)
    {
        printf("Number of edges for vertex %d:",vertex[i].data);
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            printf("Vertex connected to edge %d:",j);
            scanf("%d",&c);
            for(k=0;k<v;k++)
            {
                if(c==vertex[k].data)
                {
                    mat[i][k]=1;
                    mat[k][i]=1;
                    goto here;
                }
            }
            here:;
        }
    }
    printf("Adjacency Matrix is:\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("Enter element to start:");
    scanf("%d",&t);
    bfs(t);
getch();
}

#include<stdio.h>
#include<stdlib.h>
#define MAX 30
 
typedef struct dequeue
{
	int data[MAX];
	int right,left;
}dequeue;
 
void initialize(dequeue *p);
int empty(dequeue *p);
int full(dequeue *p);
void enqueueR(dequeue *p,int x);
void enqueueL(dequeue *p,int x);
int dequeueL(dequeue *p);
int dequeueR(dequeue *p);
void print(dequeue *p);
 
void main()
{
	int i,x,op,n;
	dequeue q;
	
	initialize(&q);
	
	do
	{
		printf("\n1.Create\n2.Push(right)\n3.Push(left)\n4.Delete(right)\n5.Delete(left)\n6.Print\n7.Exit\n\nEnter your choice:");
		//printf("");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1: printf("\nEnter number of elements:");
					scanf("%d",&n);
					initialize(&q);
					printf("\nEnter the data:");
					
					for(i=0;i<n;i++)
					{
						scanf("%d",&x);
						if(full(&q))
						{
							printf("\nQueue is full!!");
							exit(0);
						}
						enqueueR(&q,x);
					}
					break;
					
			case 2: printf("\nEnter element to be inserted:");
					scanf("%d",&x);
							
					if(full(&q))
					{
						printf("\nQueue is full!!");
						exit(0);
					}
					
					enqueueR(&q,x);
					break;
							
			case 3: printf("\nEnter the element to be inserted:");
					scanf("%d",&x);
							
					if(full(&q))
					{
						printf("\nQueue is full!!");
						exit(0);
					}
					
					enqueueL(&q,x);
					break;
							
			case 4: if(empty(&q))
					{
						printf("\nQueue is empty!!");
						exit(0);
					}
							
					x=dequeueR(&q);
					printf("\nElement deleted is %d\n",x);
					break;
					
			case 5: if(empty(&q))
					{
						printf("\nQueue is empty!!");
						exit(0);
					}
							
					x=dequeueL(&q);
					printf("\nElement deleted is %d\n",x);
					break;
							
			case 6: print(&q);
					break;
					
			default: break;
		}
	}while(op!=7);
}
 
void initialize(dequeue *P)
{
	P->right=-1;
	P->left=-1;
}
 
int empty(dequeue *P)
{
	if(P->right==-1)
		return(1);
	
	return(0);
}
 
int full(dequeue *P)
{
	if((P->right+1)%MAX==P->left)
		return(1);
	
	return(0);
}
 
void enqueueR(dequeue *P,int x)
{
	if(empty(P))
	{
		P->right=0;
		P->left=0;
		P->data[0]=x;
	}
	else
	{
		P->right=(P->right+1)%MAX;
		P->data[P->right]=x;
	}
}
 
void enqueueL(dequeue *P,int x)
{
	if(empty(P))
	{
		P->right=0;
		P->left=0;
		P->data[0]=x;
	}
	else
	{
		P->left=(P->left-1+MAX)%MAX;
		P->data[P->left]=x;
	}
}
 
int dequeueL(dequeue *P)
{
	int x;
	
	x=P->data[P->left];
	
	if(P->right==P->left)	//delete the last element
		initialize(P);
	else
		P->left=(P->left+1)%MAX;
	
	return(x);
}
 
int dequeueR(dequeue *P)
{
	int x;
	
	x=P->data[P->right];
	
	if(P->right==P->left)
		initialize(P);
	else
		P->right=(P->right-1+MAX)%MAX;
		
	return(x);
}
 
void print(dequeue *P)
{
	if(empty(P))
	{
		printf("\nQueue is empty!!");
		exit(0);
	}
	
	int i;
	i=P->left;
	
	while(i!=P->right)
	{
		printf("\n%d",P->data[i]);
		i=(i+1)%MAX;
	}
	
	printf("\n%d\n",P->data[P->right]);
}
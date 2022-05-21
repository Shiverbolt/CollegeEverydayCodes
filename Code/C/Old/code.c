#include<stdio.h>
#include<stdlib.h>
#define MAX 50
 
struct node
{
        struct node *lchild;
        int info;
        struct node *rchild;
};
 
struct node *search_nrec(struct node *root, int skey);
struct node *insert_nrec(struct node *root, int ikey );
void display(struct node *ptr,int level);
 
 
int main( )
{
        struct node *root=NULL, *ptr;
        int choice,k;
 
        while(1)
        {
                printf("\n");
                printf("1.Search\n");
                printf("2.Insert\n");
                printf("3.Display\n");
                printf("4.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);
 
                switch(choice)
                {
 
                case 1:
                        printf("\nEnter the key to be searched : ");
                        scanf("%d",&k);
                        ptr = search_nrec(root, k);
                        if(ptr==NULL)
                                printf("\nKey not present\n");
                        else
                                printf("\nKey present\n");
                        break;
 
                case 2:
                        printf("\nEnter the key to be inserted : ");
                        scanf("%d",&k);
                        root = insert_nrec(root, k);
                        break;
 
        case 3:
                        printf("\n");
                        display(root,0);
                        printf("\n");
                        break;
 
                case 4:
                        exit(1);
 
                default:
                        printf("\nWrong choice\n");
                }/*End of switch*/
        }/*End of while */
 
        return 0;
 
}/*End of main( )*/
 
struct node *search_nrec(struct node *ptr, int skey)
{
        while(ptr!=NULL)
        {
                if(skey < ptr->info)
                        ptr = ptr->lchild; /*Move to left child*/
                else if(skey > ptr->info)
                        ptr = ptr->rchild;  /*Move to right child */
                else    /*skey found*/
                        return ptr;
        }
        return NULL;
}/*End of search_nrec()*/
 
struct node *insert_nrec(struct node *root, int ikey)
{
        struct node *tmp,*par,*ptr;
 
        ptr = root;
        par = NULL;
 
        while( ptr!=NULL)
        {
                par = ptr;
                if(ikey < ptr->info)
                        ptr = ptr->lchild;
                else if( ikey > ptr->info )
                        ptr = ptr->rchild;
                else
                {
                        printf("Duplicate key");
                        return root;
                }
        }
 
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=ikey;
        tmp->lchild=NULL;
        tmp->rchild=NULL;
 
        if(par==NULL)
                root=tmp;
        else if( ikey < par->info )
                par->lchild=tmp;
        else
                par->rchild=tmp;
 
        return root;
}/*End of insert_nrec( )*/
 
 
void display(struct node *ptr,int level)
{
        int i;
        if(ptr == NULL )/*Base Case*/
                return;
        else
    {
                display(ptr->rchild, level+1);
                printf("\n");
                for (i=0; i<level; i++)
                        printf("    ");
                printf("%d", ptr->info);
                display(ptr->lchild, level+1);
        }
}/*End of display()*/
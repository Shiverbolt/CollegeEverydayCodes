#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  
  
void insert_begin ();
void display();    
void insert_end ();  
void delete_begin();  
void delete_end();   
void main ()  
{  
    int op =0;  
    while(op != 7)   
    {  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Display\n6.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&op);  
        switch(op)  
        {  
            case 1:  
            insert_begin();      
            break;  
            case 2:  
            insert_end();         
            break;  
            case 3:  
            delete_begin();       
            break;  
            case 4:  
            delete_end();        
            break;    
            case 5:  
            display();        
            break;  
            case 6:  
            exit(0);  
            break;  
            default:  
            printf("Sike! Try again");  
        }  
    }  
}  
void insert_begin()  
{  
    struct node *ptr,*temp;   
    int val;   
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else   
    {  
        printf("\nEnter the node data?");  
        scanf("%d",&val);  
        ptr -> data = val;  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;  
        }  
        else   
        {     
            temp = head;  
            while(temp->next != head)  
                temp = temp->next;  
            ptr->next = head;   
            temp -> next = ptr;   
            head = ptr;  
        }   
        printf("\nnode inserted\n");  
    }  
              
}  
void insert_end()  
{  
    struct node *ptr,*temp;   
    int val;  
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
        printf("\nEnter Data: ");  
        scanf("%d",&val);  
        ptr->data = val;  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;    
        }  
        else  
        {  
            temp = head;  
            while(temp -> next != head)  
            {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;  
        }  
          
        printf("\nNode inserted\n");  
    }  
  
}  
  
void delete_begin()  
{  
    struct node *ptr;   
    if(head == NULL)  
    {  
        printf("\nUNDERFLOW");    
    }  
    else if(head->next == head)  
    {  
        head = NULL;  
        free(head);  
        printf("\nNode deleted\n");  
    }  
      
    else  
    {   ptr = head;   
        while(ptr -> next != head)  
            ptr = ptr -> next;   
        ptr->next = head->next;  
        free(head);  
        head = ptr->next;  
        printf("\nNode deleted\n");  
  
    }  
}  
void delete_end()  
{  
    struct node *ptr, *preptr;  
    if(head==NULL)  
    {  
        printf("\nUNDERFLOW");  
    }  
    else if (head ->next == head)  
    {  
        head = NULL;  
        free(head);  
        printf("\nNode deleted\n");  
  
    }  
    else   
    {  
        ptr = head;  
        while(ptr ->next != head)  
        {  
            preptr=ptr;  
            ptr = ptr->next;  
        }  
        preptr->next = ptr -> next;  
        free(ptr);  
        printf("\nNode deleted\n");  
  
    }  
}  
  
/*void search()  
{  
    struct node *ptr;  
    int val,i=0,flag=1;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter val which you want to search?\n");   
        scanf("%d",&val);  
        if(head ->data == val)  
        {  
        printf("val found at location %d",i+1);  
        flag=0;  
        }  
        else   
        {  
        while (ptr->next != head)  
        {  
            if(ptr->data == val)  
            {  
                printf("val found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        }  
        if(flag != 0)  
        {  
            printf("val not found\n");  
        }  
    }     
          
}*/  
  
void display()  
{  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nNothing here:c");  
    }     
    else  
    {  
        printf("\nThe values are:\n");  
          
        while(ptr -> next != head)  
        {  
          
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  
    }  
              
}  
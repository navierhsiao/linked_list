#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int val;
    struct node *next;
};

void list_append(struct node *head,int value)
{
    struct node *current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=(struct node*)malloc(sizeof(struct node));
    current=current->next;
    current->val=value;
    current->next=NULL;
}

void list_remove(struct node *head,int value)
{
    struct node *current=head;
    while(current!=NULL)
    {
        current=current->next;
    }
}

void list_insert(struct node *head,int front_value,int value)
{
    
}

void list_sort(struct node *head)
{
    
}



void list_show(struct node *head)
{
    struct node *current=head;
    printf("value = ");
    while(current!=NULL)
    {
        printf("%d ",current->val);
        current=current->next;
    }
    printf("\n");
}


int main() {
    
    printf("linked list test\n");
    struct node *list_head=NULL;
    
    while(1)
    {
        char input[50];
        printf("input = ");
        scanf("%s",input);
        
        if(!strcmp(input,"a"))
        {
            int val=0;
            printf("value = ");
            scanf("%d",&val);
            if(!list_head)
            {
                list_head=(struct node*)malloc(sizeof(struct node));
                list_head->val=val;
                list_head->next=NULL;
            }
            else
            {
                list_append(list_head,val);
            }
        }
        else if(!strcmp(input,"i"))
        {
            
        }
        else if(!strcmp(input,"r"))
        {
            
        }
        else if(!strcmp(input,"pb"))
        {
            
        }
        else if(!strcmp(input,"st"))
        {
            
        }
        else if(!strcmp(input,"sh"))
        {
            if(list_head)
            {
                list_show(list_head);
            }
            else
            {
                printf("empty list \n");
            }
        }
        else if(!strcmp(input,"ext"))
        {
            break;
        }
        else if(!strcmp(input,"clr"))
        {
            
        }
    }
    
    printf("exit\n");
    return 0;
}
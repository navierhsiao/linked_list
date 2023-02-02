#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int val;
    struct node *next;
};

struct node *list_swap(struct node *head,int value1,int value2)
{
    struct node *new_head=head;
    struct node *current=head;
    struct node *prev=NULL;

    struct node *node1_prev=NULL;
    struct node *node2_prev=NULL;
    struct node *node1=NULL;
    struct node *node2=NULL;
    struct node *temp=NULL;

    if(head==NULL||(value1==value2))
    {
        return new_head;
    }
    
    while(current!=NULL)
    {
        if(current->val==value1)
        {
            if(!node1)
            {
                node1_prev=prev;
                node1=current;
            }
            else
            {
                node2_prev=prev;
                node2=current;
            }
        }
        else if(current->val==value2)
        {
            if(!node1)
            {
                node1_prev=prev;
                node1=current;
            }
            else
            {
                node2_prev=prev;
                node2=current;
            }
        }

        prev=current;
        current=current->next;
    }

    if(!node1||!node2)
    {
        printf("Input value not found!\n");
        return new_head;
    }
    else if(node1&&node2)
    {
        printf("Both values are found!\n");
        printf("node1 = %d node2 = %d\n",node1->val,node2->val);
       
        if(!node1_prev||!node2_prev)
        {
            if(!node1_prev)
            {
                new_head=node2;
                temp=node2->next;
                if(node2_prev!=node1)
                {
                    node2_prev->next=node1;
                    node2->next=node1->next;
                }
                else
                {
                    node2->next=node1;
                }
                node1->next=temp;
            }
            else if(!node2_prev)
            {
                new_head=node1;
                temp=node2->next;
                if(node1_prev!=node2)
                {
                    node1_prev->next=node2;
                    node1->next=node2->next;
                }
                else
                {
                    node1->next=node2;
                }
                node2->next=temp;
            }
        }
        else if(node1_prev&&node2_prev)
        {
            node1_prev->next=node2;
            temp=node2->next;
            if(node1==node2_prev||node2==node1_prev)
            {
                node2->next=node1;    
            }
            else
            {
                node2_prev->next=node1;
                node2->next=node1->next;
            }
            node1->next=temp;
        }
    }

    printf("Swap finished!\n");
    return new_head;
}

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
    struct node *new_head=head;
    struct node *current=head;
    while(current!=NULL)
    {
        current=current->next;
    }
}

void list_insert(struct node *head,int front_value,int value)
{
    
}

struct node *list_sort(struct node *head)
{
    struct node *new_head=head;
    int flag=0;
    while(1)
    {
        struct node *current=new_head;
        flag=1;
        while(current->next!=NULL)
        {
            if(current->val>current->next->val)
            {
                flag=0;
                new_head=list_swap(new_head,current->val,current->next->val);
            }
            else
            {
                current=current->next;
            }
        }

        if(flag==1)
        {
            break;
        }
    }

    printf("list sorting finished!\n");
    return new_head;
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

int list_search(struct node *head,int value)
{
    struct node *current=head;
    int count=0;
    while(current!=NULL)
    {
        if(current->val==value)
        {
            return count;
        }
        current=current->next;
        count++;
    }

    return -1;
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
            list_head=list_sort(list_head);
        }
        else if(!strcmp(input,"sw"))
        {
            int val1=0,val2=0;
            printf("input 2 value = ");
            scanf("%d %d",&val1,&val2);
            if(list_head)
            {
                list_head=list_swap(list_head,val1,val2);
            }
            else
            {
                printf("empty list \n");
            }
        }
        else if(!strcmp(input,"s"))
        {
            int val=0;
            printf("value = ");
            scanf("%d",&val);
            if(list_head)
            {
                int pos=list_search(list_head,val);
                if(pos==-1)
                {
                    printf("Value %d doesn't exit \n",val);
                }
                else
                {
                    printf("The position of Value %d is %d\n",val,pos);
                }
            }
            else
            {
                printf("empty list \n");
            }
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
        else
        {
            printf("command error\n");
        }
    }
    
    printf("exit\n");
    return 0;
}
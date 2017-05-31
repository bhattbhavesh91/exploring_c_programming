/*
Menu Driven Code for Linked List
Bhavesh Bhatt


struct ll_core
{
    char c_ll;
    struct ll_core * next;
};

printf("size of struct ll_core = %d\n\n",sizeof(struct ll_core));


Assuming you are running your code on 32 bit machine, size of pointer will be 4 bytes. As structure will be aligned on word boundary, 3 bytes will be padded and so the size will be 8 bytes.

this structure will actually be like,

struct ll_core{
    char       c_11:
    char const byte[3];  //padded bytes for alignment reasons
    struct ll_core *next;
};

*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* link;
} node;

typedef struct node* node_ptr;

void add_at_end(node_ptr* head)
{
    int data;
    printf("\nEnter the data value for the node\n");
    scanf("%d",&data);
    node_ptr temp = *head;
    node_ptr new_node = (node_ptr)malloc(sizeof(node));
    new_node -> data = data;
    new_node -> link = NULL;

    if (*head == NULL)
        {
            *head = new_node;
             return;
        }

        while(temp -> link != NULL)
            temp = temp -> link;

        temp -> link = new_node;
        return;
}

void print_LL(node_ptr head)
{
    if (head == NULL)
        printf("\nList is Empty\n");

    else
    {
        printf("\nContent of the Linked List is \n");
        while(head!=NULL)
            {
                printf("%d ",head->data);
                head = head -> link;
            }
        printf("\n");
    }
}
void add_at_begin(node_ptr *head)
{
    node_ptr new_node = (node_ptr)malloc(sizeof(node));
    int data;
    printf("\nEnter the data value for the node\n");
    scanf("%d",&data);
    new_node -> data = data;
    new_node -> link = NULL;

    if(*head == NULL)
        {
            *head = new_node;
            return;
        }

        new_node -> link = *head;
        *head = new_node;
        return;
}

void  add_at_pos(node_ptr *head)
{
    node_ptr new_node = (node_ptr)malloc(sizeof(node));
    node_ptr temp = *head;
    int data,pos,i;
    printf("\nEnter the data value for the node\n");
    scanf("%d",&data);
    new_node -> data = data;
    new_node -> link = NULL;
    printf("\nEnter the position\n");
    scanf("%d",&pos);
    if (pos == 1 && *head==NULL)
    {
        *head = new_node;
         return;
    }

    else if(pos == 1&& *head!=NULL)
    {
        new_node -> link = *head;
        *head = new_node;
        return;
    }

    else
    {
        for(i=0;i<(pos-1);i++)
            {
                temp = temp -> link;
            }
        new_node -> link = temp -> link;
        temp -> link = new_node;
    return;
    }
}

void locate_midpoint(node_ptr head)
{
    node_ptr fast = head;
    node_ptr slow = head;
    if (head!=NULL)
    {
        while(fast!=NULL && fast -> link != NULL)
            {
                fast = fast -> link -> link;
                slow = slow -> link;
            }
        printf("\nThe middle element is %d\n",slow -> data);
    }
    return;
}

int main()
{
    node_ptr head = NULL;
    int ch;
    while(1)
    {
        printf("\nLinked List Operation\n");
        printf("Enter the choice \n");
        printf("1. Print the Linked List\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at specified position\n");
        printf("5. Mid point of Linked List\n");
        scanf("\n%d",&ch);
        switch(ch)
        {
        case 1:
            print_LL(head);
            break;
        case 2:
            add_at_end(&head);
            break;
        case 3:
            add_at_begin(&head);
            break;
        case 4:
            add_at_pos(&head);
            break;
        case 5:
            locate_midpoint(head);
            break;

        default:
            exit(0);
        }

    }

}


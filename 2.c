#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int item;
    struct node *next;
}node;

node first = {0,NULL};
node *head = NULL;

node *mk_node(int item)
{
    node *p = (node *)malloc(sizeof(node));

    if(p != NULL)
    {
        p->item = item;
        p->next = NULL;
        return p;
    }else
    {
        printf("malloc failure\n");
    }

}

int intial()
{
    head = &first;
}

void insert_node(node *p)
{
    p->next = head->next;
    head->next = p;
}

void traverse()
{
    node *p = head->next;

    while(p != NULL)
    {
        printf("%4d",p->item);
        p = p->next;
    }
    printf("\n");
}

node *find_node(int item)
{
    node *p = head->next;
    while(p != NULL)
    {
        if(p->item == item)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void rm_node(node *p)
{
    node *pre = head;


    while(pre->next != NULL)
    {
        if(pre->next == p)
        {
            pre->next = p->next;
            return;
        }

        pre = pre->next;
    }
}

void free_node(node *p)
{
    free(p);
    p = NULL;
}

void destory()
{
    node *p = NULL;

    while(head->next != NULL)
    {
        p = head->next;
        head = head->next;
        free_node(p);
    }
}

void traverse_node()
{
    node *p = NULL;
    node *nhead = NULL;

    while(head->next != NULL)
    {
        p = head->next;
        head->next = p->next;

        p->next = nhead;
        nhead = p;
    }
    head->next =nhead;
    
}

void insert_tail(node *p)
{
    node *pre = head;

    while(pre->next != NULL)
    {
        pre = pre->next;
    }
    pre->next = p;
}

void insert_l2b(node *p)
{
    node *pre = head;

    while(pre->next != NULL)
    {
        if(p->item < pre->next->item)
        {
            break;
        }
        pre =pre->next;
    }
    p->next = pre->next;
    pre->next = p;
}

void insert_b2l(node *p)
{
    node *pre = head;

    while(pre->next != NULL)
    {
        if(p->item > pre->next->item)
        {
            break;
        }
        pre =pre->next;
    }
    p->next = pre->next;
    pre->next = p;
}

int main()
{
    intial();
    int target;
    node *p = mk_node(1);
    insert_b2l(p);
    p = mk_node(5);
    insert_b2l(p);
    p = mk_node(2);
    insert_b2l(p);
    p = mk_node(12);
    insert_b2l(p);
    p = mk_node(5);
    insert_b2l(p);
    p = mk_node(6);
    insert_b2l(p);
    p = mk_node(7);
    insert_b2l(p);

    traverse();
    

    scanf("%d",&target);

    p = find_node(target);
    if(p != NULL)
    {
        printf("%p,%d,%d\n",p,p->item,target);
        rm_node(p);
        free_node(p);
        traverse();
    }else
    {
        printf("can't find target\n");
    }  
    traverse_node();
    traverse();

    destory();

    traverse();

    return 0;
}

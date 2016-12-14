#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node *next;
}node;

node sential = {0,NULL};
node *head;

void  init()
{
    head = &sential;
}

node *mk_node(int item)
{
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("malloc failure\n");
        exit(1);
    }

    p->item = item;
    p->next = NULL;

    return p;
}

void free_node(node *p)
{
    free(p);
    p = NULL;
}

void insert_node(node *p)
{
    p->next = head->next;
    head->next = p;
}

void insert_node_tail(node *p)
{
    node *pre = head;

    while (pre->next != NULL)
    {
        pre = pre->next;
    }   

    pre->next = p;
}

void insert_node_l2b(node *p)
{
    node *pre = head;

    while (pre->next != NULL)
    {
        if (p->item < pre->next->item)
        {
            break;
        }

        pre = pre->next;
    }

    p->next = pre->next;
    pre->next = p;
}


void traverse()
{
    node *p = head->next;

    while (p != NULL)
    {
        printf("%d ",p->item);
        p = p->next;
    }
    printf("\n");
}

node *find_item(int item)
{
    node *p = head->next;

    while (p != NULL)
    {
        if (p->item == item)
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

    while (pre->next != NULL)
    {
        if(pre->next == p)
        {
            pre->next = p->next;
            p->next = NULL;
            return;
        }

        pre = pre->next;
    }
}

void destroy()
{
    node *p;

    while (head->next != NULL)
    {
        p = head->next;
        head->next = p->next;
        free_node(p);
    }
}

void reverse()
{
    node *nhead = NULL;
    node *p;

    while (head->next != NULL)
    {
        p = head->next;
        head->next = p->next;

        p->next = nhead;
        nhead = p; 
    }

    head->next = nhead;
}

int main()
{
    int target;
    init();

    node *p = mk_node(100);
    insert_node_l2b(p);
    p = mk_node(2);
    insert_node_l2b(p);
    p = mk_node(-3);
    insert_node_l2b(p);
    p = mk_node(40);
    insert_node_l2b(p);
    p = mk_node(15);
    insert_node_l2b(p);
    p = mk_node(67);
    insert_node_l2b(p);
    p = mk_node(17);
    insert_node_l2b(p);

    traverse();

    scanf("%d",&target);
    p = find_item(target);
    if (p != NULL)
    {
        printf("%p %d %d\n",p,p->item,target);
        rm_node(p);
        free_node(p);
        traverse();
    }else
    {
        printf("can't find target %d\n",target);
    }
    reverse();
    traverse();
    destroy();
    traverse();

    return 0;
}

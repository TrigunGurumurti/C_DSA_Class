#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node
{
    int data; // adjacent node 
    struct node *next;
} node;

void create_list(node *l)
{
    int vertex, from, to;
    node *t, *nn;
    printf("Enter the number of vertices :\n");
    scanf("%d", &vertex);
    l[0].data = vertex;
    l[0].next = NULL;
    for(int i = 1; i <= l[0].data; i++)
    {
        l[i].data = i;
        l[i].next = NULL;
    }
    while(1)
    {
        printf("\nEnter the from and to node:");
        scanf("%d %d", &from, &to);
        if (from > 0 && from <= vertex && to > 0 && to <= vertex)
        {
            t = &l[from];
            while (t->next != NULL)
            {
                t = t->next;
            }
            nn = (node *)malloc(sizeof(node));
            nn->data = to;
            nn->next = NULL;
            t->next = nn;
        }
        else
            break;
    }
}

void ListDisplay(node *l)
{
    node *t;
    for(int i = 1; i <= l[0].data; i++)
    {
        printf("\n%d->", l[i].data);
        t = &l[i];
        while (t->next != NULL)
        {
            t = t->next;
            printf("%d->", t->data);
        }
        printf("NULL");
    }
}

int main()
{
    node adjlist[MAX]; // 1d array
    create_list(adjlist);
    ListDisplay(adjlist);
    return 0;
}
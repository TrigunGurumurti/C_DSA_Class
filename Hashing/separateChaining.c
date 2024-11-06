#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
// For the nodes in SLL
typedef struct node
{
    int data;
    struct node *next;
}NODE;
// structure for the hash table
typedef struct hashtable{
    int count;
    struct node *head;
}HT;
NODE* createNode(int key)
{
    NODE *nn = (NODE*)malloc(sizeof(NODE));
    nn->data = key;
    nn->next = NULL;
    return nn;
}
void insert(int key,HT *hashtable)
{
    int hash_func = key % SIZE;
    NODE *nn = createNode(key);
    nn->next = hashtable[hash_func].head; // add a node to the head of the SLL
    hashtable[hash_func].head = nn;
    hashtable[hash_func].count++;
}

void display(HT *hashtable)
{
    for(int i=0;i<SIZE;i++)
    {
        if(hashtable[i].count != 0)
        {
            printf("\n Index[%d]:",i);
            NODE *t = hashtable[i].head;
            while(t)
            {
                printf("%d->",t->data);
                t = t->next;
            }
            printf("NULL");
        }
    }
    printf("\n");
}
void search(int key, HT *hashtable)
{
   int hash_func = key % SIZE;
   int pos = 1;
   NODE *t = hashtable[hash_func].head;
   while(t)
   {
    if(t->data == key)
    {
        printf("\n Element found at index [%d], position [%d]\n",hash_func,pos);
        return;
    }
    t = t->next;
    pos++;
   }
   printf("\nElement not found");
}
int main()
{
    HT hashtable[SIZE] = {0}; // Initialize the hash table with zero counts and NULL heads
    insert(10,hashtable);
    insert(20,hashtable);
    insert(15,hashtable);
    insert(30,hashtable);
    insert(47,hashtable);
    insert(65,hashtable);
    display(hashtable);

    search(20,hashtable);
    display(hashtable);
}

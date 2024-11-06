#include<stdio.h>

#define SIZE 10


typedef struct node
{
    int data;
    int flag;  // 0: empty, 1: occupied
} NODE;


void initializeHashTable(NODE *hashTable)
{
    for(int i=0; i<SIZE; i++)
    {
        hashTable[i].data = 0;
        hashTable[i].flag = 0;
    }
}


void display(NODE *hashTable)
{
    printf("\nHash Table:\n");
    for(int i=0; i<SIZE; i++)
    {
        if(hashTable[i].flag == 1)
        {
            printf("Index %d: %d\n", i, hashTable[i].data);
        }
        else
        {
            printf("Index %d: EMPTY\n", i);
        }
    }
    printf("\n");
}


//Linear Probing
void insert(int key, NODE *hashtable)
{
    int i = 0;
    int hash = ( (key % SIZE) + i ) % SIZE;
    while(hashtable[hash].flag !=0 && i<SIZE)
    {
        i++;
        hash = ( (key % SIZE) + i ) % SIZE;
    }
    if(hashtable[hash].flag == 0)
    {
        hashtable[hash].data = key;
        hashtable[hash].flag = 1;
    }
    else
    {
        printf("\nData cannot be inserted\n");
    }
}


void search(int key, NODE *hashtable)
{
    int i = 0;
    int hash = ( (key % SIZE) + i ) % SIZE;
    while(i < SIZE)
    {
        if(hashtable[hash].data == key && hashtable[hash].flag == 1)
        {
            printf("The data %d is found at the index %d\n",key, hash);
            return;
        }
        i++;
        hash = ( (key % SIZE) + i ) % SIZE;
    }
    printf("Data not found");
}

int main()
{
    NODE hashTable[SIZE];
    initializeHashTable(hashTable);
    insert(5, hashTable);
    insert(15, hashTable);
    insert(25, hashTable);
    insert(49, hashTable);
    insert(59, hashTable);
    display(hashTable);
    search(15, hashTable); // Should find the data
    search(35, hashTable); // Should not find the data
    return 0;
}
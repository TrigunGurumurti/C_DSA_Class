// Max heap implementation using top down approach

#include<stdio.h>
#include<stdlib.h>
#include<limits.h> // INT_MAX in index 0
#define SIZE 20

typedef struct heap
{
    int heap[SIZE];
    int heapsize;
}HEAP;

void init(HEAP *h)
{
    h->heapsize=0; // start with an empty heap
    h->heap[0]=INT_MAX;
    // Is not used in the heap operations
    // heap index starts from 1
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insert(HEAP *h,int data)
{
    h->heap[++(h->heapsize)]=data; // insert the element at the end
    int current=h->heapsize;
    int parent=current/2;

    // Bubble up : Move the inserted element up to maintain the max heap property
    while(h->heap[parent] < h->heap[current] && current > 1)
    {
        swap(&h->heap[parent],&h->heap[current]);
        current=parent;
        parent=current/2;
    }
}

int deletemax(HEAP *h)
{
    int max=h->heap[1]; // the root element is deleted
    h->heap[1]=h->heap[h->heapsize--]; // moving the last element to the root
    int current=1;
    int child=2*current;

    while(child <= h->heapsize)
    {
        // Select the larger child
        if(h->heap[child+1] > h->heap[child])
        {
            child++;
        }

        // if the current element is smaller than the larger child, swap them
        if(h->heap[current] < h->heap[child])
        {
            swap(&h->heap[current],&h->heap[child]);
            current=child;
            child=2*current;
        }
        else
        {
            break;
        }  
    }
    
    return max;  
}

void display(HEAP *h)
{
    printf("Heap : ");
    for(int i=1;i<=h->heapsize;i++)
    {
        printf("%d",h->heap[i]);
    }
    printf("\n");
}

int main()
{
    HEAP *heap=(HEAP*)malloc(sizeof(HEAP));
    init(heap);
    int data,choice;
    do
    {
        printf("Enter the data to insert into the heap : ");
        scanf("%d",&data);
        insert(heap,data);
        printf("Heap after insertion : ");
        display(heap);
        printf("Press 1 to continue, 0 to stop");
        scanf("%d",&choice);
    }while(choice==1);

    printf("%d",deletemax(heap));
    printf("\nAfter deleting : ");
    display(heap);
}
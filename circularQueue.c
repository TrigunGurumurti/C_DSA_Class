#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

int front=-1;
int last=-1;
int cque[MAX_SIZE];

// function to insert an element x into circular queue
void cqinsert(int x)
{
    if(last==MAX_SIZE-1) last=0; // check for last index and update suitably
    else last++;

    if(front==last)  // check whether the cq is full or not
    {
        printf("cq full\n"); 
        last--;
    }
    else cque[last]=x; // adding the element x into the cque

    if(front==-1) front=0; // update the front index incase first element in the cque
} // end of function

int cqdelete(void)
{
    int x=-999;
    // check whether cq is empty
    if(front==-1) printf("Queue is empty");
    else
    {
        x=cque[front]; // remove the element from cque
        if(front==last) // check if this is the only element
        {
            front=-1; // reset the front and last to indicate empty
            last=-1;
        }
        else front++;
    }
    return x;
} // end of function cqdelete

void cqdisplay(void)
{
    int index1,index2,i;
    index1=front;
    index2=last;
    if(index1==-1) printf("Empty list\n");
    else
    {
        if(index2<index1)
        {
            for(i=index2;i<MAX_SIZE-1;i++)
            {
                printf("%d\n",cque[i]);
            }
            for(i=0;i<=index2;i++)
            {
                printf("%d\n",cque[i]);
            }    
        }
        else
        {
          for(i=index1;i<=index2;i++)
          {
            printf("%d\n",cque[i]);
          }
        }  
    }
}

void cqmenu(void)
{
    int choice,x;
    for(;;)
    {
        printf("\nInput your choice ---> 1 for cqinsert\n");
        printf("                  ---> 2 for cqdelete\n");
        printf("                  ---> 3 for cqdisplay\n");
        printf("                  ---> 1 any other value to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Input the value to be inserted onto the cque\n");
            scanf("%d",&x);
            cqinsert(x);
            break;
            case 2: printf("The value deleted from cq is: %d\n",cqdelete());
            break;
            case 3: printf("The elements on the cq are:\n");
            cqdisplay();
            break;
            default:  printf("Exiting from the program");
            exit(1);
        }
    }
}

int main()
{
    cqmenu();
    return 0;
}
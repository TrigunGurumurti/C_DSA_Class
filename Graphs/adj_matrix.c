#include<stdio.h>
#define MAX 10

typedef struct graph
{
    int vertex; // nodes
    int adjmat[MAX][MAX]; // 2d array
} graph;

void  create_matrix(graph *g)
{
    int from , to;
    printf("\nEnter the number of vertices :");
    scanf("%d", &g->vertex);
    g->adjmat[0][0] = 0;
    for(int i = 1; i <= g->vertex; i++)
    {
        g->adjmat[0][i] = i; // columns as vertices
        g->adjmat[i][0] = i; // rows as vertices
        for(int j = 1; j<= g->vertex; j++)
        {
            g->adjmat[i][j] = 0; // initialize all the matrix to zero
        }
    }
    while(1)
    {
        printf("\nEnter the from and to vertices : ");
        scanf("%d %d", &from, &to);
        if(from > 0 && from <= g->vertex && to > 0 && to <= g->vertex)
        {
            g->adjmat[from][to] = 1; // directed graph
            // g->adjmat[to][from] = 1; // undirected graph
        }
        else
        {
            break;
        }
    }
}

void display(graph g)
{
    for(int i = 0; i <= g.vertex; i++) // row
    {
        printf("\n");
        for(int j = 0; j <= g.vertex; j++) // col
        {
            if(i == 0 && j == 0)
            {
                printf(" ");
            }
            else
            {
                printf("%d ",g.adjmat[i][j]);
            }
        }
    }
}

int main()
{
    graph g;
    create_matrix(&g); // create the adjacency matrix
    display(g); // print the matrix
    return 0;
}

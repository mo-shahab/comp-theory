#include <stdio.h>
#include <stdlib.h>
#define infinity 9999
#define MAX 100

int n;
int adj[MAX][MAX];
int D[MAX][MAX];
int pred[MAX][MAX];

void create_graph();
void floyd_warshalls();
void find_path(int s, int d);
void display(int matrix[MAX][MAX], int n);

int main()
{
    int s, d;
    create_graph();
    floyd_warshalls();
    while(1);
    {
        printf("enter the source vertex(-1 to quit): ");
        scanf("%d", &s);
        if(s == 1)
        {
            break;
        }
        printf("enter the destination vertex: ");
        scanf("%d", &d);
        if(s < 0 || s > (n-1) || d < 0 || d > n-1)
        {
            printf("enter valid vertices. \n");
            continue;
        }
        printf("shortest path is : ");
        find_path(s, d);
        printf("length of this path is %d\n", D[s][d]);
    }
}

void floyd_warshalls()
{
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(adj[i][j] == 0)
            {
                D[i][j] = infinity;
                pred[i][j] = -1;
            }
            else
            {
                D[i][j] = adj[i][j];
                pred[i][j] = i;
            }
        }
    }
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }        
    }
    printf("shortest path matrix is : \n");
    display(D, n);
    printf("\n\n predecessor matrix is : \n");
    display(pred, n);
    for(i = 0; i< n; i++)
    {
        if(D[i][j] < 0)
        {
            printf("error: negative cycle: \n");
            exit(1);
        }
    }
}

void find_path(int s, int d)
{
    int i;
    int path[MAX];
    int count = 0;
    
    if(D[s][d] == infinity)
    {
        printf("no path\n");
        return;
    }
    count = -1;
    do
    {
        path[++count] = d;
        d = pred[s][d];
    } while (d!= s);
    path[++count] = s;
    for(i = count; i>= 0; i--)
    {
        printf("%d ", path[i]);
    }
    printf("\n");
}

void display(int matrix[MAX][MAX], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%7d", matrix[i][j]);
        }
        printf("\n");
    }
}

void create_graph()
{
    int i,max_edges,origin,destin, wt;

    printf("\nEnter number of vertices : ");
    scanf("%d",&n);

    max_edges = n*(n-1);

    for( i=1; i<=max_edges; i++ )
    {
        printf("\nEnter edge %d( -1 -1 ) to quit : ",i);
        scanf("%d %d",&origin,&destin);
        if( (origin == -1) && (destin == -1) )
            break;
        printf("enter the weight for this edge: ");
        scanf("%d", &wt);
        if( origin >= n || destin >= n || origin<0 || destin<0)
        {
            printf("\nInvalid edge!\n");
            i--;
        }
        else
            adj[origin][destin] = wt;
    }
}
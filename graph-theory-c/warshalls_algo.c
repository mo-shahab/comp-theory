#include <stdio.h>
#define MAX 100

void display(int matrix[MAX][MAX], int n);
int adj[MAX][MAX];
int n;

void create_graph();

int main()
{
    int i, j, k;
    int p[MAX][MAX];
    create_graph();
    printf("the adjacency matrix is: \n");
    display(adj, n);
    for(i = 0; i<n; i++)
    {
        for(j = 0; j< n; j++)
        {
            p[i][j] = adj[i][j]; // setting of the P-1 matrix viz. also adjacency matrix
        }
    }
    for(k = 0; k< n; k++)
    {
        for(i = 0; i<n; i++)
        {
            for(j = 0; j< n; j++)
            {
                p[i][j] = (p[i][j] || (p[i][k] && p[k][j]));
            }
        }
        printf("p%d is: \n", k);
        display(p, n);
    }
    return 0;
}

void create_graph()
{
        int i,max_edges,origin,destin;

        printf("\nEnter number of vertices : ");
        scanf("%d",&n);

        max_edges = n*(n-1);

        for( i=1; i<=max_edges; i++ )
        {
                printf("\nEnter edge %d( -1 -1 ) to quit : ",i);
                scanf("%d %d",&origin,&destin);
                if( (origin == -1) && (destin == -1) )
                        break;
                if( origin >= n || destin >= n || origin<0 || destin<0)
                {
                        printf("\nInvalid edge!\n");
                        i--;
                }
                else
                        adj[origin][destin] = 1;
        }/*End of for*/
}

void display(int matrix[MAX][MAX], int n)
{
        int i,j;
        for(i=0; i<n; i++)
        {
                for(j=0; j<n; j++)
                        printf("%4d",matrix[i][j]);
                printf("\n");
        }
        printf("\n");
}
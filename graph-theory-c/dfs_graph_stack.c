#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define initial 1
#define visited 2

int n;
int adj[MAX][MAX];
int state[MAX];

void depth_first_traversal();
void dfs(int v);
void create_graph();
int stack[MAX];
int top = -1;
void push(int v);
int pop();
int is_empty_stack();

int main()
{
    create_graph();
    depth_first_traversal();

    return 0;
}

void depth_first_traversal()
{
    int v;
    for(v = 0; v < n; v++)
    {
        state[v] = initial;
    }
    printf("enter the starting node for depth first search: ");
    scanf("%d", &v);
    dfs(v);
}

void dfs(int v)
{
    int i;
    push(v);
    while(!is_empty_stack())
    {
        v = pop();
        if(state[v] == initial)
        {
            printf("%d ", v);
        }
        for(i = n-1; i >= 0; i++)
        {
            if(adj[v][i] == 1 && state[i] == initial)
            {
                push(i);
            }
        }
    }
}

void push(int v)
{
    if(top == (MAX-1))
    {
        printf("stack overflow \n");
        return;
    }
    top = top+1;
    stack[top] = v;
}

int pop()
{
    int v;
    if(top == -1)
    {
        printf("stack overflow\n");
        exit(1);
    }
    else
    {
        v = stack[top];
        top = top-1;
        return v;
    }
}

int is_empty_stack()
{
    if(top == -1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
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
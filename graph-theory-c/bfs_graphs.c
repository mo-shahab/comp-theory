#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
int n;
int adj[MAX][MAX];
int state[MAX];

void create_graph();
void breadth_first_traversal();
void bfs(int n);

int queue[MAX], front = -1, rear = -1;
void insert_queue(int vertex);
int delete_queue();
int is_empty_queue();

int main()
{
    create_graph();
    breadth_first_traversal();

    return 0;
}

void breadth_first_traversal()
{
    int v;
    for(v = 0; v < n; v++)
    {
        state[v] = initial;
    }
    printf("enter starting vertex for breadth first search: ");
    scanf("%d", &v);
    bfs(v);
}

void bfs(int v)
{
    int i;
    insert_queue(v);
    state[v] = waiting;
    while(!is_empty_queue())
    {
        v = delete_queue();
        printf("%d ", v);
        state[v] = visited;
        for(i = 0; i< n; i++)
        {
            if(adj[v][i] == 1 && state [i] == initial)
            {
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
}

void insert_queue(int vertex)
{
    if(rear == MAX -1)
    {
        printf("queue overflow\n");
    }
    else{
        if(front == -1)
        {
            front = 0;
        }
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

int is_empty_queue()
{
    if(front == -1 || front> rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int delete_queue()
{
    int del_item;
    if(front == -1 || front > rear)
    {
        printf("queue underflow \n");
        exit(1);
    }
    del_item = queue[front];
    front = front + 1;
    return del_item;
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
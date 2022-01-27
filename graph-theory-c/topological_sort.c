#include <stdio.h>
#include <stdlib.h>

#define max 100
int n;
int adj[max][max];
void create_graph();
int queue[max], front = -1, rear = -1;

void insert_queue(int v);
int delete_queue();
int is_empty_queue();
int indegree(int v);

int main()
{
    int i, v, count, topo_order[max], indeg[max];
    create_graph();

    for(i = 0; i<n; i++)
    {
        indeg[i] = indegree(i);
        if(indeg[i] == 0)
        {
            insert_queue(i);
        }
    }
    count = 0;
    while(!is_empty_queue())
    {
        v = delete_queue();
        topo_order[++count] = v;
        for(i = 0; i < n; i++)
        {
            if(adj[v][i] == 1)
            {
                adj[v][i] = 0;
                indeg[i] = indeg[i] -1;
                if(indeg[i] == 0)
                {
                    insert_queue(i);
                }
            }
        }
    }
    if(count < n)
    {
        printf("no topological ordering is possible, graph contains cycle. \n");
        exit(1);
    }
    printf("vertices in topological order are: \n");
    for(i = 0; i<= count; i++)
    {
        printf("%d", topo_order[i]);
    }
    printf("\n");
}

void insert_queue(int vertex)
{
    if(rear == max-1)
    {
        printf("queue overflow\n");
    }
    else
    {
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
    if(front == -1 || front > rear)
    {
        return 1;
    }
    else{
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

int indegree(int v)
{
    int i, in_deg = 0;
    for(i = 0; i< n; i++)
    {
        if(adj[i][v] == 1)
        {
            in_deg++;
        }
    }
    return in_deg;
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
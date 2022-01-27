#include <stdio.h>
#define MAX 100
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1

void find_path(int s, int v);
void dijkstra(int s);
int min_temp();
void create_graph();

int n;
int adj[MAX][MAX];
int predecessor[MAX];
int path_length[MAX];
int status[MAX];

int main()
{
    int s, v;
    create_graph();
    printf("enter the source vertex: ");
    scanf("%d", &s);
    dijkstra(s);
    
    while(1)
    {
        printf("enter the destination vertex(-1 to quit): ");
        scanf("%d", &v);
        if(v == -1)
        {
            break;
        }
        if(v < 0 || v > n)
        {
            printf("this vertex does not exist. \n");            
        }
        else if (v == s)
        {
            printf("source and destination vertex are the same. \n");
        }
        else if (path_length[v] == infinity)
        {
            printf("there is no path from the source to the destination vertex.\n");
        }
        else{
            find_path(s, v);
        }
    }
    return 0;
}

void dijkstra(int s)
{
    int i, current;

    for(i = 0; i< n; i++)
    {
        predecessor[i] = NIL;
        path_length[i] = infinity;
        status[i] = TEMP;
    }

    path_length[s] = 0;
    while(1)
    {


        current = min_temp();
        if(current == NIL)
        {
            return;
        }
        status[current] = PERM;
        for(i = 0; i < n; i++)
        {
            if (adj[current][i] != 0 && status[i] == TEMP)
            {
                if(path_length[current] + adj[current][i] < path_length[i])
                {
                    predecessor[i] = current;
                    path_length[i] = path_length[current] + adj[current][i];
                }
            }
        }
    }
}

int min_temp()
{
    int i;
    int min = infinity;
    int k = NIL;
    for(i = 0; i< n; i++)
    {
        if(status[i] == TEMP && path_length[i]<min)
        {
            min = path_length[i];
            k = i;
        }
    }
    return k;
}

void find_path(int s, int v)
{
    int i, u;
    int path[MAX];
    int shortdist = 0;
    int count = 0;
    
    while(v !=s)
    {
        count++;
        path[count] = v;
        u = predecessor[v];
        shortdist += adj[u][v];
        v = u;
    }
    count++;
    path[count] = s;
    printf("shortest path is: ");
    for(i = count; i >= 1; i--)
    {
        printf("%d ", path[i]);
    }
    printf("the shortest distance is: %d\n", shortdist);
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
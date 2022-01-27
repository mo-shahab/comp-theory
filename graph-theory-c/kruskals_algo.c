#include <stdio.h>
#include <stdlib.h>

#define max 100
#define NIL -1

struct edge
{
    int u;
    int v;
    int weight;
    struct edge *link;
} *front = NULL;

void make_tree(struct edge tree[]);
void insert_pque(int i, int j, int wt);
struct edge *del_pque();
int is_empty_pque();
void create_graph();
int n;

int main()
{
    int i;
    struct edge tree[max];
    int wt_tree = 0;
    create_graph();
    make_tree(tree);
    printf("edges to be included in minimum spanning tree are: \n");
    for(i = 1; i<= n-1; i++)
    {
        printf("%d", tree[i].v);
        printf("%d", tree[i].v);
        wt_tree += tree[i].weight;
    }
    printf("weight of this minimum spanning tree is: %d\n", wt_tree);
}

void make_tree(struct edge tree[])
{
    struct edge *temp;
    int v1, v2, root_v1, root_v2;
    int father[max];
    int i, count = 0;
    for(i = 0; i< n; i++)
    {
        father[i] = NIL;
    }
    while(!is_empty_pque() && count < n-1)
    {
        temp = del_pque();
        v1 = temp->u;
        v2 = temp->v;
        while(v1 != NIL)
        {
            root_v1 = v1;
            v1 = father[v1];
        }
        while(v2 != NIL)
        {
            root_v2 = v2;
            v2 = father[v1];
        }
        if(root_v1 != root_v2)
        {
            count++;
            tree[count].u = temp->u;
            tree[count].v = temp->v;
            tree[count].weight = temp->weight;
            father[root_v2] = root_v1;
        }
    }
    if(count < n-1)
    {
        printf("graph is not connected, no spanning tree can be formed. \n");
        exit(1);
    }
}

void insert_pque(int i, int j, int wt)
{
    struct edge *temp, *q;
    temp = (struct edge*)malloc(sizeof(struct edge));
    temp->u = i;
    temp->v = j;
    temp->weight = wt;
    if(front == NULL)
    {
        temp->link = front;
        front = temp;
    }
    else
    {
        q = front;
        while(q->link != NULL && q->link->weight <= temp->weight)
        {
            q = q->link;
        }
        temp->link = q->link;
        if(q->link == NULL)
        {
            temp->link = NULL;
        }
    }
}

struct edge *del_pque()
{
    struct edge *temp;
    temp = front;
    front = front->link;
    return temp;
}

int is_empty_pque()
{
    if(front == NULL)
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
    int i,max_edges,origin,destin, wt;

    printf("\nEnter number of vertices : ");
    scanf("%d",&n);

    max_edges = n*(n-1)/2;

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
        {
            insert_pque(origin, destin, wt);
        }  
    }
}
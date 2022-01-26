// first try and all of that
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX];  //matrix defo
int n;              //no of vertices
void create_graph();
void display();
void insert_edge(int origin, int destin);
void del_edge(int origin, int destin);


int main()
{
    int choice, origin, destin;
    create_graph();
    while(1){
        printf("1. insert an edge\n");
        printf("2. delete an edge\n");
        printf("3. display\n");
        printf("4. exit\n");
        printf("enter your choice\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("enter an edge to be inserted: \n");
                scanf("%d %d", &origin, &destin);
                insert_edge(origin, destin);
                break;
            
            case 2:
                printf("enter an edge to be deleted: \n");
                scanf("%d %d", &origin, &destin);
                del_edge(origin, destin);
            
            case 3:
                display();
                break;

            case 4:
                exit(1);
            
            default:
                printf("wrong choice \n");
                break;
        }
    }
    return 0;
}

void create_graph(){
    int max_edges, i, j, origin, destin;
    int graph_type;
    printf("enter 1 for the graph type and 2 for the undirected graph\n");
    scanf("%d", &graph_type);
    printf("enter the number of the vertices\n");
    scanf("%d", &n);

    if(graph_type == 1){
        max_edges = n*(n-1)/2;
    } else {
        max_edges = n*(n-1);
    }

    for(i = 0; i< max_edges; i++){
        printf("enter the edges %d(-1 -1 to quit): ", i);
        scanf("%d %d", &origin, &destin);
        if(origin == -1 && destin == -1){
            break;
        }
        if(origin >= n || destin >= n || origin < 0 || destin < 0){
            printf("invalid vertex\n");
        }
        else{
            adj[origin][destin] = 1;
            if(graph_type = 1){
                adj[destin][origin] = 1;
            }
        }
    }
}

void display(){
    printf("the adjacency matrix is: \n");
    for (int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            printf("%4d", adj[i][j]);
        }
        printf("\n");
    }   
    
}

void insert_edge(int origin, int destin){
    if(origin < 0 || origin >=n || destin < 0 || destin >= n){
        printf("invalid");
        return;
    }
    adj[origin][destin] = 1;
}

void del_edge(int origin, int destin){
    if(origin < 0 || origin >=n || destin < 0 || destin >= n || adj[origin][destin] == 0){
        printf("invalid");
        return;
    }
    adj[origin][destin] = 0;
}
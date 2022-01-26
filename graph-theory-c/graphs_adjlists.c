#include <stdio.h>
#include <stdlib.h>

struct vertex
{
    int info;
    struct vertex* next_vertex;
    struct edge* first_edge;
};
struct vertex* start = NULL;

struct edge
{
    struct vertex* dest_vertex;
    struct edge* next_edge;
};

struct vertex *find_vertex(int u);
void insert_vertex(int u);
void insert_edge(int u, int v);
void delete_edge(int u, int v);
void delete_incoming_edges(int u);
void delete_vertex(int u);
void display();

int main()
{
    int choice, u, origin, destin;
    while(1){
        printf("1. insert a vertex\n");
        printf("2. insert an edge\n");
        printf("3. delete a vertex\n");
        printf("4. delete an edge\n");
        printf("5. display\n");
        printf("6. exit\n");
        printf("7. enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("enter a vertex to be inserted: ");
                scanf("%d", &u);
                insert_vertex(u);
                break;
            case 2:
                printf("enter an edge to be inserted: ");
                scanf("%d %d", &origin, &destin);
                insert_edge(origin, destin);
                break;
            case 3:
                printf("enter a vertex to be deleted: ");
                scanf("%d", &u);
              //this deletes all edges coming to this vertex  
                delete_incoming_edges(u);
              //this function deletes vertex from the vertex list  
                delete_vertex(u);
                break;
            case 4:
                printf("enter an edge to be deleted: ");
                scanf("%d %d", &origin, &destin);
                delete_edge(origin, destin);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(1);
            default:
                printf("wrong choice bro.");
        }
    }

    return 0;
}

//basic end insertion of the linked list
void insert_vertex(int u){
    struct vertex* temp, *ptr;
    temp = malloc(sizeof(struct vertex));
    temp->info = u;
    temp->next_vertex = NULL;
    temp->first_edge = NULL;

    if(start == NULL){
        start = temp;
        return;
    }
    ptr = start;
    while(ptr->next_vertex != NULL){
        ptr = ptr->next_vertex;
    }
    ptr->next_vertex = temp;
}
//basic linked list deletion
void delete_vertex(int u){
    struct vertex* temp, *q;
    struct edge* _temp, *p;
    if(start == NULL){
        printf("no vertices needs to be delete.\n");
        return;
    }
    if(start->info == u){
        temp = start;
        start = start->next_vertex;
    }
    else {
        q = start;
        while(q->next_vertex != NULL){
            if(q->next_vertex->info == u){
                break;
            }
            q = q->next_vertex;
        }
        if(q->next_vertex == NULL){
            printf("vertex not found");
            return;
        }
        else {
            temp = q->next_vertex;
            q->next_vertex = temp->next_vertex;
        }
    }
    p = temp->first_edge;
    while(p != NULL){
        _temp = p;
        p = p->next_edge;
        free(_temp);
    }
    free(temp);
}

void delete_incoming_edges(int u){
    struct vertex* ptr; 
    struct edge* q, *temp;

    ptr = start;
    
    while(ptr != NULL){                                     //this is the normal traversal
        if(ptr->first_edge == NULL){                        //edge list for vertex pointer is empty
            ptr = ptr->next_vertex;
            continue;
        }
        if(ptr->first_edge->dest_vertex->info == u){        
            temp = ptr->first_edge;
            ptr->first_edge = ptr->first_edge->next_edge;
            free(temp);
            continue;
        }
        q = ptr->first_edge;
        while(q->next_edge != NULL){
            if(q->next_edge->dest_vertex->info == u){
                temp = q->next_edge;
                q->next_edge = temp->next_edge;
                free(temp);
                continue;
            }
            q = q->next_edge;
        }
        ptr = ptr->next_vertex;
    } 
}

struct vertex* find_vertex(int u){
    struct vertex* ptr, *loc;
    ptr = start;
    while(ptr != NULL){
        if(ptr->info == u){
            loc = ptr;
            return loc;
        } else {
            ptr = ptr->next_vertex;
        }
    }
    loc = NULL;
    return loc;
}

void insert_edge(int u, int v){
    struct vertex* locu, *locv;
    struct edge* ptr, *temp;
    locu = find_vertex(u);
    locv = find_vertex(v);
    if(locu == NULL){
        printf("start vertex not present, first insert vertex %d\n", u);
        return;
    }
    if(locv == NULL){
        printf("end vertex not present, first insert vertex %d\n", v);
        return;
    }
    temp = malloc(sizeof(struct edge));
    temp->dest_vertex = locv;
    temp->next_edge = NULL;
    if(locu->first_edge == NULL){
        locu->first_edge = temp;
        return;
    }
    ptr = locu->first_edge;
    while(ptr->next_edge != NULL){
        ptr = ptr->next_edge;
    }
    ptr->next_edge = temp;
}

void delete_edge(int u, int v){
    struct vertex* locu;
    struct edge* temp, *q;
    locu = find_vertex(u);
    if(locu == NULL){
        printf("start vertex is not found");
        return;
    }
    if(locu->first_edge == NULL){
        printf("edge not present");
        return;
    }
    if(locu->first_edge->dest_vertex->info == v){
        temp = locu->first_edge;
        locu->first_edge = locu->first_edge->next_edge;
        free(temp);
        return;
    }
    q = locu->first_edge;
    while(q->next_edge != NULL){
        if(q->next_edge->dest_vertex->info == v){
            temp = q->next_edge;
            q->next_edge = temp->next_edge;
            free(temp);
            return;
        }
        q = q->next_edge;
    }
    printf("the edge is not present");
}

void display(){
    struct vertex* ptr;
    struct edge* q;
    ptr = start;
    while(ptr != NULL){
        printf("%d", ptr->info);
        q = ptr->first_edge;
        while(q != NULL){
            printf(" %d", q->dest_vertex->info);
            q = q->next_edge;
        }
        printf("\n");
        ptr = ptr->next_vertex;
    }
}
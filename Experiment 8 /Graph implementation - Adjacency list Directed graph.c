#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node *next;
};

typedef struct node *GNODE;

GNODE graph[20] = {NULL};

GNODE createNode(int v) {
    GNODE newNode = (GNODE)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addAtEnd(int src, int dest) {
    GNODE newNode = createNode(dest);

    if (graph[src] == NULL) {
        graph[src] = newNode;
    } else {
        GNODE temp = graph[src];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void print(int *N) {
    for (int i = 1; i <= *N; i++) {
        if (graph[i] != NULL) {
            printf("%d=>", i);
            GNODE temp = graph[i];
            while (temp != NULL) {
                printf("%d	", temp->vertex);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

void insertVertex(int *N) {
    int edges, v;

    (*N)++;

    printf("Enter number of edges from existing vertices to new vertex : ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d", &v);
        if (v < 1 || v >= *N) {
            printf("Invalid vertex.\n");
            (*N)--;
            return;
        }
        addAtEnd(v, *N);
    }

    printf("Enter number of edges from new vertex to existing vertices : ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d", &v);
        if (v < 1 || v >= *N) {
            printf("Invalid vertex.\n");
            (*N)--;
            return;
        }
        addAtEnd(*N, v);
    }

    printf("After inserting vertex the adjacency list is : \n");
    print(N);
}

void insertEdge(int *N) {
    int src, dest;

    printf("Enter the source vertex of the edge : ");
    scanf("%d", &src);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &dest);

    if (src < 1 || src > *N || dest < 1 || dest > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    addAtEnd(src, dest);

    printf("After inserting edge the adjacency list is : \n");
    print(N);
}

void deleteVertex(int *N) {
    int v;

    if (*N == 0) {
        printf("Graph is empty.\n");
        return;
    }

    printf("Enter the vertex to be deleted : ");
    scanf("%d", &v);

    if (v < 1 || v > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    for (int i = 1; i <= *N; i++) {
        GNODE temp = graph[i], prev = NULL;

        while (temp != NULL) {
            if (temp->vertex == v) {
                if (prev == NULL)
                    graph[i] = temp->next;
                else
                    prev->next = temp->next;

                GNODE del = temp;
                temp = temp->next;
                free(del);
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
    }

    GNODE temp = graph[v];
    while (temp != NULL) {
        GNODE del = temp;
        temp = temp->next;
        free(del);
    }

    for (int i = v; i < *N; i++) {
        graph[i] = graph[i + 1];
    }
    graph[*N] = NULL;

    (*N)--;

    for (int i = 1; i <= *N; i++) {
        GNODE temp2 = graph[i];
        while (temp2 != NULL) {
            if (temp2->vertex > v)
                temp2->vertex--;
            temp2 = temp2->next;
        }
    }

    printf("After deleting vertex the adjacency list is : \n");
    print(N);
}

void deleteEdge(int *N) {
    int src, dest;

    printf("Enter the source vertex of the edge : ");
    scanf("%d", &src);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &dest);

    if (src < 1 || src > *N || dest < 1 || dest > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    GNODE temp = graph[src], prev = NULL;

    while (temp != NULL) {
        if (temp->vertex == dest) {
            if (prev == NULL)
                graph[src] = temp->next;
            else
                prev->next = temp->next;

            GNODE del = temp;
            temp = temp->next;
            free(del);
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    printf("After deleting edge the adjacency list is : \n");
    print(N);
}

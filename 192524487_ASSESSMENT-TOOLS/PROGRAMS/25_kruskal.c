/*
 * Program 25: Implementation of Minimum Spanning Tree using Kruskal's Algorithm
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compare(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e1->weight - e2->weight;
}

int main() {
    int n, edgeCount;
    Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edgeCount);

    printf("Enter edges (u v weight) with 0-based vertex numbers:\n");
    for (int i = 0; i < edgeCount; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    qsort(edges, edgeCount, sizeof(Edge), compare);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int mstWeight = 0, count = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");
    for (int i = 0; i < edgeCount && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int setU = find(u);
        int setV = find(v);

        if (setU != setV) {
            printf("%d - %d \t%d\n", u, v, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSet(setU, setV);
            count++;
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);

    return 0;
}

/*
 * Program 24: Implementation of Minimum Spanning Tree using Prim's Algorithm
 */
#include <stdio.h>
#include <limits.h>

#define MAX 20

int graph[MAX][MAX];
int n;

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex = -1;

    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int parent[]) {
    int totalWeight = 0;
    printf("\nEdge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

void primMST() {
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet);
        if (u == -1) break;
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent);
}

int main() {
    int edges, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v weight) with 0-based vertex numbers:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;   /* undirected graph */
    }

    primMST();

    return 0;
}

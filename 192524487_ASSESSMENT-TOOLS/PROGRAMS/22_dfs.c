/*
 * Program 22: Write a C program to Graph traversal using Depth First Search
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int current) {
    visited[current] = 1;
    printf("%d ", current);

    for (int i = 0; i < n; i++) {
        if (adj[current][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) with 0-based vertex numbers:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   /* undirected graph */
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS Traversal starting from vertex %d:\n", start);
    dfs(start);
    printf("\n");

    return 0;
}

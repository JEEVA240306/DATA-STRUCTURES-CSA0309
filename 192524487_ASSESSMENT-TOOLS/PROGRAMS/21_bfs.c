/*
 * Program 21: Write a C program to Graph traversal using Breadth First Search
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal starting from vertex %d:\n", start);

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
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

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}

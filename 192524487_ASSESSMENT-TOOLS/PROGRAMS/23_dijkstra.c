/*
 * Program 23: Implementation of Shortest Path Algorithms using Dijkstra's Algorithm
 */
#include <stdio.h>
#include <limits.h>

#define MAX 20

int graph[MAX][MAX];
int n;

int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, minIndex = -1;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printSolution(int dist[], int src) {
    printf("\nVertex \t Distance from Source (%d)\n", src);
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int src) {
    int dist[MAX];
    int visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, src);
}

int main() {
    int edges, u, v, w, src;

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

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}

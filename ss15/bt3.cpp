#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
int adj[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void dfs(int v, int V) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, V);
        }
    }
}

int checkConnectivity(int V) {
    dfs(0, V);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int V, E;
    printf("Nhap so dinh: ");
    scanf("%d", &V);
    printf("Nhap so canh: ");
    scanf("%d", &E);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Danh sach cac canh:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    if (checkConnectivity(V)) {
        printf("Do thi lien thong\n");
    } else {
        printf("Do thi khong lien thong\n");
    }

    return 0;
}


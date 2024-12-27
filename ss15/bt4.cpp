#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adj[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int recStack[MAX_VERTICES];

int dfs(int v, int V) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[v][i] == 1) {  
            if (!visited[i] && dfs(i, V)) {
                return 1; 
            }
            if (recStack[i]) {
                return 1; 
            }
        }
    }

    recStack[v] = 0; 
    return 0;
}


int checkCycle(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V)) {
                return 1;  
            }
        }
    }
    return 0;  
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
    }

    if (checkCycle(V)) {
        printf("Do thi co chu trinh\n");
    } else {
        printf("Do thi khong co chu trinh\n");
    }

    return 0;
}


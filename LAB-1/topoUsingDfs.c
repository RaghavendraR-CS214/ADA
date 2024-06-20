#include <stdio.h>
#include <stdlib.h>

#define max_v 100

int s[max_v] = {0};
int res[max_v];
int j = 0;

void DFS(int u, int n, int a[max_v][max_v]) {
    s[u] = 1;
    for (int v = 0; v < n; v++) {
        if (a[u][v] == 1 && s[v] == 0) {
            DFS(v, n, a);
        }
    }
    res[j++] = u;
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int a[max_v][max_v];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int u = 0; u < n; u++) {
        if (s[u] == 0) {
            DFS(u, n, a);
        }
    }

    printf("Topological order: ");
    for (int i = j - 1; i >= 0; i--) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}

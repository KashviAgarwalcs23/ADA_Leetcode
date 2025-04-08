#include <stdio.h>

#define MAX 10
#define INF 99999

int a[MAX][MAX], D[MAX][MAX], n;

void floyd(int [][MAX], int);
int min(int, int);

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (-1 for no connection):\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] == -1)
                a[i][j] = INF;
        }
    }

    floyd(a, n);

    printf("Distance Matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (D[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void floyd(int a[MAX][MAX], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            D[i][j] = a[i][j];
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (D[i][k] != INF && D[k][j] != INF)
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

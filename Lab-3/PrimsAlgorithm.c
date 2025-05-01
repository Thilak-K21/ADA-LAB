//This is Prim's Algorithm

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 9999

int main()
{
    int G[MAX][MAX], i, j, n;
    int selected[MAX];
    int no_edge = 0;
    int x, y;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (enter 0 if no edge):\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
            if (G[i][j] == 0)
            {
                G[i][j] = INF;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        selected[i] = 0;
    }

    selected[0] = 1;

    printf("\nEdge \tWeight\n");

    while (no_edge < n - 1)
    {
        int min = INF;
        x = 0;
        y = 0;

        for (i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!selected[j] && G[i][j] < min)
                    {
                        min = G[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d - %d\t%d\n", x, y, G[x][y]);
        selected[y] = 1;
        no_edge++;
    }

    return 0;
}

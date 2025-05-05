#include<stdio.h>
#include<limits.h>
#define INF 99999
#define MAX 100

int n;

int minDistance(int dist[],int visited[])
{
    int min=INF,min_index=-1;
    for(int v=0;v<n;v++)
    {
        if(dist[v]<=min && !visited[v])
        {
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX],int src)
{
    int dist[MAX],parent[MAX],visited[MAX];

    //initialise the matrices
    for(int i=0;i<n;i++)
    {
        dist[i]=INF;
        parent[i]=-1;
        visited[i]=0;
    }

    dist[src]=0;
    for(int count=0;count<n-1;count++)
    {
        int u=minDistance(dist,visited);
        if(u==-1)break;
        visited[u]=1;

        for(int v=0;v<n;v++)
        {
            if(!visited[v]&&graph[u][v]&&dist[u]!=INF&&dist[u]+graph[u][v]<dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
                parent[v]=u;
            }
        }
    }

    printf("Vertex\tDistance from Source\tPath\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i, dist[i]);
        int path[MAX], path_len = 0;
        int temp = i;
        while (temp != -1)
        {
            path[path_len++] = temp;
            temp = parent[temp];
        }
        for (int j = path_len - 1; j >= 0; j--)
            printf("%d ", path[j]);
        printf("\n");
    }
}
int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source);
}

#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void Dijkstra(int cost[MAX][MAX], int n, int start, int destination)
{
    int distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;

    // Creating cost matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (cost[i][j] == 0)
                cost[i][j] = INFINITY;

            else
                cost[i][j] = cost[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1)
    {
        mindistance = INFINITY;

        for (i = 0; i < n; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }

// Printing the distance of each node from the source
    for (i = 0; i < n; i++)
    {
        if (i != start)
        {
            printf("Distance from source to %d: %d\n", i, distance[i]);
            printf("Path: %d ", start);
            int path1 = i;
            int path[MAX];
            int pathlength=0;
            while (path1 != start)
            {
                path[pathlength++]=path1;
                path1 = pred[path1];
            }
            for(int p=pathlength-1;p>=0;p--)
            {
                printf("-->%d",path[p]);
            }
            printf("\n");
        }
    }

// Printing the shortest path
    printf("Shortest distance from source to destination: %d\n", distance[destination]);
    printf("Shortest path: %d ", destination);
    int path = destination;
    int ShortestPath[MAX];
    int pathlength=0;

    while (path != start)
    {
        ShortestPath[pathlength++]=path;
        path = pred[path];
    }
    for(int p=pathlength-1;p>=0;p--)
         printf("-->%d",ShortestPath[p]);
    printf("\n");
}

int main()
{
    int cost[MAX][MAX], i, j, n, u, destination;
    printf("Enter the number of nodes:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i > j)
            {
                printf("Distance between %d and %d: %d\n", i, j, cost[j][i]);
                cost[i][j] = cost[j][i];
            }

            else
            {
                printf("Distance between %d and %d:", i, j);
                scanf("%d", &cost[i][j]);
            }
        }
    }

    printf("Enter the starting node:");
    scanf("%d", &u);

    printf("Enter the destination node:");
    scanf("%d", &destination);

    Dijkstra(cost, n, u, destination);
    return 0;
}
//In case of an error in the first code, try the second or third code.
------------------------------------------------------------------------------------------------------------------
//1st Codw
#include <stdio.h>

#define V 4 // Number of vertices in the graph
#define INF 9999 // Infinity

// Function to print the solution matrix
void printSolution(int dist[][V]) {
    int i,j;
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for ( i = 0; i < V; i++) {
        for ( j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd Warshall algorithm
void floydWarshall(int graph[][V]) {
    int dist[V][V];
    int i, j, k;
    // Initialize the solution matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update dist[][] if vertex k is on the shortest path from i to j
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {{0, 3, 6, 8},
                       {3, 0, 2, 4},
                       {6, 2, 0, 1},
                       {8, 4, 1, 0}};
    // Run Floyd Warshall algorithm
    floydWarshall(graph);
    return 0;
}


------------------------------------------------------------------------------------------------------------------------------------------------
//2nd code
#include <stdio.h>

// Define infinity as a very large value
#define INF 99999
#define V 4 // Number of vertices

// Function to implement Floyd-Warshall algorithm
void floydWarshall(int graph[V][V]) {
    int dist[V][V]; // Output matrix where dist[i][j] will be the shortest distance from i to j

    // Initialize the solution matrix with the input graph values
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update dist[][] to find shortest path through intermediate vertices
    for (int k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distances
    printf("The shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Sample graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);
    return 0;
}


-------------------------------------------------------------------------------------------------------------------------------------------------------------
//3rd code
//For User Input
    #include <stdio.h>

#define INF 99999
#define V 4

void floydWarshall(int graph[][V], int vertices) {
    int dist[V][V];
    int i, j, k;

    // Initialize the distance matrix with the given graph
    for (i = 0; i < vertices; i++)
        for (j = 0; j < vertices; j++)
            dist[i][j] = graph[i][j];

    // Main algorithm loop
    for (k = 0; k < vertices; k++) {
        for (i = 0; i < vertices; i++) {
            for (j = 0; j < vertices; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    int graph[V][V];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    floydWarshall(graph, vertices);
    return 0;
}



//output :
// Enter the number of vertices in the graph: 3
// Enter the adjacency matrix of the graph:
// 0  4   11
// 6  0   2
// 3  INF  0
// Shortest distances between every pair of vertices:
// 0 4 6 
// 5 0 2 
// 3 7 0

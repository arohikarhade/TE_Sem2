#include <bits/stdc++.h>
using namespace std;
#define V 9

void printSolution(int dist[]){
    for(int i=0; i<V; i++){
        cout << i << "\t" << dist[i] << endl;
    }
}

int minDist(int dist[], bool spt[]){
    int min = INT_MAX, min_index;

    for(int v=0; v<V; v++){
        if(!spt[v] && dist[v]<min){
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void djikstra(int graph[V][V], int src){
    int dist[V];
    bool spt[V];

    for(int i=0; i<V; i++){
        dist[i]=INT_MAX;
        spt[i]=false;
    }

    dist[src] = 0;

    for(int cnt=0; cnt<V-1; cnt++){
        int u = minDist(dist, spt);

        spt[u] = true;

        for(int v=0; v<V; v++)
            if(!spt[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];

        printSolution(dist);
        cout << endl;
    }

    cout << endl;
    printSolution(dist);
}

int main(){
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	// Function call
	djikstra(graph, 0);

	return 0;
}

















// // A utility function to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
// int minDistance(int dist[], bool sptSet[])
// {
// 	// Initialize min value
// 	int min = INT_MAX, min_index;

// 	for (int v = 0; v < V; v++){
// 		if (sptSet[v] == false && dist[v] <= min){
//             min = dist[v];
//             min_index = v;
//         }
//     }
//     return min_index;
// }

// // A utility function to print the constructed distance array
// void printSolution(int dist[])
// {
// 	cout << "Vertex \t Distance from Source" << endl;
// 	for (int i = 0; i < V; i++)
// 		cout << i << " \t\t\t\t" << dist[i] << endl;
// }

// void dijkstra(int graph[V][V], int src)
// {
// 	int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i
//     bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

// 	// Initialize all distances as INFINITE and stpSet[] as false
// 	for (int i = 0; i < V; i++){
// 		dist[i] = INT_MAX;
//         sptSet[i] = false;
//     }

// 	// Distance of source vertex from itself is always 0
// 	dist[src] = 0;

// 	// Find shortest path for all vertices
// 	for (int count = 0; count < V - 1; count++) {
// 		// Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in the first iteration.
// 		int u = minDistance(dist, sptSet);

// 		// Mark the picked vertex as processed
// 		sptSet[u] = true;

// 		// Update dist value of the adjacent vertices of the picked vertex.
// 		for (int v = 0; v < V; v++)

// 			// Update dist[v] only if is not in sptSet, there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of dist[v]
// 			if (!sptSet[v] && graph[u][v]
// 				&& dist[u] != INT_MAX
// 				&& dist[u] + graph[u][v] < dist[v])
// 				dist[v] = dist[u] + graph[u][v];
// 	}

// 	printSolution(dist);
// }

#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

void bfs(Graph, int);

int main() {
    char filename[] = "input.txt";
    
    Graph graph = createNewGraph(filename);
    graph.printGraph();

    int vertices = graph.getVertices();

    for (int vertex = 0; vertex < vertices; vertex++) {
        vector<bool> visited(vertices, false);
        cout << "bfs(" << vertex << "): ";
        bfs(graph, vertex);

        cout << "\n\n";
    }

    return 0;
}

void bfs(Graph graph, int vertex) {
    queue<int> q;
    q.push(vertex);

    vector<bool> visited(graph.getVertices(), false);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (!visited[current]) {
            cout << current << " ";
            visited[current] = true;
        
            vector<int> neighbours = graph.getNeighboursOf(current);

            for (int neighbour : neighbours) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                }
            }
        }
    }
}



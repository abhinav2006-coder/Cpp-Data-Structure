#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adjmatrix; // Adjacency matrix

    Graph(int V) {
        this->V = V;
        adjmatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adjmatrix[u][v] = 1; // Add edge from u to v
        adjmatrix[v][u] = 1; // Add edge from v to u (for undirected graph)
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (int j = 0; j < V; j++) {
                cout << adjmatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int start, vector<bool>& visited) {
        visited[start] = true;
        cout << start << " ";

        for (int neighbor = 0; neighbor < V; neighbor++) {
            if (adjmatrix[start][neighbor] == 1 && !visited[neighbor]) {
                DFS(neighbor, visited);
            }
        }
    }
    
    void BFS(int start) {
        vector<bool> visited(V, false);
        vector<int> queue;

        visited[start] = true;
        queue.push_back(start);

        while (!queue.empty()) {
            int current = queue.front();
            queue.erase(queue.begin());
            cout << current << " ";

            for (int neighbor = 0; neighbor < V; neighbor++) {
                if (adjmatrix[current][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push_back(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "Graph representation (Adjacency Matrix):" << endl;
    g.printGraph();

    vector<bool> visited(5, false);
    cout << "\nDFS traversal starting from vertex 0:" << endl;
    g.DFS(0, visited);

    cout << "\nBFS traversal starting from vertex 0:" << endl;
    g.BFS(0);

    return 0;
}
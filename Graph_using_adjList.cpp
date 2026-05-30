#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Add edge from u to v
        adjList[v].push_back(u); // Add edge from v to u (for undirected graph)
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (int j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void DFS(int start, vector<bool>& visited) {
        visited[start] = true;
        cout << start << " ";

        for (int neighbor : adjList[start]) {
            if (!visited[neighbor]) {
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

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
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

    cout << "Graph representation (Adjacency List):" << endl;
    g.printGraph();

    cout << "DFS starting from vertex 0: ";
    vector<bool> visited(g.V, false);
    g.DFS(0, visited);
    cout << endl;

    cout << "BFS starting from vertex 0: ";
    g.BFS(0);
    cout << endl;

    return 0;
}
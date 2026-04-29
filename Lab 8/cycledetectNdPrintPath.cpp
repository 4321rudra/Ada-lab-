#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    bool dfsCycle(int node, int parent, vector<bool>& visited) {
        visited[node] = true;

        for (auto neighbour : adj[node]) {
            int next = neighbour.first;

            if (!visited[next]) {
                if (dfsCycle(next, node, visited))
                    return true;
            }
            else if (next != parent) {
                return true;
            }
        }

        return false;
    }

    bool hasCycle() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsCycle(i, -1, visited))
                    return true;
            }
        }

        return false;
    }
    void shortestPath(int source) {

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);

        dist[source] = 0;

        pq.push({0, source});

        while (!pq.empty()) {

            int node = pq.top().second;

            pq.pop();

            for (auto neighbour : adj[node]) {

                int next = neighbour.first;
                int weight = neighbour.second;

                if (dist[node] + weight < dist[next]) {

                    dist[next] = dist[node] + weight;

                    parent[next] = node;

                    pq.push({dist[next], next});
                }
            }
        }
        cout << "\nShortest Distances from Source " << source << ":\n";

        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " = " << dist[i] << endl;
        }

        // Print paths
        cout << "\nPaths:\n";

        for (int i = 0; i < V; i++) {

            if (i == source)
                continue;

            cout << "Path to " << i << ": ";

            printPath(i, parent);

            cout << endl;
        }
    }
    void printPath(int node, vector<int>& parent) {

        if (node == -1)
            return;

        printPath(parent[node], parent);

        cout << node << " ";
    }
};

int main() {

    Graph g(6);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 2);
    if (g.hasCycle())
        cout << "Graph contains cycle\n";
    else
        cout << "Graph does not contain cycle\n";
    g.shortestPath(0);

    return 0;
}
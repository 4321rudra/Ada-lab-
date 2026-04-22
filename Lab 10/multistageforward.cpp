#include <iostream>
#include <vector>
#include <climits>

using namespace std;
#define INF INT_MAX


void shortestPath(const vector<vector<int>>& graph, int stages) {
    int n = graph.size();
    vector<int> cost(n, 0);
    vector<int> dest(n, 0);
    cost[n - 1] = 0;
    dest[n - 1] = n - 1; 
    for (int i = n - 2; i >= 0; i--) {
        cost[i] = INF;
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != INF && cost[j] != INF) {
                if (graph[i][j] + cost[j] < cost[i]) {
                    cost[i] = graph[i][j] + cost[j];
                    dest[i] = j; 
                }
            }
        }
    }
    cout << "Minimum cost from source to sink is: " << cost[0] << "\n\n";
    cout << "Shortest Path: ";
    int current = 0;
    while (current != n - 1) {
        cout << current << " -> ";
        current = dest[current];
    }
    cout << n - 1 << endl;
}

int main() {
    int stages = 4;
    vector<vector<int>> graph = {
        {INF, 1, 2, 5, INF, INF, INF, INF},
        {INF, INF, INF, INF, 4, 11, INF, INF},
        {INF, INF, INF, INF, 9, 5, 16, INF},
        {INF, INF, INF, INF, INF, INF, 2, INF},
        {INF, INF, INF, INF, INF, INF, INF, 18},
        {INF, INF, INF, INF, INF, INF, INF, 13},
        {INF, INF, INF, INF, INF, INF, INF, 2}, 
        {INF, INF, INF, INF, INF, INF, INF, INF}
    };

    shortestPath(graph, stages);

    return 0;
}
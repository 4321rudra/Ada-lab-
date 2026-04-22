#include<iostream>
#include<vector>
using namespace std;

const int o = 100;
#define INF 9999

void dijkstra(int graph[][o], int n, int src) {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for(int i = 0; i < n - 1; i++) {
        int min = INF, min_index = -1;
        for(int j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                min_index = j;
            }
        }

        if(min_index == -1) break;

        visited[min_index] = true;

        
        for(int j = 0; j < n; j++) {
            if(!visited[j] && graph[min_index][j] != 0 &&
               dist[min_index] + graph[min_index][j] < dist[j]) {
                dist[j] = dist[min_index] + graph[min_index][j];
            }
        }
    }

    
    cout << "\nShortest distances from source " << src << ":\n";
    for(int i = 0; i < n; i++) {
        cout << "To " << i << " = " << dist[i] << endl;
    }
}

int main() {
    int graph[o][o], n, src;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(graph, n, src);

    return 0;
}
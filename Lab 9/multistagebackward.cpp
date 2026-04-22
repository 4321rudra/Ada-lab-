#include<iostream>
#include<vector>
using namespace std;

#define INF 9999

int main() {
    int n = 8; 
    int graph[8][8] = {
        {0,1,2,5,0,0,0,0},
        {0,0,0,0,4,11,0,0},
        {0,0,0,0,9,5,16,0},
        {0,0,0,0,0,0,2,0},
        {0,0,0,0,0,0,0,18},
        {0,0,0,0,0,0,0,13},
        {0,0,0,0,0,0,0,2},
        {0,0,0,0,0,0,0,0}
    };

    vector<int> cost(n, INF);
    vector<int> path(n, -1);
    cost[n-1] = 0;
    for(int i = n-2; i >= 0; i--) {
        for(int j = i+1; j < n; j++) {
            if(graph[i][j] != 0) {
                if(graph[i][j] + cost[j] < cost[i]) {
                    cost[i] = graph[i][j] + cost[j];
                    path[i] = j;
                }
            }
        }
    }
    cout << "Minimum cost from 0 to " << n-1 << " = " << cost[0] << endl;
    cout << "Path: ";
    int i = 0;
    while(i != -1) {
        cout << i << " ";
        i = path[i];
    }

    return 0;
}
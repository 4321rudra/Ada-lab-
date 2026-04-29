#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<vector<int>> &graph, vector<int> &color, int vertex,int c,int n){
    for (int i = 0; i < n; i++){
        if (graph[vertex][i] == 1 &&color[i] == c) {
            return false;
        }
    }
    return true;
}
bool graphColoring(vector<vector<int>> &graph, int m, vector<int> &color, int vertex, int n){
    if (vertex == n)
        return true;
    for (int c = 1; c <= m; c++){
        if (isSafe(graph, color,vertex, c, n)){
            color[vertex] = c;
            if (graphColoring(graph, m, color, vertex + 1, n)){
                return true;
            }
            color[vertex] = 0;
        }
    }
    return false;
}
int main(){
    int n = 4;
    vector<vector<int>> graph =
        {
            {0, 1, 1, 1},
            {1, 0, 1, 0},
            {1, 1, 0, 1},
            {1, 0, 1, 0}};
    int m = 3;
    vector<int> color(n, 0);
    if (graphColoring(graph, m, color, 0, n)){
        cout << "Coloring possible\n";
        for (int i = 0; i < n; i++){
            cout << "Vertex "<< i<< " -> Color "<< color[i]<< endl;
        }
    }
    else{
        cout << "Coloring not possible";
    }
    return 0;
}
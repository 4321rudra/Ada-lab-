#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int v, vector<vector<int>>& graph,vector<int>& path, int pos, int n){
    if(graph[path[pos - 1]][v] == 0)
        return false;
    for(int i = 0; i < pos; i++){
        if(path[i] == v)
            return false;
    }
    return true;
}
bool hamiltonianCycle(vector<vector<int>>& graph,vector<int>& path,int pos, int n){
    if(pos == n){
        if(graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for(int v = 1; v < n; v++){
        if(isSafe(v, graph, path, pos, n)){
            path[pos] = v;
            if(hamiltonianCycle(graph,path,pos + 1, n)){
                return true;
            }
            path[pos] = -1;
        }
    }
    return false;
}
int main(){
    int n = 5;
    vector<vector<int>> graph =
    {
        {0,1,0,1,0},
        {1,0,1,1,1},
        {0,1,0,0,1},
        {1,1,0,0,1},
        {0,1,1,1,0}
    };
    vector<int> path(n, -1);
    path[0] = 0;
    if(hamiltonianCycle(graph, path, 1, n)){
        cout << "Hamiltonian Cycle:\n";
        for(int i = 0; i < n; i++)
            cout << path[i] << " ";
        cout << path[0];
    }
    else{
        cout << "No Hamiltonian Cycle exists";
    }
    return 0;
}
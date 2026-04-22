#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge {
    int u, v, weight;
};
bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}
vector<int> parent, rankArr;
int find(int x) {
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if(rootX != rootY) {
        if(rankArr[rootX] < rankArr[rootY]) {
            parent[rootX] = rootY;
        } else if(rankArr[rootX] > rankArr[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rankArr[rootX]++;
        }
    }
}

void kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), cmp);
    parent.resize(n);
    rankArr.resize(n, 0);

    for(int i = 0; i < n; i++)
        parent[i] = i;

    cout << "Edge \tWeight\n";
    for(auto e : edges) {
        int u = e.u;
        int v = e.v;
        if(find(u) != find(v)) {
            cout << u << " - " << v << "\t" << e.weight << endl;
            unite(u, v);
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<Edge> edges;

    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < e; i++) {
        Edge temp;
        cin >> temp.u >> temp.v >> temp.weight;
        edges.push_back(temp);
    }

    kruskal(n, edges);

    return 0;
}
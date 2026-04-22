#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 9999
typedef pair<int,int> graph; 
void prim(int n, vector<vector<graph>> & adj){
    priority_queue<graph,vector<graph>, greater<graph>> pq;
    vector<int> key(n,INF);
    vector<bool> inMST(n,false);
    vector<int> parent(n,-1);
    pq.push({0,0});
    key[0]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(inMST[u]) continue;
        inMST[u]=true;
        for(auto it: adj[u]){
            int v=it.first;
            int weight =it.second;
            if(!inMST[v] && weight <key[v]){
                key[v]=weight;
                parent[v]=u;
                pq.push({key[v],v});
            }
        }
    }
    cout<<"Edge \tWeight\n";
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" - "<<i<<"\t"<<key[i]<<endl;
    }
}
int main(){
    int  n ,e ;
    cout<<"Enter number of vertices and edges : ";
    cin>>n>>e;
    vector<vector<graph>> adj(n);
    cout<< "Enter edges (u v weight ):"<<endl;
    for(int i=0;i<e;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }
    prim(n,adj);
    return 0;
}
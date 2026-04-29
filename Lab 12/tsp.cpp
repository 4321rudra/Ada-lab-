#include<iostream>
#include<vector>
using namespace std;
const int INF=99999;
int n;
vector<vector<int>> path;
vector<vector<int>> dist;
vector<vector<int>> dp;
int tsp(int mask,int pos){
    if(mask==(1<<n)-1){
        return dist[pos][0];
    }

    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }

    int ans=INF;
    for(int city=0;city<n;city++){
        if((mask & (1<<city))==0){
            int newAns=dist[pos][city]+tsp(mask |(1<<city),city);
            ans=min(ans,newAns);
            if(newAns==ans){
                path[mask][pos]=city;
            }
        }
    }
    return dp[mask][pos]=ans;
    

}
int main(){
    cout<<"Enter number of cities : "<<endl;
    cin>>n;
    dist.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<"Enter distance from city "<<i<<" to city "<<j<<" : "<<endl;
            cin>>dist[i][j];
        }
    }
    dp.assign(1<<n,vector<int>(n,-1));
    path.assign(1<<n,vector<int>(n,-1));

    cout<<tsp(1,0);
    int mask=1;
    int pos=0;
    cout<<"\nPath taken: "<<0<<" ";
    while(mask!=(1<<n)-1){
        pos=path[mask][pos];
        mask|=1<<pos;
        cout<<pos<<" ";
    }
    cout<<0<<endl;


    return 0;
}
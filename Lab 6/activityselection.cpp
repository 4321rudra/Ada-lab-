#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void activitySelection(vector<int>& s, vector<int>& f, int n){
    vector <pair<int,int>> act;
    for(int i=0;i<n;i++){
        act.push_back({f[i],s[i]});
    }
    sort(act.begin(),act.end());
    vector<int> res;
    res.push_back(0);
    int last=0;
    for(int i=1;i<n;i++){
        if(act[i].second>=act[last].first){
            res.push_back(i);
            last=i;
        }
    }
    cout<<"Selected activities are :\n";
    for(int i : res){
        // cout<<i+1<<"  ";
        cout<<"Start : "<<act[i].second<<" , Finish : "<<act[i].first<<endl;
    }
}
int main(){
    vector<int> s={1,3,0,5,8,5};
    vector<int> f={2,4,6,7,9,9};
    int n =s.size();
    activitySelection(s,f,n);
    return 0;

}
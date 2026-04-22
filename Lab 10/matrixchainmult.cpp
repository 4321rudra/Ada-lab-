#include<iostream>
using namespace std;
const int o =100;




void opsol(int s[][o], int i ,int j){
    if(i==j){
        cout<<"A"<<i;
        return;
    }
    else{
        cout<<"(";
        opsol(s,i,s[i][j]);
        opsol(s,s[i][j]+1,j);
        cout<<")";
    }
}
void mcmult(int d[] ,int n){
    int m[n][n], s[o][o];
    for(int i=0;i<=n;i++){
        m[i][i]=0;
    }
    for(int l=2;l<=n;l++){
        for(int i=1 ; i<=n-l+1;i++){
            int j=i+l-1;
            m[i][j]=32000;
            for(int k=i;k<=j-1;k++){
                int cost=m[i][k]+m[k+1][j] +d[i-1]*d[k]*d[j];
                if(cost<m[i][j]){
                    m[i][j]=cost;
                    s[i][j]=k;
                }
            }
        }
    }
    opsol(s,1,n);
}
int main(){
    int d[]={2,4,2,5,6,2};
    mcmult(d,5);
}
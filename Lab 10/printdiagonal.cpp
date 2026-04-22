#include<iostream>
using namespace std;
const int o=100;
void printd(int m[][5], int n){
    for(int i=n-1;i>=0;i--){
        int temp =i;
        for(int j=0;j<=i;j++){
            cout<<" "<<m[j][temp--]<<" ";
        }
        cout<<endl;
    }

}
int main(){
    int m[5][5]={{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4},{5,5,5,5,5}};
    printd(m,5);
}
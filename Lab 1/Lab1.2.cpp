#include<iostream>
using namespace std;
void permutation(string arr[],int k,int n){
    if(k==n){
        for(int i=0;i<n;i++){
            cout<<arr[i];
            
        }
        cout<<endl;
        return;
    }
    else{
        for(int i=k;i<n;i++){
            swap(arr[i],arr[k]);
            permutation(arr,k+1,n);
            swap(arr[i],arr[k]);
        }
    }
}
int main(){
    string arr[]={"A","B","C"};
    permutation(arr,0,3);
    return 0;
}
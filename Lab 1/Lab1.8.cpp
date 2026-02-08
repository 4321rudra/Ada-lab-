#include<iostream>
using namespace std;
void findMissing(int arr[],int n,int i){
    if(i==n-1){
        return;
    }
    
        if(arr[i]%2==arr[i+1]%2){
            cout<<"Number Missing "<<arr[i]+1<<endl;
            return;
        }

    findMissing(arr,n,i+1);
}
int main(){
    int arr[]={1,2,3,4,6};
    int s=sizeof(arr)/sizeof(arr[0]);
    findMissing(arr,s,0);
    return 0;
}
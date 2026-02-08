#include<iostream>
using namespace std;
void bubble_sort(int arr[],int n,int i){
    if(i==n-1){
        return;
        
    }
    for(int j=0;j<(n-i-1);j++){
        if(arr[j+1]<arr[j]){
            swap(arr[j+1],arr[j]);
        }

    }
    bubble_sort(arr,n,i+1);
}
int main(){
    int arr[]={64,25,12,22,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n,0);
    cout<<"Sorted array: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
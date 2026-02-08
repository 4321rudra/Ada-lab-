#include<iostream>
using namespace std;
void selection_sort(int arr[],int n,int i){
    if(i==n){
        return ;
    }
    int min=i;
    for(int j=i;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
    }
    swap(arr[i],arr[min]);
    selection_sort(arr,n,i+1);  
}
int main(){
    int arr[]={64,25,12,22,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,n,0);
    cout<<"Sorted array: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
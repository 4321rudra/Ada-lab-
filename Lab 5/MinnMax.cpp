#include<iostream>
using namespace std;
void minmax(int low, int high,int arr[],int &min ,int &max){
    if(low==high){
        min =max=arr[low];
    }
    else if(low==high-1){
        if(arr[low]>arr[high]){
            max=arr[low];
            min=arr[high];
        }
        else{
            max=arr[high];
            min=arr[low];
        }
    }
    else{
        int mid=(low+high)/2;
        int max1;int min1;
        minmax(low,mid,arr,min,max);
        minmax(mid+1,high,arr,min1,max1);
        if(min1<min){
            min=min1;
        }
        if(max1>max){
            max=max1;
    }
    }
}
int main(){
    int n;
    cout<<"Enter number of elements in array : "<<endl;
    cin>>n;
    int arr[n];
    int min,max;
    for(int i =0;i<n;i++){
        cout<<"Enter arr["<<i<<"] value : "<<endl;
        cin>>arr[i];
    }
    minmax(0,n-1,arr,min,max);
    cout<<"Minimum element in  the list : "<<min<<endl;
    cout<<"Maximum element in  the list : "<<max<<endl;

}
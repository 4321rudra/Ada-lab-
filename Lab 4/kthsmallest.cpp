#include<iostream>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[high]);
    return i;
}


void kthsmallest(int k,int arr[],int low,int high){
    if(k>0 && k<=high-low+1){
        int pos=partition(arr,low,high);
        if(pos-low==k-1){
            cout<<"Kth smallest element is "<<arr[pos];
            return;
        }
        if(pos-low>k-1){
            kthsmallest(k,arr,low,pos-1);
        }
        else{
            kthsmallest(k-pos+low-1,arr,pos+1,high);
        }
    }
    else{
        cout<<"K is out of range";
    }
}


int main(){
    int arr[5]={10,3,8,4,5};
    kthsmallest(3,arr,0,5);
    return 0;
}
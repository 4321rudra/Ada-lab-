#include<iostream>
using namespace std;
int horner(int arr[],int n,int i){
    if(n==0){
        return arr[n];

    }
    return ( horner(arr,n-1,i) * i + arr[n] );



}
int main(){
    int arr[]={5,0,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"Enter the value of x: ";
    cin>>x;
    int result=horner(arr,n-1,x);
    cout<<"The value of polynomial is: "<<result<<endl;
    return 0;
}

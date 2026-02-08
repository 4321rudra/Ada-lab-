#include<iostream>
using namespace std;
int power(int n, int a){
    if(a==0){
        return 1;
    }
    int ans=power(n,a/2);
    if(a%2==1){
        return n*ans*ans;
    }
    else{
        return ans*ans;
    }
}
int main(){
    int a=power(2,4);
    cout<<a;
}

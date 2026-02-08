#include<iostream>
using namespace std;
void ToH(int n,char From, char Using,char To){
    if(n==1){
        cout<<"Move disk 1 from "<<From<<" to "<<To<<endl;
        return;
    }
    ToH(n-1,From,To,Using);
    cout<<"Move disk "<<n<<" from "<<From<<" to "<<To<<endl;
    ToH(n-1,Using,From,To);

}
int main(){
    int n;
    cout<<"Enter number of disks: ";
    cin>>n;
    ToH(n,'A','B','C');
    return 0;
}

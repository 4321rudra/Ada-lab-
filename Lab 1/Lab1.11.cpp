#include <iostream>
using namespace std;

void findFirstDuplicate(int arr[], int n, int i, int j){
    if (i == n-1 ){
        cout << "No duplicate found";
        return;
    }
    if (j == n){
        findFirstDuplicate(arr, n, i+1, i+2 );
        return;
    }
    if (arr[i] == arr[j]){
        cout << "First duplicate value: " << arr[i] << endl;
        cout << "Location (index): " << j << endl;
        return;
    }
    findFirstDuplicate(arr, n, i, j+1);
}

int main(){
    int arr[] = {4,2,3,4,4,5,3,5,2,1};
    int n = 10;

    findFirstDuplicate(arr, n, 0, 1);

    return 0;
}
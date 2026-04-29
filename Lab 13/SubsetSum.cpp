#include <iostream>
#include <vector>
using namespace std;
void subsetSum(vector<int>& arr,int index, int currentSum, int target, vector<int>& subset){
    if(currentSum == target) {
        cout << "Subset: ";
        for(int x : subset)
            cout << x << " ";
        cout << endl;
    }
    if(index == arr.size() || currentSum > target)
        return;
    subset.push_back(arr[index]);
    subsetSum(arr,index + 1, currentSum + arr[index], target, subset);
    subset.pop_back();
    subsetSum(arr,index + 1,currentSum,target,subset);
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cout << "Enter target sum: ";
    cin >> target;
    vector<int> subset;
    cout << "\nPossible subsets are:\n";
    subsetSum(arr, 0, 0, target, subset);
    return 0;
}
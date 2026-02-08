#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using  std::vector;
using namespace std::chrono;
void makearray(vector<int> &arr,int size){
    arr.resize(size);
    for (int i=0;i<size;i++){
        arr[i]=rand();
    }
}
void partition(vector<int> &arr, int low, int high, int &pivotIndex) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    pivotIndex = i + 1;
}
void quicksort(vector<int> &arr, int low, int high) {
    
    if (low < high) {
        int pivotIndex;
        partition(arr, low, high, pivotIndex);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
  
    

}
void runbenchmark(){
    vector<int> dataset;
    int iterations=100;
    for(int inputsize=1000;inputsize<=10000;inputsize+=1000){
        long long totalduration=0;
        for(int iter=1;iter<=iterations;iter++){
            makearray(dataset,inputsize);
            auto starttime=high_resolution_clock::now();
            quicksort(dataset,0,inputsize-1);
            auto endtime=high_resolution_clock::now();
            totalduration+=duration_cast<nanoseconds>(endtime-starttime).count();
        }
        cout << "Average duration for size " << inputsize<< " : " << (totalduration / iterations) << " nanoseconds" << endl;
    }
}

int main() {
    runbenchmark();
    return 0;
}
#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
void makeArray(int data[], int Size) {
    for (int i = 0; i < Size; i++) {
        data[i] = rand();
    }
}
long long IS(int arr[], int n){
    auto startTime=system_clock::now();
    for(int i=1;i<n;i++){
        int element=arr[i];
        int j=i-1;
        while (j>=0 &&arr[j]>element){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=element;  
    }
    auto endTime=system_clock::now();
    return abs(duration_cast<nanoseconds>(endTime-startTime).count());
}
void runbenchmark(){
    int dataset[10000];
    int iterations =100;
    for(int inputsize=1000;inputsize<10000;inputsize+=1000){
        long long totalduration=0;
        for(int iter=1;iter<=iterations;iter++){
            makeArray(dataset,inputsize);
            totalduration+=IS(dataset,inputsize);
        }
        cout << "Average duration for size " << inputsize<< " : " << (totalduration / iterations) << " nanoseconds" << endl;
            
    }
    }
int main(){
    runbenchmark();
    return 0;
}
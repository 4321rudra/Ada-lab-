#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
void makeArray(int data[], int Size) {
    for (int i = 0; i < Size; i++) {
        data[i] = rand();
    }
}
void IS(int arr[], int n){
    for(int i=1;i<n;i++){
        int element=arr[i];
        int j=i-1;
        while (j>=0 &&arr[j]>element){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=element;  
    }
}
int binarySearch(int arr[], int size, int x){
    IS(arr, size);
    auto start = system_clock::now();
     
    int first = 0;
    int last = size - 1;
    
    while(first <= last){
        int mid = (first + last) / 2;
        if(arr[mid] == x){
            auto endTime = system_clock::now();
            return abs(duration_cast<nanoseconds>(endTime - start).count());
        }
        else if(x > arr[mid]){
            first = mid + 1;
        }
        else{
            last = mid - 1;
        }
    }
    auto endTime = system_clock::now();
    return abs(duration_cast<nanoseconds>(endTime - start).count());
}
void makearray(int arr[], int size){
    for(int i=0;i<size;i++){
        arr[i]=rand();
    }
}

void runBenchmark(){
    int dataset[10000];
    int iterations=100;
    for(int inputsize=1000;inputsize<10000;inputsize+=1000){
        
        int totalduration=0;
        for(int iter =1;iter<=100;iter++){
            makearray(dataset,inputsize);
            totalduration+=binarySearch(dataset,inputsize,dataset[inputsize-1]);

        }
        cout << "Average duration for size " << inputsize<< " : " << abs((totalduration / iterations)) << " nanoseconds" << endl;
    }
}
int main(){
    runBenchmark();
    return 0;
}
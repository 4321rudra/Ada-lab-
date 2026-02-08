#include <iostream>
#include <cstdlib> 
#include <chrono>

using namespace std;
using namespace std::chrono;

void makeArray(int data[], int Size) {
    for (int i = 0; i < Size; i++) {
        data[i] = rand();
    }
}

int LinearSearch(int data[], int size, int searchKey) {
    auto startTime = system_clock::now();
    
    for (int i = 0; i < size; i++) {
        if (data[i] == searchKey) break;
    }
    
    auto endTime = system_clock::now();
    return duration_cast<nanoseconds>(endTime - startTime).count();
}

void runBenchmark() {
    int dataset[20000];
    int iterations = 100;

    for (int inputSize = 1000; inputSize <= 20000; inputSize += 1000) {
        int totalDuration = 0;
       
        for (int iter = 1; iter <= iterations; iter++) {
            makeArray(dataset, inputSize);
            totalDuration += LinearSearch(dataset, inputSize, rand());
        }

        cout << "Average duration for size " << inputSize 
             << " : " << (totalDuration / iterations) << " nanoseconds" << endl;
    }
}

int main() {
  
    runBenchmark();
    
    return 0;
}
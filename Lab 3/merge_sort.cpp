#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using  std::vector;
using namespace std::chrono;

void makearray(vector<int> &arr, int size){
    arr.resize(size);
    for(int i=0;i<size;i++){
        arr[i]=rand();
    }

}
void merge(vector<int> &arr,int low,int mid, int high){
    int i=low;
    int j=mid+1;
    vector<int> temp;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }   
    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }
    int k=0;
    for(int i=low;i<=high;i++){
        arr[i]=temp[k];
        k++;
    }
}
void mergesort(vector<int> &arr,int low,int high){
   
    if(low<high){
        int mid=low+(high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
   
}
void runbenchmark(){
    vector<int> dataset;
    int iterations=100;
    for(int inputsize=1000;inputsize<=10000;inputsize+=1000){
        long long totalduration=0;
        for(int iter=1;iter<=iterations;iter++){
            makearray(dataset,inputsize);
            auto startTime=high_resolution_clock::now();
            mergesort(dataset,0, inputsize-1);
            auto endTime=high_resolution_clock::now();
            totalduration+=duration_cast<nanoseconds>(endTime-startTime).count();
        }
        cout<<"Average duration for size "<<inputsize<< " : "<<(totalduration/iterations)<<"nanosecond"<<endl;
    }


}
int main(){
    runbenchmark();
    return 0;
}
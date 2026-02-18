#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct Process{
    int id;;
    int arrivaltime;
    int bursttime;
    int remainingtime;
    int completiontime;
    int waitingtime;
    int turnaroundtime;

};
struct cmprmngtime{
    bool operator()(const Process* a , const Process *  b){
        if(a->remainingtime==b->remainingtime){
            
        }
        return a->remainingtime > b->remainingtime;
    }

};
void SRTF(vector<Process> & processes){
    int n=processes.size();
    int currenttime=0;
    int completed=0;
    // auto cmp=cmprmngtime();
    priority_queue<Process*,vector<Process*>,cmprmngtime> minHeap;
    while(completed<n){
        for(auto& process: processes){
            if(process.arrivaltime==currenttime){
                minHeap.push(&process);
            }
        }
        if(!minHeap.empty()){
            Process *currentProcess=minHeap.top();
            minHeap.pop();
            currentProcess->remainingtime--;
            currenttime++;
            if (currentProcess->remainingtime==0){
                completed++;
                currentProcess->completiontime=currenttime;
                currentProcess->turnaroundtime=currentProcess->completiontime-currentProcess->arrivaltime;
                currentProcess->waitingtime=currentProcess->turnaroundtime-currentProcess->bursttime;
            }
            else{
                minHeap.push(currentProcess);
            }
        }
        else{
            currenttime++;
            

        }
    }
}
int main(){
    int n;
    cout<<"Enter the number of processes : ";
    cin>>n;
    vector<Process> processes(n);
    for(int i=0;i<n;i++){
        cout<<"Enter arrival time and burst time for process "<<i+1<<": ";
        cin>>processes[i].arrivaltime>>processes[i].bursttime;
        processes[i].id=i+1;
        processes[i].remainingtime=processes[i].bursttime;
    }
    SRTF(processes);
    // cout<<" \n Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    // for(const auto& process : processes){
    //     cout<< process.id<<"\t\t"<<process.arrivaltime<<"\t\t"<<process.bursttime<<"\t\t"<<process.completiontime<<"\t\t"<<process.turnaroundtime<<"\t\t"<<process.waitingtime<<"\n";
    // }
    int ATA=0;
    int AWT=0;

    for(const auto& process : processes){
        ATA+=process.


    }
    cout<<"Average Turnaround time : "<<
    return 0;
}
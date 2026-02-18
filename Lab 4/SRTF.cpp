#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

struct CompareRemainingTime {
    bool operator()(const Process* a, const Process* b) {
        if (a->remainingTime == b->remainingTime) {
            return a->arrivalTime > b->arrivalTime;
        }
        return a->remainingTime > b->remainingTime;
    }
};

void SRTF(vector<Process>& processes) {
    int n = processes.size();
    int currentTime = 0;
    int completed = 0;

    auto cmp = CompareRemainingTime();
    priority_queue<Process*, vector<Process*>, CompareRemainingTime> minHeap;

    while (completed < n) {
        for (auto& process : processes) {
            if (process.arrivalTime == currentTime) {
                minHeap.push(&process);
            }
        }

        if (!minHeap.empty()) {
            Process* currentProcess = minHeap.top();
            minHeap.pop();

            currentProcess->remainingTime--;
            currentTime++;

            if (currentProcess->remainingTime == 0) {
                completed++;
                currentProcess->completionTime = currentTime;
                currentProcess->turnaroundTime = currentProcess->completionTime - currentProcess->arrivalTime;
                currentProcess->waitingTime = currentProcess->turnaroundTime - currentProcess->burstTime;
            } else {
                minHeap.push(currentProcess);
            }
        } else {
            currentTime++;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].id = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }

    SRTF(processes);

    cout << "\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (const auto& process : processes) {
        cout << process.id << "\t\t" << process.arrivalTime << "\t\t" << process.burstTime << "\t\t" << process.completionTime << "\t\t" << process.turnaroundTime << "\t\t" << process.waitingTime << "\n";
    }

    return 0;
}

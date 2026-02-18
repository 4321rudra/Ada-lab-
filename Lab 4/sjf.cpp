#include<iostream>
#include<climits> // For INT_MAX
using namespace std;

struct Process {
    int id;             // To identify process (P1, P2, etc.)
    int burst_time;
    int arrival_time;
    int turnaround_time;
    int waiting_time;
    int completion_time;
    bool is_completed;  // Flag to check if process is done
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    // Dynamic allocation of array based on input n
    Process* p = new Process[n]; 
    
    // --- Input Section ---
    for(int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> p[i].burst_time;
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> p[i].arrival_time;
        p[i].is_completed = false; // Initialize as incomplete
    }

    // --- SJF Logic Section ---
    int current_time = 0;
    int completed = 0;

    // Loop until all processes are completed
    while(completed != n) {
        int idx = -1;
        int min_burst = INT_MAX;

        // Find the process with the shortest burst time among those that have arrived
        for(int i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && !p[i].is_completed) {
                if(p[i].burst_time < min_burst) {
                    min_burst = p[i].burst_time;
                    idx = i;
                }
                // Tie-breaker: If burst times are same, pick the one that arrived first (or by ID)
                if(p[i].burst_time == min_burst) {
                    if(p[i].arrival_time < p[idx].arrival_time) {
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) {
            // Process found: Execute it
            p[idx].completion_time = current_time + p[idx].burst_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            
            p[idx].is_completed = true;
            completed++;
            current_time = p[idx].completion_time; // Jump time forward
        } else {
            // No process arrived yet; CPU is idle
            current_time++;
        }
    }

    // --- Output Section ---
    cout << "\n-----------------------------------------------------------------------\n";
    cout << "ID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    cout << "-----------------------------------------------------------------------\n";
    
    float total_tat = 0;
    float total_wt = 0;

    for(int i = 0; i < n; i++) {
        total_tat += p[i].turnaround_time;
        total_wt += p[i].waiting_time;
        
        cout << p[i].id << "\t" 
             << p[i].arrival_time << "\t" 
             << p[i].burst_time << "\t" 
             << p[i].completion_time << "\t\t" 
             << p[i].turnaround_time << "\t\t" 
             << p[i].waiting_time << "\n";
    }

    cout << "\nAverage Turnaround Time: " << total_tat / n << endl;
    cout << "Average Waiting Time: " << total_wt / n << endl;

    delete[] p; // Clean up memory
    return 0;
}
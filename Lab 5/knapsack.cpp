#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
struct object {
    int id;
    double profit;
    double weight;
};
void makeobject(object o[], int n, int capacity) {
    for(int i = 0; i < n; i++) {
        o[i].id = i;
        o[i].profit = rand() % capacity + 1;
        o[i].weight = rand() % capacity + 1;
    }
}
bool comparebyr(object a, object b) {
    return (a.profit / a.weight) > (b.profit / b.weight);
}

bool comparebyp(object a, object b) {
    return a.profit > b.profit;
}

bool comparebyw(object a, object b) {
    return a.weight < b.weight;
}
double greedyRatio(object o[], int n, double remweight) {
    sort(o, o + n, comparebyr);

    double netprofit = 0;
    int i = 0;

    while(remweight > 0 && i < n) {
        if(o[i].weight <= remweight) {
            netprofit += o[i].profit;
            remweight -= o[i].weight;
        } else {
            netprofit += (remweight / o[i].weight) * o[i].profit;
            remweight = 0;
        }
        i++;
    }
    return netprofit;
}
double greedyProfit(object o[], int n, double remweight) {
    sort(o, o + n, comparebyp);

    double netprofit = 0;
    int i = 0;

    while(remweight > 0 && i < n) {
        if(o[i].weight <= remweight) {
            netprofit += o[i].profit;
            remweight -= o[i].weight;
        } else {
            netprofit += (remweight / o[i].weight) * o[i].profit;
            remweight = 0;
        }
        i++;
    }
    return netprofit;
}

double greedyWeight(object o[], int n, double remweight) {
    sort(o, o + n, comparebyw);

    double netprofit = 0;
    int i = 0;

    while(remweight > 0 && i < n) {
        if(o[i].weight <= remweight) {
            netprofit += o[i].profit;
            remweight -= o[i].weight;
        } else {
            netprofit += (remweight / o[i].weight) * o[i].profit;
            remweight = 0;
        }
        i++;
    }
    return netprofit;
}
void runbenchmark() {
    int iterations = 100;
    int capacity = 200;

    for(int i = 5; i <= iterations; i += 5) {

        object base[100], o1[100], o2[100], o3[100];

        makeobject(base, i, capacity);
        for(int j = 0; j < i; j++) {
            o1[j] = base[j];
            o2[j] = base[j];
            o3[j] = base[j];
        }

        double r = greedyRatio(o1, i, capacity);
        double w = greedyWeight(o2, i, capacity);
        double p = greedyProfit(o3, i, capacity);

        cout << "\nObjects: " << i << endl;
        cout << "Profit (Ratio): " << r << endl;
        cout << "Profit (Weight): " << w << endl;
        cout << "Profit (Profit): " << p << endl;
    }
}

int main() {
    srand(time(0)); 
    runbenchmark();
    return 0;
}
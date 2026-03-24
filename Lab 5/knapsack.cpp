#include<iostream>
#include<algorithm>
#include<random>
using namespace std;
struct object{
    int id;
    double profit;
    double weight;
};
void makeobject(object o[],int n,int capacity){
    for(int i=0;i<n;i++){
        o[i].id=i;
        o[i].profit=rand()%capacity+1;
        o[i].weight=rand()%capacity+1;
    }
}
bool comparebyr(object a,object b){
    double r1=(double)a.profit/a.weight;
    double r2=(double)b.profit/b.weight;
    return r1>r2;
}
bool comparebyp(object a,object b){
    double r1=(double)a.profit;
    double r2=(double)b.profit;
    return r1>r2;
}
bool comparebyw(object a,object b){
    double r1=(double)a.weight;
    double r2=(double)b.weight;
    return r1<r2;
}

double greedyknapsackforr(object o[],int n,double remweight){
    double netprofit=0;
    int i=0;
    sort(o,o+n,comparebyr);
    while(remweight!=0 &&i<n){
        if(o[i].weight<remweight){
            netprofit+=o[i].profit;
            remweight-=o[i].weight;
        }
        else{
            netprofit+=(double)(remweight/o[i].weight)*o[i].profit;
            remweight=0;
        }
        i++;
    }
    return netprofit;
}
double greedyknapsackforp(object o[],int n,double remweight){
    double netprofit=0;
    int i=0;
    sort(o,o+n,comparebyp);
    while(remweight!=0 &&i<n){
        if(o[i].weight<remweight){
            netprofit+=o[i].profit;
            remweight-=o[i].weight;
        }
        else{
            netprofit+=(double)(remweight/o[i].weight)*o[i].profit;
            remweight=0;
        }
        i++;
    }
    return netprofit;
}
double greedyknapsackforw(object o[],int n,double remweight){
    double netprofit=0;
    int i=0;
    sort(o,o+n,comparebyw);
    while(remweight!=0 &&i<n){
        if(o[i].weight<remweight){
            netprofit+=o[i].profit;
            remweight-=o[i].weight;
        }
        else{
            netprofit+=(double)(remweight/o[i].weight)*o[i].profit;
            remweight=0;
        }
        i++;
    }
    return netprofit;
}
void runbenchmark(){
    object o[100];
    int iterations=100;
    double capacity=200;
    double profitbyr[100];
    double profitbyw[100];
    double profitbyp[100];
    for(int i=5;i<iterations;i=i+5){
        makeobject(o,i,capacity);
        profitbyr[i]=greedyknapsackforr(o,i,200);
        cout<<"Profit by ratio of profit and weight for "<<i<<" objects : "<<profitbyr[i]<<endl;
        profitbyw[i]=greedyknapsackforw(o,i,200);
        cout<<"Profit by weight for "<<i<<" objects : "<<profitbyw[i]<<endl;
        profitbyp[i]=greedyknapsackforp(o,i,200);
        cout<<"Profit by ratio of profit for"<<i<<" objects : "<<profitbyp[i]<<endl;

    }

    // if(profitbyw/100 > profitbyr/100 && profitbyw/100 > profitbyp/100){
    //     cout<<"Profit by weight is maximum !"<<endl;
    // }
    // else if(profitbyw/100 > profitbyr/100 && profitbyw/100< profitbyp){
    //     cout<<"Profit by profit is maximum !"<<endl;
    // }
    // else{
    //     cout<<"Profit by ratio of profitbyweight is maximum !"<<endl;

    // }

}
int main(){
   runbenchmark();
}
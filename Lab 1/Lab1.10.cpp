#include <iostream>
#include <string>

using namespace std;

void generateTruthTable(int n, string current) {
    
    if (current.length()== n) {
        cout << current << endl;
        return;
    }
    generateTruthTable(n, current + "T");
    generateTruthTable(n, current + "F");
}

int main() {
    int n;
    cout << "Enter number of variables (n): ";
    cin >> n;
    generateTruthTable(n, "");

    return 0;
}
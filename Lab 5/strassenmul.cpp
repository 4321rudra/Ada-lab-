#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> Matrix;
Matrix add(Matrix A, Matrix B, int n) {
    Matrix C(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}
Matrix subtract(Matrix A, Matrix B, int n) {
    Matrix C(n, vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}
Matrix strassen(Matrix A, Matrix B, int n) {
    if(n % 2 != 0) {
        Matrix Anew(n+1, vector<int>(n+1, 0));
        Matrix Bnew(n+1, vector<int>(n+1, 0));

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) {
                Anew[i][j] = A[i][j];
                Bnew[i][j] = B[i][j];
            }
        Matrix Cnew = strassen(Anew, Bnew, n+1);
        Matrix C(n, vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                C[i][j] = Cnew[i][j];
        return C;
    }
    if(n == 2) {
        Matrix C(2, vector<int>(2));

        int a=A[0][0], b=A[0][1], c=A[1][0], d=A[1][1];
        int e=B[0][0], f=B[0][1], g=B[1][0], h=B[1][1];

        int M1 = (a+d)*(e+h);
        int M2 = (c+d)*e;
        int M3 = a*(f-h);
        int M4 = d*(g-e);
        int M5 = (a+b)*h;
        int M6 = (c-a)*(e+f);
        int M7 = (b-d)*(g+h);

        C[0][0] = M1 + M4 - M5 + M7;
        C[0][1] = M3 + M5;
        C[1][0] = M2 + M4;
        C[1][1] = M1 - M2 + M3 + M6;

        return C;
    }

    int k = n/2;

    Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k)),
           A21(k, vector<int>(k)), A22(k, vector<int>(k));
    Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k)),
           B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }

    Matrix M1 = strassen(add(A11,A22,k), add(B11,B22,k), k);
    Matrix M2 = strassen(add(A21,A22,k), B11, k);
    Matrix M3 = strassen(A11, subtract(B12,B22,k), k);
    Matrix M4 = strassen(A22, subtract(B21,B11,k), k);
    Matrix M5 = strassen(add(A11,A12,k), B22, k);
    Matrix M6 = strassen(subtract(A21,A11,k), add(B11,B12,k), k);
    Matrix M7 = strassen(subtract(A12,A22,k), add(B21,B22,k), k);

    Matrix C(n, vector<int>(n));

    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j+k] = M3[i][j] + M5[i][j];
            C[i+k][j] = M2[i][j] + M4[i][j];
            C[i+k][j+k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }

    return C;
}
int main() {

    int n = 4;

    Matrix A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3},
        {4, 5, 6, 7}
    };
    Matrix B = {
        {7, 6, 5, 4},
        {3, 2, 1, 0},
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };

    Matrix C = strassen(A, B, n);

    cout << "Result Matrix:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
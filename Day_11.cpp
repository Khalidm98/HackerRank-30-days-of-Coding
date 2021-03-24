#include <iostream>
using namespace std;

int main(){
    unsigned short n = 6;
    short A[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    int MAX = INT_MIN;
    for (int i = 1; i < n-1; i++)
        for (int j = 1; j < n-1; j++){
            int I = A[i-1][j-1] + A[i-1][j] + A[i-1][j+1];
            I += A[i][j] + A[i+1][j-1] + A[i+1][j] + A[i+1][j+1];
            if (I > MAX)
            	MAX = I;
        }
    cout << MAX << endl;
    return 0;
}

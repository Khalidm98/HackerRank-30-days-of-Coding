#include <iostream>

using namespace std;

// float has very big upper limit
float factorial(unsigned short n) {
    if (n < 2) return 1;
    else return n * factorial(n - 1);
}

int main() {
    unsigned short n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}

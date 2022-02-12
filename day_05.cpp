#include <iostream>

using namespace std;

int main() {
    unsigned short n, sum = 0;
    cin >> n;
    for (size_t i = 1; i <= 10; i++) {
        sum += n;
        cout << n << " x " << i << " = " << sum << endl;
    }
    return 0;
}

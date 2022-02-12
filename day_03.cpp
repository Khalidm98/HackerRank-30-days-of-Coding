#include <iostream>

using namespace std;

int main() {
    unsigned short n;
    cin >> n;
    if (n % 2 == 1 || (n >= 6 && n <= 20)) cout << "Weird";
    else cout << "Not Weird";
    return 0;
}

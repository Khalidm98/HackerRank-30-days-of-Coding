#include <iostream>
using namespace std;

int main(){
    unsigned short n;
    cin >> n;
    for (size_t i = 1; i <= 10; i++)
        cout << n << " x " << i << " = " << n*i << endl;
    return 0;
}

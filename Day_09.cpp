#include <iostream>
using namespace std;

float factorial(unsigned short n){		// float has very big upper limit
    if (n < 2)			return 1;
    else				return n * factorial(n-1);
}

int main()
{
    unsigned short n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}

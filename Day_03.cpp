#include <iostream>
using namespace std;

int main(){
    unsigned short N;
    cin >> N;
    if (N % 2 == 1 || (N >= 6 && N <= 20))		cout << "Weird";
    else										cout << "Not Weird";
    return 0;
}

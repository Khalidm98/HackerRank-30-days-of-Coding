#include <cmath>
#include <iostream>
using namespace std;

int main(){
	unsigned long T, n;
	cin >> T;
	while (T--){
		cin >> n;
		if (n < 2){
			cout << "Not prime" << endl;
			continue;
		}

		bool prime = true;
		for (unsigned long i = 2; i <= sqrt(n); ++i){
			if (n % i == 0){
				cout << "Not prime" << endl;
				prime = false;
				break;
			}
		}
		if (prime)
			cout << "Prime" << endl;
	}
    return 0;
}

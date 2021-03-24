#include <string>
#include <iostream>
using namespace std;

int main(){
    unsigned long dec;
    cin >> dec;
    string bin;
    while (dec > 0){
        bin.insert(0, dec%2 ? "1":"0");
        dec /= 2;
    }

    int max_ones = 0, ones = 0;
    for (size_t i = 0; i < bin.length(); i++){
        if (bin[i] == '1')
            ++ones;

        else {
            if (ones > max_ones)
            	max_ones = ones;
            ones = 0;
        }
    }
    if (ones > max_ones)
    	max_ones = ones;
    cout << max_ones << endl;
    return 0;
}

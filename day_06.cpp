#include <iostream>
#include <string>

using namespace std;

int main() {
    unsigned short T;
    string s;
    cin >> T;
    for (size_t i = 0; i < T; i++) {
        cin >> s;
        for (size_t j = 0; j < s.length(); j += 2) cout << s[j];
        cout << " ";
        for (size_t j = 1; j < s.length(); j += 2) cout << s[j];
        cout << endl;
    }
    return 0;
}

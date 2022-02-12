#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    try {
        int i = stoi(s);
        cout << i;
    }
    catch (const invalid_argument &ia) {
        cerr << "Bad String";
    }
    return 0;
}

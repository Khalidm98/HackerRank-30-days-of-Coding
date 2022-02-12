#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    unsigned long n;
    string key, val, query;
    map<string, string> contacts;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> key >> val;
        contacts[key] = val;
    }

    while (cin >> query) {
        auto it = contacts.find(query);
        if (it == contacts.end()) cout << "Not found\n";
        else cout << query << "=" << contacts.find(query)->second << endl;
    }
    return 0;
}

#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(){
    unsigned long n;
    string key, val, query;
    map<string, string> contacts;
    cin >> n;
    for (size_t i = 0; i < n; i++){
        cin >> key >> val;
        contacts[key] = val;
    }

    while(cin >> query){
        if (contacts.count(query) == 1)
            cout << query << "=" << contacts.find(query)->second << endl;
        else
            cout << "Not found\n";
    }
    return 0;
}

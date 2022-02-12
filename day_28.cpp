#include <algorithm>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> gmail(0);
    unsigned short N;
    cin >> N;
    vector<map<string, string>> db(N);
    for (auto row: db) {
        cin >> row["name"] >> row["email"];
        if (regex_match(row["email"], regex("[a-z.]+@gmail.com")))
            gmail.push_back(row["name"]);
    }
    sort(gmail.begin(), gmail.end());
    for (const string &name: gmail)
        cout << name << endl;
    return 0;
}

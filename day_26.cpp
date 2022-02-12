#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, unsigned short> ret, due;
    cin >> ret["day"] >> ret["month"] >> ret["year"];
    cin >> due["day"] >> due["month"] >> due["year"];

    if (ret["year"] > due["year"])
        cout << 10000;
    else if (ret["year"] < due["year"])
        cout << 0;
    else {
        if (ret["month"] > due["month"])
            cout << 500 * (ret["month"] - due["month"]);
        else if (ret["month"] < due["month"])
            cout << 0;
        else {
            if (ret["day"] > due["day"])
                cout << 15 * (ret["day"] - due["day"]);
            else
                cout << 0;
        }
    }
    return 0;
}

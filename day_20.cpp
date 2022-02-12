#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned short n;
    cin >> n;
    vector<unsigned long> a(n);
    for (size_t i = 0; i < n; ++i)
        cin >> a[i];

    unsigned long numSwaps = 0;
    for (int i = 0; i < n - 1; ++i) {
        int numberOfSwaps = 0;
        for (int j = 0; j < n - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                numberOfSwaps++;
            }
        }
        if (numberOfSwaps == 0)
            break;
        numSwaps += numberOfSwaps;
    }

    cout << "Array is sorted in " << numSwaps << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n - 1] << endl;
    return 0;
}

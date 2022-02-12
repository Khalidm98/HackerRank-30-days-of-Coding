#include <iostream>

using namespace std;

int bitwiseAnd(int N, int K) {
    int MAX = 0;
    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            int OR = i & j;
            if (OR > MAX && OR < K)
                MAX = OR;
        }
    }
    return MAX;
}

int main() {
    unsigned short T, N, K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        cout << bitwiseAnd(N, K) << endl;
    }
    return 0;
}

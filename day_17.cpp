#include <iostream>

using namespace std;

class Negative : public exception {
public:
    Negative() = default;

    const char *what() const noexcept override {
        return "n and p should be non-negative";
    }

    ~Negative() override = default;
};

class Zero : public exception {
public:
    Zero() = default;

    const char *what() const noexcept override {
        return "Undefined Value";
    }

    ~Zero() override = default;
};

class Calculator {
public:
    int power(int base, int P) {
        if (base < 0 || P < 0)
            throw Negative{};
        if (base == 0 && P == 0)
            throw Zero{};
        if (base == 0)
            return 0;
        if (base == 1 || P == 0)
            return 1;
        if (P == 1)
            return base;
        return base * power(base, P - 1);
    }
};

int main() {
    Calculator myCalculator = Calculator();
    int T, n, p;
    cin >> T;
    while (T--) {
        if (scanf("%d %d", &n, &p) == 2) {
            try {
                int ans = myCalculator.power(n, p);
                cout << ans << endl;
            }
            catch (exception &e) {
                cout << e.what() << endl;
            }
        }
    }
}

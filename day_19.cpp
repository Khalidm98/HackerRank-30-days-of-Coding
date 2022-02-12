#include <iostream>

using namespace std;

class AdvancedArithmetic {
public:
    virtual int divisorSum(int n) = 0;

    virtual ~AdvancedArithmetic() = default;
};

class Calculator : public AdvancedArithmetic {
public:
    int divisorSum(int n) override {
        if (n == 1)
            return 1;

        int sum = n + 1;
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0)
                sum += i;
        }
        return sum;
    }
};

int main() {
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator();
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;
    delete myCalculator;
    return 0;
}

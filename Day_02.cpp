#include <iomanip>
#include <iostream>
using namespace std;

void solve(double meal_cost, int tip_percent, int tax_percent){
    cout << fixed << setprecision(0) << ((tip_percent + tax_percent)/100.0 + 1) * meal_cost;
}

int main()
{
    double meal_cost;
    int tip_percent, tax_percent;
    cin >> meal_cost >> tip_percent >> tax_percent;
    solve(meal_cost, tip_percent, tax_percent);
    return 0;
}

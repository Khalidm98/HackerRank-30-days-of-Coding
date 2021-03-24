#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class Difference {
	vector<int> elements;

public:
	unsigned short maximumDifference;

	Difference(vector<int> &elements)
	: elements(elements.begin(), elements.end()), maximumDifference(0) {}

	void computeDifference(){
		for (size_t i = 0; i < elements.size()-1; ++i)
			for (size_t j = i+1; j < elements.size(); ++j)
				if (fabs(elements[i] - elements[j]) > maximumDifference)
					maximumDifference = fabs(elements[i]-elements[j]);
	}
};

int main(){
    int N;
    cin >> N;
    vector<int> a;
    for (int i = 0; i < N; i++){
        int e;
        cin >> e;
        a.push_back(e);
    }
    Difference d(a);
    d.computeDifference();
    cout << d.maximumDifference;
    return 0;
}

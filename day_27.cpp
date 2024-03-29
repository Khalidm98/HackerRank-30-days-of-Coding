#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int minimum_index(vector<int> seq) {
    if (seq.empty()) {
        throw invalid_argument("Cannot get the minimum value index from an empty sequence");
    }
    int min_idx = 0;
    for (int i = 1; i < seq.size(); ++i) {
        if (seq[i] < seq[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

class TestDataEmptyArray {
public:
    static vector<int> get_array() {
        return {};
    }
};

class TestDataUniqueValues {
public:
    static vector<int> get_array() {
        int arr[] = {5, 7, 9, 1, 6, 4};
        vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
        return v;
    }

    static int get_expected_result() {
        return 3;
    }
};

class TestDataExactlyTwoDifferentMinimums {
public:
    static vector<int> get_array() {
        int arr[] = {2, 4, 1, 9, 7, 1};
        vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
        return v;
    }

    static int get_expected_result() {
        return 2;
    }
};

void TestWithEmptyArray() {
    try {
        auto seq = TestDataEmptyArray::get_array();
        minimum_index(seq);
    } catch (invalid_argument &e) {
        return;
    }
    assert(false);
}

void TestWithUniqueValues() {
    auto seq = TestDataUniqueValues::get_array();
    assert(seq.size() >= 2);

    assert(set<int>(seq.begin(), seq.end()).size() == seq.size());

    auto expected_result = TestDataUniqueValues::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

void TestWithExactlyTwoDifferentMinimums() {
    auto seq = TestDataExactlyTwoDifferentMinimums::get_array();
    assert(seq.size() >= 2);

    auto tmp = seq;
    sort(tmp.begin(), tmp.end());
    assert(tmp[0] == tmp[1] and (tmp.size() == 2 or tmp[1] < tmp[2]));

    auto expected_result = TestDataExactlyTwoDifferentMinimums::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

int main() {
    TestWithEmptyArray();
    TestWithUniqueValues();
    TestWithExactlyTwoDifferentMinimums();
    cout << "OK" << endl;
    return 0;
}

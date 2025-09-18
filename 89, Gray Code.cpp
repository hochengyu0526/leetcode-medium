#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result = {0};
        for(int i = 0; i < n; i++){
            int add = 1 << i;
            int size = result.size();
            for(int j = size - 1; j >= 0; j--){
                result.push_back(result[j] | add);
            }
        }
        return result;
    }
};

// Helper function to print a vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution s;

    // LeetCode default test case 1: n = 2
    cout << "Test Case 1:" << endl;
    int n1 = 2;
    cout << "n = " << n1 << endl;
    cout << "Gray Code: ";
    printVector(s.grayCode(n1));
    cout << "Expected: [0, 1, 3, 2]" << endl;
    cout << endl;

    // LeetCode default test case 2: n = 1
    cout << "Test Case 2:" << endl;
    int n2 = 1;
    cout << "n = " << n2 << endl;
    cout << "Gray Code: ";
    printVector(s.grayCode(n2));
    cout << "Expected: [0, 1]" << endl;
    cout << endl;

    // LeetCode custom test case 3: n = 3
    cout << "Test Case 3:" << endl;
    int n3 = 3;
    cout << "n = " << n3 << endl;
    cout << "Gray Code: ";
    printVector(s.grayCode(n3));
    cout << "Expected: [0, 1, 3, 2, 6, 7, 5, 4]" << endl;
    cout << endl;

    return 0;
}
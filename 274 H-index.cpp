#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        for (int i = 1; i <= citations.size(); i++) {
            int count = 0;
            for (int j = 0; j < citations.size(); j++) {
                if (citations[j] >= i) {
                    count++;
                }
                if (count >= i) {
                    h = i; // Update h to the current valid h-index
                    break;
                }
            }
        }
        return h;
    }
};

void printResult(const string& testCase, int result) {
    cout << "Test Case: " << testCase << endl;
    cout << "H-Index: " << result << endl;
    cout << "--------------------" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    vector<int> citations1 = {3, 0, 6, 1, 5};
    cout << "Input: {3, 0, 6, 1, 5}" << endl;
    printResult("", solution.hIndex(citations1)); // Expected: 3

    // Test case 2 from LeetCode
    vector<int> citations2 = {1, 3, 1};
    cout << "Input: {1, 3, 1}" << endl;
    printResult("", solution.hIndex(citations2)); // Expected: 1
    
    // Test case 3
    vector<int> citations3 = {100};
    cout << "Input: {100}" << endl;
    printResult("", solution.hIndex(citations3)); // Expected: 1
    
    return 0;
}
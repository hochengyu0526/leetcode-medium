#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, current, 1, n, k);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& current, int start, int n, int k) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }
        for (int i = start; i <= n; i++) {
            current.push_back(i);
            backtrack(result, current, i + 1, n, k);
            current.pop_back();
        }
    }
};

// Helper function to print a vector of vectors
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << (j == result[i].size() - 1 ? "" : ", ");
        }
        cout << "]" << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution s;

    // LeetCode default test case 1: n = 4, k = 2
    cout << "Test Case 1:" << endl;
    int n1 = 4, k1 = 2;
    cout << "n = " << n1 << ", k = " << k1 << endl;
    vector<vector<int>> result1 = s.combine(n1, k1);
    cout << "Expected Output (order may vary): [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]" << endl;
    cout << "Your Output: ";
    printResult(result1);
    cout << endl;

    // LeetCode default test case 2: n = 1, k = 1
    cout << "Test Case 2:" << endl;
    int n2 = 1, k2 = 1;
    cout << "n = " << n2 << ", k = " << k2 << endl;
    vector<vector<int>> result2 = s.combine(n2, k2);
    cout << "Expected Output: [[1]]" << endl;
    cout << "Your Output: ";
    printResult(result2);
    cout << endl;
    
    // LeetCode custom test case 3: n = 3, k = 3
    cout << "Test Case 3:" << endl;
    int n3 = 3, k3 = 3;
    cout << "n = " << n3 << ", k = " << k3 << endl;
    vector<vector<int>> result3 = s.combine(n3, k3);
    cout << "Expected Output: [[1,2,3]]" << endl;
    cout << "Your Output: ";
    printResult(result3);
    cout << endl;

    return 0;
}
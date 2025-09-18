#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, n, n);
        return result;
    }
private:
    void backtrack(vector<string>& result, string& current, int left, int right) {
        if (left == 0 && right == 0) {
            result.push_back(current);
            return;
        }
        if (left > 0) {
            current.push_back('(');
            backtrack(result, current, left - 1, right);
            current.pop_back();
        }
        if (right > left) {
            current.push_back(')');
            backtrack(result, current, left, right - 1);
            current.pop_back();
        }
    }
};

// Helper function to print a vector of strings
void printVector(const vector<string>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << "\"" << v[i] << "\"" << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution s;

    // LeetCode default test case 1: n = 3
    cout << "Test Case 1:" << endl;
    int n1 = 3;
    cout << "n = " << n1 << endl;
    vector<string> result1 = s.generateParenthesis(n1);
    cout << "Output:" << endl;
    printVector(result1);
    cout << "Expected: [\"((()))\",\"(()())\",\"(())()\",\"()(())\",\"()()()\"] (order may vary)" << endl;
    cout << endl;

    // LeetCode default test case 2: n = 1
    cout << "Test Case 2:" << endl;
    int n2 = 1;
    cout << "n = " << n2 << endl;
    vector<string> result2 = s.generateParenthesis(n2);
    cout << "Output:" << endl;
    printVector(result2);
    cout << "Expected: [\"()\"]" << endl;
    cout << endl;

    return 0;
}
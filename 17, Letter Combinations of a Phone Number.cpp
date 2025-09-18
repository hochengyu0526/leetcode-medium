#include <iostream>
#include <vector>
#include <string>
#include <functional> // For std::function

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string combination;

        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) {
                result.push_back(combination);
                return;
            }
            string letters = phone[digits[index] - '0'];
            for (char letter : letters) {
                combination.push_back(letter);
                backtrack(index + 1);
                combination.pop_back(); // Backtrack
            }
        };

        backtrack(0);
        return result;
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

    // LeetCode default test case 1: digits = "23"
    cout << "Test Case 1:" << endl;
    string digits1 = "23";
    cout << "Input: \"" << digits1 << "\"" << endl;
    vector<string> result1 = s.letterCombinations(digits1);
    cout << "Output:" << endl;
    printVector(result1);
    cout << "Expected: [\"ad\",\"ae\",\"af\",\"bd\",\"be\",\"bf\",\"cd\",\"ce\",\"cf\"] (order may vary)" << endl;
    cout << endl;

    // LeetCode default test case 2: digits = ""
    cout << "Test Case 2:" << endl;
    string digits2 = "";
    cout << "Input: \"" << digits2 << "\"" << endl;
    vector<string> result2 = s.letterCombinations(digits2);
    cout << "Output:" << endl;
    printVector(result2);
    cout << "Expected: []" << endl;
    cout << endl;

    // LeetCode default test case 3: digits = "2"
    cout << "Test Case 3:" << endl;
    string digits3 = "2";
    cout << "Input: \"" << digits3 << "\"" << endl;
    vector<string> result3 = s.letterCombinations(digits3);
    cout << "Output:" << endl;
    printVector(result3);
    cout << "Expected: [\"a\",\"b\",\"c\"]" << endl;
    cout << endl;

    return 0;
}
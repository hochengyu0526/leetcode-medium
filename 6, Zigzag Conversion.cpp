#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string result = "";
        int cycleLen = 2 * numRows - 2;

        for (int row = 0; row < numRows; ++row) {
            for (int j = 0; j + row < s.size(); ++j) {
                // Add character from the main downward path
                int index = j + row;
                if (index < s.size()) {
                    result += s[index];
                }
                
                // For middle rows, add character from the diagonal path
                if (row != 0 && row != numRows - 1) {
                    int diagonal_index = j + cycleLen - row;
                    if (diagonal_index < s.size()) {
                        result += s[diagonal_index];
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: s = "PAYPALISHIRING", numRows = 3
    cout << "Test Case 1:" << endl;
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << "Input string: \"" << s1 << "\", numRows: " << numRows1 << endl;
    cout << "Result: \"" << s.convert(s1, numRows1) << "\"" << endl;
    cout << "Expected: \"PAHNAPLSIIGYIR\"" << endl;
    cout << endl;

    // LeetCode default test case 2: s = "PAYPALISHIRING", numRows = 4
    cout << "Test Case 2:" << endl;
    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    cout << "Input string: \"" << s2 << "\", numRows: " << numRows2 << endl;
    cout << "Result: \"" << s.convert(s2, numRows2) << "\"" << endl;
    cout << "Expected: \"PINALSIGYAHRPI\"" << endl;
    cout << endl;

    // LeetCode default test case 3: s = "A", numRows = 1
    cout << "Test Case 3:" << endl;
    string s3 = "A";
    int numRows3 = 1;
    cout << "Input string: \"" << s3 << "\", numRows: " << numRows3 << endl;
    cout << "Result: \"" << s.convert(s3, numRows3) << "\"" << endl;
    cout << "Expected: \"A\"" << endl;
    cout << endl;

    return 0;
}
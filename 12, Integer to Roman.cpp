#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = "";
        
        for (size_t i = 0; i < values.size() && num > 0; ++i) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }
        
        return result;
    }
};

// Main function for testing
int main() {
    Solution s;

    // LeetCode default test case 1: num = 3
    cout << "Test Case 1:" << endl;
    int num1 = 3;
    cout << "Input: " << num1 << endl;
    cout << "Result: \"" << s.intToRoman(num1) << "\"" << endl;
    cout << "Expected: \"III\"" << endl;
    cout << endl;

    // LeetCode default test case 2: num = 58
    cout << "Test Case 2:" << endl;
    int num2 = 58;
    cout << "Input: " << num2 << endl;
    cout << "Result: \"" << s.intToRoman(num2) << "\"" << endl;
    cout << "Expected: \"LVIII\"" << endl;
    cout << endl;

    // LeetCode default test case 3: num = 1994
    cout << "Test Case 3:" << endl;
    int num3 = 1994;
    cout << "Input: " << num3 << endl;
    cout << "Result: \"" << s.intToRoman(num3) << "\"" << endl;
    cout << "Expected: \"MCMXCIV\"" << endl;
    cout << endl;

    // Custom test case 4: num = 2
    cout << "Test Case 4:" << endl;
    int num4 = 2;
    cout << "Input: " << num4 << endl;
    cout << "Result: \"" << s.intToRoman(num4) << "\"" << endl;
    cout << "Expected: \"II\"" << endl;
    cout << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long long result = 0;
        int sign = 1;

        // Step 1: Discard leading whitespace
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3 & 4: Read digits and convert with overflow check
        while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Overflow check
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        // Step 5: Apply sign and return
        return result * sign;
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: "42"
    cout << "Test Case 1:" << endl;
    string input1 = "42";
    cout << "Input: \"" << input1 << "\"" << endl;
    cout << "Result: " << s.myAtoi(input1) << endl;
    cout << "Expected: 42" << endl;
    cout << endl;

    // LeetCode default test case 2: "   -42"
    cout << "Test Case 2:" << endl;
    string input2 = "   -42";
    cout << "Input: \"" << input2 << "\"" << endl;
    cout << "Result: " << s.myAtoi(input2) << endl;
    cout << "Expected: -42" << endl;
    cout << endl;

    // LeetCode default test case 3: "4193 with words"
    cout << "Test Case 3:" << endl;
    string input3 = "4193 with words";
    cout << "Input: \"" << input3 << "\"" << endl;
    cout << "Result: " << s.myAtoi(input3) << endl;
    cout << "Expected: 4193" << endl;
    cout << endl;

    // LeetCode default test case 4: "words and 987"
    cout << "Test Case 4:" << endl;
    string input4 = "words and 987";
    cout << "Input: \"" << input4 << "\"" << endl;
    cout << "Result: " << s.myAtoi(input4) << endl;
    cout << "Expected: 0" << endl;
    cout << endl;
    
    // LeetCode default test case 5: "-91283472332" (overflow)
    cout << "Test Case 5 (Overflow):" << endl;
    string input5 = "-91283472332";
    cout << "Input: \"" << input5 << "\"" << endl;
    cout << "Result: " << s.myAtoi(input5) << endl;
    cout << "Expected: -2147483648 (INT_MIN)" << endl;
    cout << endl;

    return 0;
}
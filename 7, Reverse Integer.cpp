#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long reversed_num = 0;
        int original_num = x;

        while (original_num != 0) {
            int digit = original_num % 10;
            reversed_num = reversed_num * 10 + digit;
            original_num /= 10;
        }

        if (reversed_num > INT_MAX || reversed_num < INT_MIN) {
            return 0;
        }

        return static_cast<int>(reversed_num);
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: x = 123
    cout << "Test Case 1:" << endl;
    int x1 = 123;
    cout << "Input: " << x1 << endl;
    cout << "Result: " << s.reverse(x1) << endl;
    cout << "Expected: 321" << endl;
    cout << endl;

    // LeetCode default test case 2: x = -123
    cout << "Test Case 2:" << endl;
    int x2 = -123;
    cout << "Input: " << x2 << endl;
    cout << "Result: " << s.reverse(x2) << endl;
    cout << "Expected: -321" << endl;
    cout << endl;

    // LeetCode default test case 3: x = 120
    cout << "Test Case 3:" << endl;
    int x3 = 120;
    cout << "Input: " << x3 << endl;
    cout << "Result: " << s.reverse(x3) << endl;
    cout << "Expected: 21" << endl;
    cout << endl;

    // LeetCode default test case 4: x = 1534236469 (overflow case)
    cout << "Test Case 4 (Overflow):" << endl;
    int x4 = 1534236469;
    cout << "Input: " << x4 << endl;
    cout << "Result: " << s.reverse(x4) << endl;
    cout << "Expected: 0" << endl;
    cout << endl;

    // LeetCode default test case 5: x = -2147483648 (INT_MIN)
    cout << "Test Case 5 (INT_MIN):" << endl;
    int x5 = -2147483648;
    cout << "Input: " << x5 << endl;
    cout << "Result: " << s.reverse(x5) << endl;
    cout << "Expected: 0" << endl;
    cout << endl;

    return 0;
}
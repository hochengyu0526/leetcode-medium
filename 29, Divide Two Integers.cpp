#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge case for integer overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        if (ldividend < ldivisor) {
            return 0;
        }

        long long result = 0;
        while (ldividend >= ldivisor) {
            long long temp_divisor = ldivisor;
            long long multiple = 1;
            while (ldividend >= (temp_divisor << 1)) {
                temp_divisor <<= 1;
                multiple <<= 1;
            }
            ldividend -= temp_divisor;
            result += multiple;
        }

        return isNegative ? -result : result;
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: dividend = 10, divisor = 3
    cout << "Test Case 1:" << endl;
    int dividend1 = 10, divisor1 = 3;
    cout << "10 / 3 = " << s.divide(dividend1, divisor1) << endl;
    cout << "Expected: 3" << endl;
    cout << endl;

    // LeetCode default test case 2: dividend = 7, divisor = -3
    cout << "Test Case 2:" << endl;
    int dividend2 = 7, divisor2 = -3;
    cout << "7 / -3 = " << s.divide(dividend2, divisor2) << endl;
    cout << "Expected: -2" << endl;
    cout << endl;

    // LeetCode edge case: INT_MIN / -1
    cout << "Test Case 3 (Edge Case):" << endl;
    int dividend3 = INT_MIN, divisor3 = -1;
    cout << "-2147483648 / -1 = " << s.divide(dividend3, divisor3) << endl;
    cout << "Expected: 2147483647 (INT_MAX)" << endl;
    cout << endl;
    
    // Custom test case: a large division
    cout << "Test Case 4 (Large Division):" << endl;
    int dividend4 = 2147483647, divisor4 = 2;
    cout << "2147483647 / 2 = " << s.divide(dividend4, divisor4) << endl;
    cout << "Expected: 1073741823" << endl;
    cout << endl;

    return 0;
}
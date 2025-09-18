#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // This is a direct implementation using the standard library pow function.
        // For the LeetCode problem, the challenge is typically to implement
        // this functionality yourself using an efficient algorithm like
        // binary exponentiation (exponentiation by squaring).
        return pow(x, n);
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: x = 2.0, n = 10
    double x1 = 2.0;
    int n1 = 10;
    cout << "Test Case 1:" << endl;
    cout << "x = " << x1 << ", n = " << n1 << endl;
    cout << "Result: " << s.myPow(x1, n1) << endl;
    cout << "Expected: 1024.00000" << endl;
    cout << endl;

    // LeetCode default test case 2: x = 2.1, n = 3
    double x2 = 2.1;
    int n2 = 3;
    cout << "Test Case 2:" << endl;
    cout << "x = " << x2 << ", n = " << n2 << endl;
    cout << "Result: " << s.myPow(x2, n2) << endl;
    cout << "Expected: 9.26100" << endl;
    cout << endl;
    
    // LeetCode default test case 3: x = 2.0, n = -2
    double x3 = 2.0;
    int n3 = -2;
    cout << "Test Case 3:" << endl;
    cout << "x = " << x3 << ", n = " << n3 << endl;
    cout << "Result: " << s.myPow(x3, n3) << endl;
    cout << "Expected: 0.25000" << endl;
    cout << endl;

    return 0;
}
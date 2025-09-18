#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize the first row and first column
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: m = 3, n = 7
    cout << "Test Case 1:" << endl;
    int m1 = 3, n1 = 7;
    cout << "m = " << m1 << ", n = " << n1 << endl;
    cout << "Number of unique paths: " << s.uniquePaths(m1, n1) << endl;
    cout << "Expected: 28" << endl;
    cout << endl;

    // LeetCode default test case 2: m = 3, n = 2
    cout << "Test Case 2:" << endl;
    int m2 = 3, n2 = 2;
    cout << "m = " << m2 << ", n = " << n2 << endl;
    cout << "Number of unique paths: " << s.uniquePaths(m2, n2) << endl;
    cout << "Expected: 3" << endl;
    cout << endl;
    
    // LeetCode custom test case 3: m = 1, n = 1
    cout << "Test Case 3:" << endl;
    int m3 = 1, n3 = 1;
    cout << "m = " << m3 << ", n = " << n3 << endl;
    cout << "Number of unique paths: " << s.uniquePaths(m3, n3) << endl;
    cout << "Expected: 1" << endl;
    cout << endl;

    return 0;
}
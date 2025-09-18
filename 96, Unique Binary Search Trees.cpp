#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<long long> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // j is the number of nodes in the left subtree, i-1-j is the number of nodes in the right subtree
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return (int)dp[n];
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: n = 3
    cout << "Test Case 1:" << endl;
    int n1 = 3;
    cout << "n = " << n1 << endl;
    cout << "Number of unique BSTs: " << s.numTrees(n1) << endl;
    cout << "Expected: 5" << endl;
    cout << endl;

    // LeetCode default test case 2: n = 1
    cout << "Test Case 2:" << endl;
    int n2 = 1;
    cout << "n = " << n2 << endl;
    cout << "Number of unique BSTs: " << s.numTrees(n2) << endl;
    cout << "Expected: 1" << endl;
    cout << endl;
    
    // LeetCode custom test case 3: n = 5
    cout << "Test Case 3:" << endl;
    int n3 = 5;
    cout << "n = " << n3 << endl;
    cout << "Number of unique BSTs: " << s.numTrees(n3) << endl;
    cout << "Expected: 42" << endl;
    cout << endl;

    return 0;
}
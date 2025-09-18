#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;

        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));

        // Initialization
        dp[0][0] = true;

        for (int i = 1; i <= n1; i++) {
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }

        for (int j = 1; j <= n2; j++) {
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i-1] == s3[i-1+j]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
                if (s2[j-1] == s3[i-1+j]) {
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1:
    string s1_1 = "aabcc";
    string s2_1 = "dbbca";
    string s3_1 = "aadbbcbcac";
    cout << "Test Case 1:" << endl;
    cout << "s1 = \"" << s1_1 << "\", s2 = \"" << s2_1 << "\", s3 = \"" << s3_1 << "\"" << endl;
    cout << "Is interleaving? " << (s.isInterleave(s1_1, s2_1, s3_1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;

    // LeetCode default test case 2:
    string s1_2 = "aabcc";
    string s2_2 = "dbbca";
    string s3_2 = "aadbbbaccc";
    cout << "Test Case 2:" << endl;
    cout << "s1 = \"" << s1_2 << "\", s2 = \"" << s2_2 << "\", s3 = \"" << s3_2 << "\"" << endl;
    cout << "Is interleaving? " << (s.isInterleave(s1_2, s2_2, s3_2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl;
    cout << endl;

    // LeetCode default test case 3:
    string s1_3 = "";
    string s2_3 = "";
    string s3_3 = "";
    cout << "Test Case 3:" << endl;
    cout << "s1 = \"" << s1_3 << "\", s2 = \"" << s2_3 << "\", s3 = \"" << s3_3 << "\"" << endl;
    cout << "Is interleaving? " << (s.isInterleave(s1_3, s2_3, s3_3) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;

    return 0;
}
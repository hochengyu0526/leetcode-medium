#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Initialization
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }

        // DP calculation
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: word1 = "horse", word2 = "ros"
    cout << "Test Case 1:" << endl;
    string word1_1 = "horse";
    string word2_1 = "ros";
    cout << "word1 = \"" << word1_1 << "\", word2 = \"" << word2_1 << "\"" << endl;
    cout << "Minimum distance: " << s.minDistance(word1_1, word2_1) << endl;
    cout << "Expected: 3" << endl;
    cout << endl;

    // LeetCode default test case 2: word1 = "intention", word2 = "execution"
    cout << "Test Case 2:" << endl;
    string word1_2 = "intention";
    string word2_2 = "execution";
    cout << "word1 = \"" << word1_2 << "\", word2 = \"" << word2_2 << "\"" << endl;
    cout << "Minimum distance: " << s.minDistance(word1_2, word2_2) << endl;
    cout << "Expected: 5" << endl;
    cout << endl;

    // LeetCode custom test case 3: word1 = "", word2 = ""
    cout << "Test Case 3:" << endl;
    string word1_3 = "";
    string word2_3 = "";
    cout << "word1 = \"" << word1_3 << "\", word2 = \"" << word2_3 << "\"" << endl;
    cout << "Minimum distance: " << s.minDistance(word1_3, word2_3) << endl;
    cout << "Expected: 0" << endl;
    cout << endl;

    return 0;
}
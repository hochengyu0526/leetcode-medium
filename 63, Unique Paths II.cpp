#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        // Fill the first row
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill the first column
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i - 1][0];
            }
        }

        // Fill the rest of the DP table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Helper function to print a 2D vector
void printGrid(const vector<vector<int>>& grid) {
    cout << "[" << endl;
    for (const auto& row : grid) {
        cout << "  [";
        for (size_t j = 0; j < row.size(); ++j) {
            cout << row[j] << (j == row.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution s;

    // LeetCode default test case 1:
    vector<vector<int>> obstacleGrid1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << "Test Case 1:" << endl;
    cout << "Input grid:" << endl;
    printGrid(obstacleGrid1);
    cout << "Number of unique paths: " << s.uniquePathsWithObstacles(obstacleGrid1) << endl;
    cout << "Expected: 2" << endl;
    cout << endl;

    // LeetCode default test case 2:
    vector<vector<int>> obstacleGrid2 = {{0, 1}, {0, 0}};
    cout << "Test Case 2:" << endl;
    cout << "Input grid:" << endl;
    printGrid(obstacleGrid2);
    cout << "Number of unique paths: " << s.uniquePathsWithObstacles(obstacleGrid2) << endl;
    cout << "Expected: 1" << endl;
    cout << endl;

    // Custom test case 3:
    vector<vector<int>> obstacleGrid3 = {{1}};
    cout << "Test Case 3:" << endl;
    cout << "Input grid:" << endl;
    printGrid(obstacleGrid3);
    cout << "Number of unique paths: " << s.uniquePathsWithObstacles(obstacleGrid3) << endl;
    cout << "Expected: 0" << endl;
    cout << endl;

    return 0;
}
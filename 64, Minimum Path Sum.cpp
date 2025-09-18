#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else if (i == 0) {
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                } else if (j == 0) {
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                } else {
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
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

    // LeetCode default test case 1: grid = [[1,3,1],[1,5,1],[4,2,1]]
    cout << "Test Case 1:" << endl;
    vector<vector<int>> grid1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << "Grid:" << endl;
    printGrid(grid1);
    cout << "Minimum path sum: " << s.minPathSum(grid1) << endl;
    cout << "Expected: 7 (1 -> 3 -> 1 -> 1 -> 1)" << endl;
    cout << endl;

    // LeetCode default test case 2: grid = [[1,2,3],[4,5,6]]
    cout << "Test Case 2:" << endl;
    vector<vector<int>> grid2 = {{1, 2, 3}, {4, 5, 6}};
    cout << "Grid:" << endl;
    printGrid(grid2);
    cout << "Minimum path sum: " << s.minPathSum(grid2) << endl;
    cout << "Expected: 12" << endl;
    cout << endl;

    return 0;
}
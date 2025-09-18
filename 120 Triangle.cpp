#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Handle empty triangle
        if (triangle.empty()) {
            return 0;
        }

        vector<vector<int>> dp = triangle;
        
        // Iterate from the second-to-last row up to the first row
        for (int row = triangle.size() - 2; row >= 0; --row) {
            for (int col = 0; col < triangle[row].size(); ++col) {
                // The minimum path sum to this element is itself plus the minimum
                // of the two elements below it.
                dp[row][col] += min(dp[row + 1][col], dp[row + 1][col + 1]);
            }
        }
        
        return dp[0][0];
    }
};

void printResult(const vector<vector<int>>& triangle, int result) {
    cout << "Input Triangle:" << endl;
    for (const auto& row : triangle) {
        cout << "[";
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i] << (i == row.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
    cout << "Minimum path sum: " << result << endl;
    cout << "--------------------" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    vector<vector<int>> triangle1 = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    printResult(triangle1, solution.minimumTotal(triangle1)); // Expected: 11 (2+3+5+1)

    // Test case 2
    vector<vector<int>> triangle2 = {
        {-10}
    };
    printResult(triangle2, solution.minimumTotal(triangle2)); // Expected: -10
    
    return 0;
}
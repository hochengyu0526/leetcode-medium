#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(row == 0 || col == 0){
                    dp[row][col] = matrix[row][col];
                    if(matrix[row][col] == 1)
                        count++;
                    continue;
                }
                if(matrix[row][col] == 1){
                    dp[row][col] = min({dp[row-1][col], dp[row-1][col-1], dp[row][col-1]}) + 1;
                    count += dp[row][col];
                }
                else {
                    dp[row][col] = 0;
                }
            }
        }
        return count;
    }
};

void printResult(int count) {
    cout << "The number of squares is: " << count << endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<vector<int>> matrix1 = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    cout << "Test Case 1:" << endl;
    printResult(solution.countSquares(matrix1)); // Expected output: 15
    cout << "--------------------" << endl;
    
    // Test case 2
    vector<vector<int>> matrix2 = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}
    };
    cout << "Test Case 2:" << endl;
    printResult(solution.countSquares(matrix2)); // Expected output: 7
    cout << "--------------------" << endl;

    return 0;
}
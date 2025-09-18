#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int count = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> heights(m, vector<int>(n, 0));
        
        // Step 1: Calculate consecutive 1s to the left for each cell
        for(int row = 0; row < m; ++row) {
            for(int col = 0; col < n; ++col) {
                if (mat[row][col] == 1) {
                    if (col == 0) {
                        heights[row][col] = 1;
                    } else {
                        heights[row][col] = heights[row][col-1] + 1;
                    }
                }
            }
        }
        
        // Step 2: For each cell, calculate the number of valid submatrices ending at this cell
        for(int col = 0; col < n; ++col) {
            for(int row = 0; row < m; ++row) {
                if (mat[row][col] == 1) {
                    int min_width = heights[row][col];
                    // Traverse upwards to find submatrices
                    for(int i = row; i >= 0; --i) {
                        if (mat[i][col] == 0) {
                            break;
                        }
                        min_width = min(min_width, heights[i][col]);
                        count += min_width;
                    }
                }
            }
        }
        
        return count;
    }
};

void printResult(int count) {
    cout << "The number of submatrices is: " << count << endl;
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    vector<vector<int>> mat1 = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}
    };
    cout << "Test Case 1:" << endl;
    printResult(solution.numSubmat(mat1)); // Expected output: 13
    cout << "--------------------" << endl;
    
    // Test case 2 from LeetCode
    vector<vector<int>> mat2 = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };
    cout << "Test Case 2:" << endl;
    printResult(solution.numSubmat(mat2)); // Expected output: 4
    cout << "--------------------" << endl;
    
    // Additional Test Case
    vector<vector<int>> mat3 = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };
    cout << "Test Case 3:" << endl;
    printResult(solution.numSubmat(mat3)); // Expected output: 60
    cout << "--------------------" << endl;

    return 0;
}
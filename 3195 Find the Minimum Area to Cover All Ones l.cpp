#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        if(isZeroMatrix(grid)) return 0;
        int minrow = -1, maxrow = -1, mincol = -1, maxcol = -1;
        
        for(int row = 0; row < grid.size(); ++row) {
            for(int col = 0; col < grid[row].size(); ++col) {
                if(grid[row][col] == 1) {
                    if(minrow == -1) minrow = row;
                    maxrow = row;
                    if(mincol == -1) mincol = col;
                    else if(col < mincol) mincol = col;
                    if(col > maxcol) maxcol = col;
                }
            }
        }
        
        // Handle cases where minrow, mincol, etc. might not be initialized
        if (minrow == -1) {
            return 0;
        }

        return (maxrow - minrow + 1) * (maxcol - mincol + 1);
    }
private:
    bool isZeroMatrix(const vector<vector<int>>& grid) {
        for (const auto& row : grid) {
            for (int val : row) {
                if (val) return false;
            }
        }
        return true;
    }
};

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;
    
    // Test Case 1
    vector<vector<int>> grid1 = {
        {0, 1, 0},
        {1, 0, 1}
    };
    cout << "Grid 1:" << endl;
    printGrid(grid1);
    cout << "Minimum area: " << solution.minimumArea(grid1) << endl; // Expected: 6
    cout << "--------------------" << endl;

    // Test Case 2
    vector<vector<int>> grid2 = {
        {1, 0},
        {0, 0}
    };
    cout << "Grid 2:" << endl;
    printGrid(grid2);
    cout << "Minimum area: " << solution.minimumArea(grid2) << endl; // Expected: 1
    cout << "--------------------" << endl;
    
    // Additional Test Case
    vector<vector<int>> grid3 = {
        {0, 0, 0},
        {0, 0, 0}
    };
    cout << "Grid 3:" << endl;
    printGrid(grid3);
    cout << "Minimum area: " << solution.minimumArea(grid3) << endl; // Expected: 0
    cout << "--------------------" << endl;

    return 0;
}
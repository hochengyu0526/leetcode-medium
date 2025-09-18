#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        if(grid.size()==1)return grid;
        int m=grid.size();
        for(int row=0;row<m;row++){
            for(int i=0;i<m-1;i++){
                int col=0;
                for(int j=row;j<m-1-i;j++){
                    if(grid[j][col]<grid[j+1][col+1])swap(grid[j][col],grid[j+1][col+1]);
                    col++;
                }
            }
        }
        for(int col=1;col<m;col++){
            for(int i=0;i<m-1;i++){
                int row=0;
                for(int j=col;j<m-1-i;j++){
                    if(grid[row][j]>grid[row+1][j+1])swap(grid[row][j],grid[row+1][j+1]);
                    row++;
                }
            }
        }
        return grid;
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
    vector<vector<int>> grid1 = {{1, 7, 3},
                                 {9, 8, 2},
                                 {4, 5, 6}};
    cout << "Original Grid 1:" << endl;
    printGrid(grid1);
    vector<vector<int>> sortedGrid1 = solution.sortMatrix(grid1);
    cout << "Sorted Grid 1:" << endl;
    printGrid(sortedGrid1);
    cout << endl;

    // Test Case 2
    vector<vector<int>> grid2 = {{0, 1},
                                 {1, 2}};
    cout << "Original Grid 2:" << endl;
    printGrid(grid2);
    vector<vector<int>> sortedGrid2 = solution.sortMatrix(grid2);
    cout << "Sorted Grid 2:" << endl;
    printGrid(sortedGrid2);
    cout << endl;
    
    return 0;
}
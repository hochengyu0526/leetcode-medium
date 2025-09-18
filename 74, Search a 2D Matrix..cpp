#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;
        
        while(left <= right){
            int mid = left + (right - left) / 2; // Avoids potential integer overflow
            int midrow = mid / n;
            int midcol = mid % n;
            
            if(matrix[midrow][midcol] == target) {
                return true;
            } else if(matrix[midrow][midcol] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};

// Helper function to print a 2D vector
void printMatrix(const vector<vector<int>>& matrix) {
    cout << "[" << endl;
    for (const auto& row : matrix) {
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

    // LeetCode default test case 1: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    cout << "Test Case 1:" << endl;
    vector<vector<int>> matrix1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target1 = 3;
    cout << "Matrix:" << endl;
    printMatrix(matrix1);
    cout << "Target: " << target1 << endl;
    cout << "Result: " << (s.searchMatrix(matrix1, target1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;

    // LeetCode default test case 2: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    cout << "Test Case 2:" << endl;
    vector<vector<int>> matrix2 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target2 = 13;
    cout << "Matrix:" << endl;
    printMatrix(matrix2);
    cout << "Target: " << target2 << endl;
    cout << "Result: " << (s.searchMatrix(matrix2, target2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl;
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }

        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
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

    // LeetCode default test case 1: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    cout << "Test Case 1:" << endl;
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Original matrix:" << endl;
    printMatrix(matrix1);
    s.rotate(matrix1);
    cout << "Rotated matrix:" << endl;
    printMatrix(matrix1);
    cout << "Expected:" << endl;
    cout << "[ \n  [7, 4, 1]\n  [8, 5, 2]\n  [9, 6, 3]\n]" << endl;
    cout << endl;

    // LeetCode default test case 2: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    cout << "Test Case 2:" << endl;
    vector<vector<int>> matrix2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    cout << "Original matrix:" << endl;
    printMatrix(matrix2);
    s.rotate(matrix2);
    cout << "Rotated matrix:" << endl;
    printMatrix(matrix2);
    cout << "Expected:" << endl;
    cout << "[ \n  [15, 13, 2, 5]\n  [14, 3, 4, 1]\n  [12, 6, 8, 9]\n  [16, 7, 10, 11]\n]" << endl;
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            if (row[i]) {
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < n; ++j) { // Corrected loop variable from i to j
            if (col[j]) {
                for (int i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
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

    // LeetCode default test case 1: matrix = [[1,1,1],[1,0,1],[1,1,1]]
    cout << "Test Case 1:" << endl;
    vector<vector<int>> matrix1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    cout << "Original matrix:" << endl;
    printMatrix(matrix1);
    s.setZeroes(matrix1);
    cout << "Modified matrix:" << endl;
    printMatrix(matrix1);
    cout << "Expected:" << endl;
    cout << "[ \n  [1, 0, 1]\n  [0, 0, 0]\n  [1, 0, 1]\n]" << endl;
    cout << endl;

    // LeetCode default test case 2: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    cout << "Test Case 2:" << endl;
    vector<vector<int>> matrix2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    cout << "Original matrix:" << endl;
    printMatrix(matrix2);
    s.setZeroes(matrix2);
    cout << "Modified matrix:" << endl;
    printMatrix(matrix2);
    cout << "Expected:" << endl;
    cout << "[ \n  [0, 0, 0, 0]\n  [0, 4, 5, 0]\n  [0, 3, 1, 0]\n]" << endl;
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int current_val = 1;

        while (top <= bottom && left <= right) {
            // Traverse right
            for (int j = left; j <= right; ++j) {
                matrix[top][j] = current_val++;
            }
            top++;

            // Traverse down
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = current_val++;
            }
            right--;

            // Traverse left
            if (top <= bottom) {
                for (int j = right; j >= left; --j) {
                    matrix[bottom][j] = current_val++;
                }
                bottom--;
            }

            // Traverse up
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = current_val++;
                }
                left++;
            }
        }
        return matrix;
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

    // LeetCode default test case 1: n = 3
    cout << "Test Case 1:" << endl;
    int n1 = 3;
    cout << "n = " << n1 << endl;
    vector<vector<int>> result1 = s.generateMatrix(n1);
    cout << "Generated matrix:" << endl;
    printMatrix(result1);
    cout << "Expected:" << endl;
    cout << "[ \n  [1, 2, 3]\n  [8, 9, 4]\n  [7, 6, 5]\n]" << endl;
    cout << endl;

    // LeetCode default test case 2: n = 1
    cout << "Test Case 2:" << endl;
    int n2 = 1;
    cout << "n = " << n2 << endl;
    vector<vector<int>> result2 = s.generateMatrix(n2);
    cout << "Generated matrix:" << endl;
    printMatrix(result2);
    cout << "Expected:" << endl;
    cout << "[ \n  [1]\n]" << endl;
    cout << endl;

    return 0;
}
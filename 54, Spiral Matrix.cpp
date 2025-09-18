#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        while (top <= bottom && left <= right) {
            // Traverse right
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            top++;
            
            // Traverse down
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--;
            
            // Traverse left
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse up
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return result;
    }
};

// Helper function to print a vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution s;

    // LeetCode default test case 1: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    cout << "Test Case 1:" << endl;
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Input Matrix:" << endl;
    for (const auto& row : matrix1) {
        cout << "[";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
    cout << "Spiral Order: ";
    printVector(s.spiralOrder(matrix1));
    cout << "Expected: [1, 2, 3, 6, 9, 8, 7, 4, 5]" << endl;
    cout << endl;

    // LeetCode default test case 2: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    cout << "Test Case 2:" << endl;
    vector<vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout << "Input Matrix:" << endl;
    for (const auto& row : matrix2) {
        cout << "[";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
    cout << "Spiral Order: ";
    printVector(s.spiralOrder(matrix2));
    cout << "Expected: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]" << endl;
    cout << endl;

    return 0;
}
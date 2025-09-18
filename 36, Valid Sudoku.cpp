#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows and columns
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> row_set;
            unordered_set<char> col_set;
            for (int j = 0; j < 9; ++j) {
                // Check row
                char row_num = board[i][j];
                if (row_num != '.') {
                    if (row_set.count(row_num)) {
                        return false;
                    }
                    row_set.insert(row_num);
                }

                // Check column
                char col_num = board[j][i];
                if (col_num != '.') {
                    if (col_set.count(col_num)) {
                        return false;
                    }
                    col_set.insert(col_num);
                }
            }
        }

        // Check 3x3 sub-boxes
        for (int row_start = 0; row_start < 9; row_start += 3) {
            for (int col_start = 0; col_start < 9; col_start += 3) {
                unordered_set<char> subbox_set;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        char num = board[row_start + i][col_start + j];
                        if (num != '.') {
                            if (subbox_set.count(num)) {
                                return false;
                            }
                            subbox_set.insert(num);
                        }
                    }
                }
            }
        }

        return true;
    }
};

// Helper function to print a Sudoku board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) cout << " ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0) cout << endl;
    }
}

int main() {
    Solution s;

    // LeetCode default test case 1: Valid Sudoku board
    cout << "Test Case 1 (Valid):" << endl;
    vector<vector<char>> board1 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    cout << "Board:" << endl;
    printBoard(board1);
    cout << "Is Valid Sudoku: " << (s.isValidSudoku(board1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;

    // LeetCode default test case 2: Invalid Sudoku board (duplicate in row)
    cout << "Test Case 2 (Invalid - Duplicate in row):" << endl;
    vector<vector<char>> board2 = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    cout << "Board:" << endl;
    printBoard(board2);
    cout << "Is Valid Sudoku: " << (s.isValidSudoku(board2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl;
    cout << endl;

    return 0;
}
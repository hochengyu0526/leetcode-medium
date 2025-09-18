#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (word.size() == 1) return true;
                    used[i][j] = true;
                    if (backtrack(board, word, 1, i, j, used)) return true;
                    used[i][j] = false;
                }
            }
        }
        return false;
    }
private:
    bool backtrack(vector<vector<char>>& board, string word, int nextword, int row, int col, vector<vector<bool>>& used) {
        int m = board.size();
        int n = board[0].size();
        
        // Up
        if (row - 1 >= 0 && !used[row - 1][col]) {
            if (word[nextword] == board[row - 1][col]) {
                used[row - 1][col] = true;
                if (nextword == word.size() - 1) return true;
                if (backtrack(board, word, nextword + 1, row - 1, col, used)) return true;
                used[row - 1][col] = false;
            }
        }
        // Left
        if (col - 1 >= 0 && !used[row][col - 1]) {
            if (word[nextword] == board[row][col - 1]) {
                used[row][col - 1] = true;
                if (nextword == word.size() - 1) return true;
                if (backtrack(board, word, nextword + 1, row, col - 1, used)) return true;
                used[row][col - 1] = false;
            }
        }
        // Down
        if (row + 1 < m && !used[row + 1][col]) {
            if (word[nextword] == board[row + 1][col]) {
                used[row + 1][col] = true;
                if (nextword == word.size() - 1) return true;
                if (backtrack(board, word, nextword + 1, row + 1, col, used)) return true;
                used[row + 1][col] = false;
            }
        }
        // Right
        if (col + 1 < n && !used[row][col + 1]) {
            if (word[nextword] == board[row][col + 1]) {
                used[row][col + 1] = true;
                if (nextword == word.size() - 1) return true;
                if (backtrack(board, word, nextword + 1, row, col + 1, used)) return true;
                used[row][col + 1] = false;
            }
        }
        return false;
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1:
    vector<vector<char>> board1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word1 = "ABCCED";
    cout << "Test Case 1:" << endl;
    cout << "Board:" << endl;
    for (const auto& row : board1) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << "Word: " << word1 << endl;
    cout << "Result: " << (s.exist(board1, word1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;

    // LeetCode default test case 2:
    vector<vector<char>> board2 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word2 = "SEE";
    cout << "Test Case 2:" << endl;
    cout << "Board:" << endl;
    for (const auto& row : board2) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << "Word: " << word2 << endl;
    cout << "Result: " << (s.exist(board2, word2) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;

    // LeetCode default test case 3:
    vector<vector<char>> board3 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word3 = "ABCB";
    cout << "Test Case 3:" << endl;
    cout << "Board:" << endl;
    for (const auto& row : board3) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << "Word: " << word3 << endl;
    cout << "Result: " << (s.exist(board3, word3) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;

    return 0;
}
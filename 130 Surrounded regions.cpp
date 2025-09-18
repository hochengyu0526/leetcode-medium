#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        int m = board.size();
        int n = board[0].size();

        // No 'O's can be surrounded if the board is too small
        if (m <= 2 || n <= 2) {
            return;
        }

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Traverse the borders to find all 'O's that are not surrounded
        // Top and bottom borders
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O' && !visited[0][j]) {
                dfs(board, visited, 0, j);
            }
            if (board[m - 1][j] == 'O' && !visited[m - 1][j]) {
                dfs(board, visited, m - 1, j);
            }
        }
        // Left and right borders
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(board, visited, i, 0);
            }
            if (board[i][n - 1] == 'O' && !visited[i][n - 1]) {
                dfs(board, visited, i, n - 1);
            }
        }

        // Flip all remaining 'O's that were not visited
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == 'X' || visited[r][c]) {
            return;
        }
        
        visited[r][c] = true;
        
        dfs(board, visited, r + 1, c);
        dfs(board, visited, r - 1, c);
        dfs(board, visited, r, c + 1);
        dfs(board, visited, r, c - 1);
    }
};

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    vector<vector<char>> board1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    cout << "Initial Board 1:" << endl;
    printBoard(board1);
    solution.solve(board1);
    cout << "\nResult Board 1:" << endl;
    printBoard(board1); // Expected:
    // X X X X
    // X X X X
    // X X X X
    // X O X X
    cout << "--------------------" << endl;
    
    // Test case 2
    vector<vector<char>> board2 = {
        {'O', 'O', 'O'},
        {'O', 'O', 'O'},
        {'O', 'O', 'O'}
    };
    cout << "Initial Board 2:" << endl;
    printBoard(board2);
    solution.solve(board2);
    cout << "\nResult Board 2:" << endl;
    printBoard(board2); // Expected:
    // O O O
    // O O O
    // O O O
    cout << "--------------------" << endl;
    
    return 0;
}
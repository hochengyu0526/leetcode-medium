import sys
import copy
from typing import List

class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        original = copy.deepcopy(board)  # 創建一個獨立的副本
        rows = len(board)
        if rows == 0:
            return
        cols = len(board[0])
        for row in range(rows):       
            for col in range(cols):
                c=0
                if row-1>=0 and col-1>=0 and original[row-1][col-1]==1:c+=1
                if row-1>=0 and original[row-1][col]==1:c+=1
                if row-1>=0 and col+1<len(board[row]) and original[row-1][col+1]==1:c+=1
                if col+1<len(board[row]) and original[row][col+1]==1:c+=1
                if row+1<len(board) and col+1<len(board[row]) and original[row+1][col+1]==1:c+=1
                if row+1<len(board) and original[row+1][col]==1:c+=1
                if row+1<len(board) and col-1>=0 and original[row+1][col-1]==1:c+=1
                if col-1>=0 and original[row][col-1]==1:c+=1

                if original[row][col]==1 and (c<2 or c>3):
                    board[row][col]=0
                elif original[row][col]==0 and c==3:
                    board[row][col]=1

def print_board(board: List[List[int]]):
    for row in board:
        print(row)

# 測試案例
if __name__ == "__main__":
    solution = Solution()

    # 測試案例 1
    board1 = [
        [0, 1, 0],
        [0, 0, 1],
        [1, 1, 1],
        [0, 0, 0]
    ]
    print("Test Case 1:")
    print("Original board:")
    print_board(board1)
    
    solution.gameOfLife(board1)
    
    print("\nBoard after one generation:")
    print_board(board1)
    print("Expected:")
    print("[0, 0, 0]")
    print("[1, 0, 1]")
    print("[0, 1, 1]")
    print("[0, 1, 0]")
    print("--------------------")

    # 測試案例 2
    board2 = [
        [1, 1],
        [1, 0]
    ]
    print("Test Case 2:")
    print("Original board:")
    print_board(board2)
    
    solution.gameOfLife(board2)
    
    print("\nBoard after one generation:")
    print_board(board2)
    print("Expected:")
    print("[1, 1]")
    print("[1, 1]")
    print("--------------------")
from typing import Optional, List
import queue

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result=[]
        if root==None:return result 
        q=queue.Queue()
        q.put(root)
        nextlevel=0
        currentlevel=1
        while not q.empty():
            node=q.get()
            currentlevel-=1
            if node.left:
                nextlevel+=1
                q.put(node.left)
            if node.right:
                nextlevel+=1
                q.put(node.right)
            if currentlevel==0:
                currentlevel=nextlevel
                result.append(node.val)
                nextlevel=0
        return result

# Helper function to create a binary tree from a list
def create_tree(nodes):
    if not nodes:
        return None
    root = TreeNode(nodes[0])
    q = [root]
    i = 1
    while q and i < len(nodes):
        node = q.pop(0)
        if nodes[i] is not None:
            node.left = TreeNode(nodes[i])
            q.append(node.left)
        i += 1
        if i < len(nodes) and nodes[i] is not None:
            node.right = TreeNode(nodes[i])
            q.append(node.right)
        i += 1
    return root

# Main function to run tests
if __name__ == '__main__':
    solution = Solution()

    # Test case 1 from LeetCode
    root1 = create_tree([1, 2, 3, None, 5, None, 4])
    print(f"Test case 1: {solution.rightSideView(root1)}")  # Expected: [1, 3, 4]
    
    # Test case 2 from LeetCode
    root2 = create_tree([1, None, 3])
    print(f"Test case 2: {solution.rightSideView(root2)}")  # Expected: [1, 3]

    # Test case 3
    root3 = create_tree([])
    print(f"Test case 3: {solution.rightSideView(root3)}")  # Expected: []
    
    # Test case 4
    root4 = create_tree([1, 2])
    print(f"Test case 4: {solution.rightSideView(root4)}")  # Expected: [1, 2]
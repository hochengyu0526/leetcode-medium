#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) {
            return 0;
        }

        // Calculate the number for the current path
        currentSum = currentSum * 10 + node->val;

        // Base case: If it's a leaf node, return the number
        if (!node->left && !node->right) {
            return currentSum;
        }

        // Recursive step: Sum up the results from left and right subtrees
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};

// Helper function to create a binary tree for testing
TreeNode* createTree(vector<int>& nodes, int index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        return nullptr;
    }
    TreeNode* node = new TreeNode(nodes[index]);
    node->left = createTree(nodes, 2 * index + 1);
    node->right = createTree(nodes, 2 * index + 2);
    return node;
}

// Main function to run tests
int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    // Tree:   1
    //        / \
    //       2   3
    vector<int> nums1 = {1, 2, 3};
    TreeNode* root1 = createTree(nums1, 0);
    cout << "Test case 1 result: " << solution.sumNumbers(root1) << endl; // Expected: 12 + 13 = 25
    cout << "--------------------" << endl;
    
    // Test case 2 from LeetCode
    // Tree:   4
    //        / \
    //       9   0
    //      /
    //     5
    //      \
    //       1
    vector<int> nums2 = {4, 9, 0, 5, -1, -1, -1, -1, 1};
    TreeNode* root2 = createTree(nums2, 0);
    cout << "Test case 2 result: " << solution.sumNumbers(root2) << endl; // Expected: 495 + 491 + 40 = 926
    
    return 0;
}
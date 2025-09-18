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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }
private:
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> alltree;
        if (start > end) {
            alltree.push_back(nullptr);
            return alltree;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> lefttree = buildTrees(start, i - 1);
            vector<TreeNode*> righttree = buildTrees(i + 1, end);
            for (TreeNode* left : lefttree) {
                for (TreeNode* right : righttree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    alltree.push_back(root);
                }
            }
        }
        return alltree;
    }
};

// Helper function to print a single tree for testing (pre-order traversal)
void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

// Helper function to print all generated trees
void printAllTrees(const vector<TreeNode*>& trees) {
    cout << "Generated " << trees.size() << " unique BSTs:" << endl;
    for (size_t i = 0; i < trees.size(); ++i) {
        cout << "Tree " << i + 1 << ": ";
        printTree(trees[i]);
        cout << endl;
    }
    cout << "--------------------" << endl;
}

int main() {
    Solution solution;

    // Test case for n = 3
    int n1 = 3;
    cout << "Test Case: n = " << n1 << endl;
    vector<TreeNode*> result1 = solution.generateTrees(n1);
    printAllTrees(result1); // Expected: 5 unique trees

    // Test case for n = 1
    int n2 = 1;
    cout << "Test Case: n = " << n2 << endl;
    vector<TreeNode*> result2 = solution.generateTrees(n2);
    printAllTrees(result2); // Expected: 1 unique tree

    // Test case for n = 0
    int n3 = 0;
    cout << "Test Case: n = " << n3 << endl;
    vector<TreeNode*> result3 = solution.generateTrees(n3);
    printAllTrees(result3); // Expected: 0 unique trees
    
    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

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
    unordered_map<int, int> inorderMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        if (preorder.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        root->left = nullptr;
        root->right = nullptr;
        for (int i = 1; i < preorder.size(); i++) {
            build(root, inorder, preorder[i]);
        }
        return root;
    }
private:
    void build(TreeNode* &root, vector<int>& inorder, int value) {
        if (!root) {
            root = new TreeNode(value);
            root->left = nullptr;
            root->right = nullptr;
            return;
        }
        if (inorderMap.count(value) && inorderMap.count(root->val)) {
            if (inorderMap[value] < inorderMap[root->val]) {
                build(root->left, inorder, value);
            } else {
                build(root->right, inorder, value);
            }
        }
    }
};

// Helper function to print tree level by level
void printTree(TreeNode* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    cout << "[";
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (current) {
            cout << current->val;
            q.push(current->left);
            q.push(current->right);
        } else {
            cout << "null";
        }
        if (!q.empty()) {
            bool has_more = false;
            queue<TreeNode*> temp_q = q;
            while(!temp_q.empty()){
                if(temp_q.front()){
                    has_more = true;
                    break;
                }
                temp_q.pop();
            }
            if (has_more) {
                cout << ", ";
            }
        }
    }
    cout << "]" << endl;
}

int main() {
    Solution s;

    // LeetCode default test case 1:
    // preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    cout << "Test Case 1:" << endl;
    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    TreeNode* root1 = s.buildTree(preorder1, inorder1);
    cout << "Expected tree (level-order): [3, 9, 20, null, null, 15, 7]" << endl;
    cout << "Your output (level-order): ";
    printTree(root1);
    cout << endl;

    // LeetCode default test case 2:
    // preorder = [-1], inorder = [-1]
    cout << "Test Case 2:" << endl;
    vector<int> preorder2 = {-1};
    vector<int> inorder2 = {-1};
    TreeNode* root2 = s.buildTree(preorder2, inorder2);
    cout << "Expected tree (level-order): [-1]" << endl;
    cout << "Your output (level-order): ";
    printTree(root2);
    cout << endl;

    return 0;
}
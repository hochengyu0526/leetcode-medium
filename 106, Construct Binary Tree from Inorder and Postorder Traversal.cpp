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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        if (postorder.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
        root->left = nullptr;
        root->right = nullptr;
        for (int i = postorder.size() - 2; i >= 0; i--) {
            build(root, inorder, postorder[i]);
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
    // inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    cout << "Test Case 1:" << endl;
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    vector<int> postorder1 = {9, 15, 7, 20, 3};
    TreeNode* root1 = s.buildTree(inorder1, postorder1);
    cout << "Expected tree (level-order): [3, 9, 20, null, null, 15, 7]" << endl;
    cout << "Your output (level-order): ";
    printTree(root1);
    cout << endl;

    // LeetCode default test case 2:
    // inorder = [-1], postorder = [-1]
    cout << "Test Case 2:" << endl;
    vector<int> inorder2 = {-1};
    vector<int> postorder2 = {-1};
    TreeNode* root2 = s.buildTree(inorder2, postorder2);
    cout << "Expected tree (level-order): [-1]" << endl;
    cout << "Your output (level-order): ";
    printTree(root2);
    cout << endl;
    
    // LeetCode custom test case 3:
    // inorder = [], postorder = []
    cout << "Test Case 3:" << endl;
    vector<int> inorder3 = {};
    vector<int> postorder3 = {};
    TreeNode* root3 = s.buildTree(inorder3, postorder3);
    cout << "Expected tree (level-order): []" << endl;
    cout << "Your output (level-order): ";
    printTree(root3);
    cout << endl;

    return 0;
}
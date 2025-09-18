#include <iostream>
#include <vector>
#include <queue>
#include <limits>

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
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        return inorder(root, pre);
    }
private:
    bool inorder(TreeNode* root, TreeNode* &pre) {
        if (!root) return true;
        if (!inorder(root->left, pre)) return false;
        if (pre && root->val <= pre->val) return false;
        pre = root;
        return inorder(root->right, pre);
    }
};

// Helper function to build a tree from a vector representation
TreeNode* buildTree(const vector<int*>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == nullptr) {
        index++;
        return nullptr;
    }
    TreeNode* node = new TreeNode(*nodes[index++]);
    node->left = buildTree(nodes, index);
    node->right = buildTree(nodes, index);
    return node;
}

// Helper function to print tree level by level (for verification)
void printTree(TreeNode* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    cout << "[";
    bool first = true;
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (!first) {
            cout << ", ";
        }
        if (current) {
            cout << current->val;
            q.push(current->left);
            q.push(current->right);
        } else {
            cout << "null";
        }
        first = false;
    }
    cout << "]" << endl;
}

int main() {
    Solution s;

    // LeetCode default test case 1: root = [2,1,3]
    cout << "Test Case 1:" << endl;
    vector<int> vals1 = {2, 1, 3};
    vector<int*> nodes1;
    for (int v : vals1) {
        if (v == -1) nodes1.push_back(nullptr);
        else nodes1.push_back(new int(v));
    }
    int index1 = 0;
    TreeNode* root1 = buildTree(nodes1, index1);
    cout << "Tree: [2, 1, 3]" << endl;
    cout << "Is Valid BST? " << (s.isValidBST(root1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;

    // LeetCode default test case 2: root = [5,1,4,null,null,3,6]
    cout << "Test Case 2:" << endl;
    vector<int> vals2 = {5, 1, 4, -1, -1, 3, 6};
    vector<int*> nodes2;
    for (int v : vals2) {
        if (v == -1) nodes2.push_back(nullptr);
        else nodes2.push_back(new int(v));
    }
    int index2 = 0;
    TreeNode* root2 = buildTree(nodes2, index2);
    cout << "Tree: [5, 1, 4, null, null, 3, 6]" << endl;
    cout << "Is Valid BST? " << (s.isValidBST(root2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl;
    cout << endl;

    // Custom test case 3: root = [5,4,6,null,null,3,7]
    cout << "Test Case 3:" << endl;
    vector<int> vals3 = {5, 4, 6, -1, -1, 3, 7};
    vector<int*> nodes3;
    for (int v : vals3) {
        if (v == -1) nodes3.push_back(nullptr);
        else nodes3.push_back(new int(v));
    }
    int index3 = 0;
    TreeNode* root3 = buildTree(nodes3, index3);
    cout << "Tree: [5, 4, 6, null, null, 3, 7]" << endl;
    cout << "Is Valid BST? " << (s.isValidBST(root3) ? "true" : "false") << endl;
    cout << "Expected: false" << endl;
    cout << endl;

    return 0;
}
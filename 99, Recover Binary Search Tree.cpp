#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    void recoverTree(TreeNode* root) {
        TreeNode* pre = nullptr;
        TreeNode* start = nullptr;
        TreeNode* end = nullptr;
        bool flag = false;
        inorder(root, pre, start, end, flag);
        swap(start->val, end->val);
        return;
    }
private:
    void inorder(TreeNode* root, TreeNode* &pre, TreeNode* &start, TreeNode* &end, bool &flag) {
        if (!root) return;
        inorder(root->left, pre, start, end, flag);
        if (pre && root->val <= pre->val) {
            if (flag) {
                end = root;
            } else {
                start = pre;
                end = root;
                flag = true;
            }
        }
        pre = root;
        inorder(root->right, pre, start, end, flag);
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

// Helper function to print tree level by level
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

    // LeetCode default test case 1: root = [1,3,null,null,2]
    cout << "Test Case 1:" << endl;
    vector<int> vals1 = {1, 3, -1, -1, 2};
    vector<int*> nodes1;
    for (int v : vals1) {
        if (v == -1) nodes1.push_back(nullptr);
        else nodes1.push_back(new int(v));
    }
    int index1 = 0;
    TreeNode* root1 = buildTree(nodes1, index1);
    cout << "Initial tree (level-order): ";
    printTree(root1);
    s.recoverTree(root1);
    cout << "Recovered tree (level-order): ";
    printTree(root1);
    cout << endl;

    // LeetCode default test case 2: root = [3,1,4,null,null,2]
    cout << "Test Case 2:" << endl;
    vector<int> vals2 = {3, 1, 4, -1, -1, 2};
    vector<int*> nodes2;
    for (int v : vals2) {
        if (v == -1) nodes2.push_back(nullptr);
        else nodes2.push_back(new int(v));
    }
    int index2 = 0;
    TreeNode* root2 = buildTree(nodes2, index2);
    cout << "Initial tree (level-order): ";
    printTree(root2);
    s.recoverTree(root2);
    cout << "Recovered tree (level-order): ";
    printTree(root2);
    cout << endl;

    return 0;
}
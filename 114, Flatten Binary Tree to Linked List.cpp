#include <iostream>
#include <vector>
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
    void flatten(TreeNode* root) {
        if(!root)return;
        queue<TreeNode*> q;
        preorder(root,q);
        root->left=nullptr;
        root->right=nullptr;
        q.pop();
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            root->right=node;
            root=root->right;
            root->left=nullptr;
            root->right=nullptr;
        }
        return;
    }
private:
    void preorder(TreeNode* root, queue<TreeNode*> &q){
        q.push(root);
        if(root->left)preorder(root->left,q);
        if(root->right)preorder(root->right,q);
    }
};

// Helper function to build a tree from a vector
TreeNode* buildTree(const vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return nullptr;
    }
    TreeNode* node = new TreeNode(nodes[index++]);
    node->left = buildTree(nodes, index);
    node->right = buildTree(nodes, index);
    return node;
}

// Helper function to print the flattened list
void printFlattenedList(TreeNode* root) {
    TreeNode* current = root;
    while (current) {
        cout << current->val << " -> ";
        current = current->right;
    }
    cout << "nullptr" << endl;
}

int main() {
    // LeetCode default test case 1: root = [1,2,5,3,4,null,6]
    cout << "Test Case 1:" << endl;
    vector<int> nodes1 = {1, 2, 5, 3, 4, -1, 6};
    int index1 = 0;
    TreeNode* root1 = buildTree(nodes1, index1);
    
    Solution s1;
    s1.flatten(root1);
    printFlattenedList(root1); // Expected output: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> nullptr
    cout << endl;

    // LeetCode default test case 2: root = []
    cout << "Test Case 2:" << endl;
    vector<int> nodes2 = {};
    int index2 = 0;
    TreeNode* root2 = buildTree(nodes2, index2);
    
    Solution s2;
    s2.flatten(root2);
    printFlattenedList(root2); // Expected output: nullptr
    cout << endl;

    // LeetCode default test case 3: root = [0]
    cout << "Test Case 3:" << endl;
    vector<int> nodes3 = {0};
    int index3 = 0;
    TreeNode* root3 = buildTree(nodes3, index3);

    Solution s3;
    s3.flatten(root3);
    printFlattenedList(root3); // Expected output: 0 -> nullptr
    cout << endl;

    return 0;
}
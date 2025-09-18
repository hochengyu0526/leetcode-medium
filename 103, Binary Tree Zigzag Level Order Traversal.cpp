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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        vector<int> current;
        queue<TreeNode*> q;
        q.push(root);
        int nodenum = 1, nextnodenum = 0, highlevel = 0;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            current.push_back(node->val);
            nodenum--;
            if (node->left){
                q.push(node->left);
                nextnodenum++;
            }
            if(node->right){
                q.push(node->right);
                nextnodenum++;
            }
            if(nodenum == 0){
                if(highlevel % 2 == 1) reverse(current.begin(), current.end());
                result.push_back(current);
                highlevel++;
                current.clear();
                nodenum = nextnodenum;
                nextnodenum = 0;
            }
        }
        return result;
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

// Helper function to print the result vector of vectors
void printResult(const vector<vector<int>>& result) {
    if (result.empty()) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << (j == result[i].size() - 1 ? "" : ", ");
        }
        cout << "]" << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    // LeetCode default test case 1: root = [3,9,20,null,null,15,7]
    cout << "Test Case 1:" << endl;
    vector<int> vals1 = {3, 9, 20, -1, -1, 15, 7};
    vector<int*> nodes1;
    for (int v : vals1) {
        if (v == -1) nodes1.push_back(nullptr);
        else nodes1.push_back(new int(v));
    }
    int index1 = 0;
    TreeNode* root1 = buildTree(nodes1, index1);
    
    Solution s1;
    vector<vector<int>> result1 = s1.zigzagLevelOrder(root1);
    cout << "Expected Output: [[3], [20,9], [15,7]]" << endl;
    cout << "Your Output: ";
    printResult(result1);
    cout << endl;

    // LeetCode default test case 2: root = [1]
    cout << "Test Case 2:" << endl;
    vector<int> vals2 = {1};
    vector<int*> nodes2;
    for (int v : vals2) {
        if (v == -1) nodes2.push_back(nullptr);
        else nodes2.push_back(new int(v));
    }
    int index2 = 0;
    TreeNode* root2 = buildTree(nodes2, index2);

    Solution s2;
    vector<vector<int>> result2 = s2.zigzagLevelOrder(root2);
    cout << "Expected Output: [[1]]" << endl;
    cout << "Your Output: ";
    printResult(result2);
    cout << endl;

    // LeetCode default test case 3: root = []
    cout << "Test Case 3:" << endl;
    vector<int> vals3 = {};
    vector<int*> nodes3;
    for (int v : vals3) {
        if (v == -1) nodes3.push_back(nullptr);
        else nodes3.push_back(new int(v));
    }
    int index3 = 0;
    TreeNode* root3 = buildTree(nodes3, index3);

    Solution s3;
    vector<vector<int>> result3 = s3.zigzagLevelOrder(root3);
    cout << "Expected Output: []" << endl;
    cout << "Your Output: ";
    printResult(result3);
    cout << endl;

    return 0;
}
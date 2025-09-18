#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> current;
        if(!root) return result;
        dfs(root, result, current, targetSum);
        return result;
    }
private:
    void dfs(TreeNode* root, vector<vector<int>> &result, vector<int> &current, int targetSum){
        if(!root->left && !root->right){
            current.push_back(root->val);
            int sum = 0;
            for(int i = 0; i < current.size(); i++) sum += current[i];
            if(sum == targetSum){
                result.push_back(current);
                return;
            } else {
                return;
            }
        }
        current.push_back(root->val);
        if(root->left){
            dfs(root->left, result, current, targetSum);
            current.pop_back();
        }
        if(root->right){
            dfs(root->right, result, current, targetSum);
            current.pop_back();
        }
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
    // LeetCode default test case 1:
    // root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    cout << "Test Case 1:" << endl;
    vector<int> vals1 = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
    vector<int*> nodes1;
    for (int v : vals1) {
        if (v == -1) nodes1.push_back(nullptr);
        else nodes1.push_back(new int(v));
    }
    int index1 = 0;
    TreeNode* root1 = buildTree(nodes1, index1);
    
    Solution s1;
    vector<vector<int>> result1 = s1.pathSum(root1, 22);
    cout << "Target Sum: 22" << endl;
    cout << "Expected Output: [[5,4,11,2], [5,8,4,5]]" << endl;
    cout << "Your Output: ";
    printResult(result1);
    cout << endl;

    // LeetCode default test case 2:
    // root = [1,2,3], targetSum = 5
    cout << "Test Case 2:" << endl;
    vector<int> vals2 = {1, 2, 3};
    vector<int*> nodes2;
    for (int v : vals2) {
        if (v == -1) nodes2.push_back(nullptr);
        else nodes2.push_back(new int(v));
    }
    int index2 = 0;
    TreeNode* root2 = buildTree(nodes2, index2);

    Solution s2;
    vector<vector<int>> result2 = s2.pathSum(root2, 5);
    cout << "Target Sum: 5" << endl;
    cout << "Expected Output: []" << endl;
    cout << "Your Output: ";
    printResult(result2);
    cout << endl;

    // LeetCode default test case 3:
    // root = [1,2], targetSum = 0
    cout << "Test Case 3:" << endl;
    vector<int> vals3 = {1, 2};
    vector<int*> nodes3;
    for (int v : vals3) {
        if (v == -1) nodes3.push_back(nullptr);
        else nodes3.push_back(new int(v));
    }
    int index3 = 0;
    TreeNode* root3 = buildTree(nodes3, index3);

    Solution s3;
    vector<vector<int>> result3 = s3.pathSum(root3, 0);
    cout << "Target Sum: 0" << endl;
    cout << "Expected Output: []" << endl;
    cout << "Your Output: ";
    printResult(result3);
    cout << endl;

    return 0;
}
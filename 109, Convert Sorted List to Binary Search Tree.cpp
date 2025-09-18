#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        ListNode* current = head;
        vector<int> v;
        int mid = 0;
        while (current != nullptr) {
            v.push_back(current->val);
            current = current->next;
        }
        int v_size = v.size() - 1;
        if (v.empty()) {
            return nullptr;
        }
        mid = v_size / 2;
        TreeNode* root = new TreeNode(v[mid]); // 創建新節點
        root->left = nullptr;
        root->right = nullptr;
        build(root, v, 0, v_size);
        return root;
    }
private:
    void build(TreeNode* &root, vector<int> v, int left, int right) {
        if (left > right) {
            return;
        }
        int mid = left + (right - left) / 2;
        if (!root) {
            root = new TreeNode(v[mid]);
            root->left = nullptr;
            root->right = nullptr;
        }
        build(root->left, v, left, mid - 1);
        build(root->right, v, mid + 1, right);
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
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

    // LeetCode default test case 1: head = [-10,-3,0,5,9]
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {-10, -3, 0, 5, 9};
    ListNode* head1 = createList(nums1);
    TreeNode* root1 = s.sortedListToBST(head1);
    cout << "Expected tree (level-order, one possible answer): [0, -3, 9, -10, null, 5]" << endl;
    cout << "Your output (level-order): ";
    printTree(root1);
    cout << endl;

    // LeetCode default test case 2: head = []
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {};
    ListNode* head2 = createList(nums2);
    TreeNode* root2 = s.sortedListToBST(head2);
    cout << "Expected tree: []" << endl;
    cout << "Your output: ";
    printTree(root2);
    cout << endl;

    // LeetCode custom test case 3: head = [0,1,2,3,4,5]
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {0, 1, 2, 3, 4, 5};
    ListNode* head3 = createList(nums3);
    TreeNode* root3 = s.sortedListToBST(head3);
    cout << "Expected tree (level-order, one possible answer): [2, 0, 4, null, 1, 3, 5]" << endl;
    cout << "Your output (level-order): ";
    printTree(root3);
    cout << endl;

    return 0;
}
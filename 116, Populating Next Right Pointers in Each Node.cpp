#include <iostream>
#include <vector>
#include <queue>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        dfs(root);
        return root;
    }

private:
    void dfs(Node* root) {
        if (!root || !root->left) {
            return;
        }

        // 1. Connect left child to right child
        root->left->next = root->right;

        // 2. Connect right child to the left child of the next node
        if (root->next) {
            root->right->next = root->next->left;
        } else {
            root->right->next = nullptr;
        }

        // Recurse for the left and right children
        dfs(root->left);
        dfs(root->right);
    }
};

// Helper function to create a perfect binary tree for testing
Node* createPerfectTree(const std::vector<int>& values, int index) {
    if (index >= values.size()) {
        return nullptr;
    }
    Node* node = new Node(values[index]);
    node->left = createPerfectTree(values, 2 * index + 1);
    node->right = createPerfectTree(values, 2 * index + 2);
    return node;
}

// Helper function to print the connected tree level by level
void printConnectedTree(Node* root) {
    Node* level_start = root;
    while (level_start) {
        Node* current = level_start;
        while (current) {
            std::cout << current->val << (current->next ? " -> " : " -> NULL");
            current = current->next;
        }
        std::cout << std::endl;
        level_start = level_start->left; // Move to the first node of the next level
    }
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    // Perfect Binary Tree:
    //      1
    //     /  \
    //    2    3
    //   / \  / \
    //  4   5 6  7
    std::vector<int> values1 = {1, 2, 3, 4, 5, 6, 7};
    Node* root1 = createPerfectTree(values1, 0);

    std::cout << "Original Tree 1:" << std::endl;
    // (Note: The next pointers are NULL before the function call)
    
    solution.connect(root1);
    
    std::cout << "\nTree 1 after connecting next pointers:" << std::endl;
    printConnectedTree(root1);
    std::cout << "--------------------" << std::endl;

    // Test case 2 with a smaller tree
    //      1
    //     / \
    //    2   3
    std::vector<int> values2 = {1, 2, 3};
    Node* root2 = createPerfectTree(values2, 0);

    std::cout << "Original Tree 2:" << std::endl;

    solution.connect(root2);
    
    std::cout << "\nTree 2 after connecting next pointers:" << std::endl;
    printConnectedTree(root2);
    std::cout << "--------------------" << std::endl;

    return 0;
}
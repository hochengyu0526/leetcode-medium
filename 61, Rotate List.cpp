#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        int size = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            size++;
        }

        k %= size;
        if (k == 0) {
            return head;
        }

        ListNode* newTail = head;
        for (int i = 0; i < size - k - 1; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;

        return newHead;
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

// Helper function to print a linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Solution s;

    // LeetCode default test case 1: head = [1,2,3,4,5], k = 2
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(nums1);
    cout << "Initial list: ";
    printList(head1);
    cout << "k = 2" << endl;
    ListNode* result1 = s.rotateRight(head1, 2);
    cout << "Rotated list: ";
    printList(result1);
    cout << "Expected: 4 -> 5 -> 1 -> 2 -> 3 -> nullptr" << endl;
    cout << endl;

    // LeetCode default test case 2: head = [0,1,2], k = 4
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {0, 1, 2};
    ListNode* head2 = createList(nums2);
    cout << "Initial list: ";
    printList(head2);
    cout << "k = 4" << endl;
    ListNode* result2 = s.rotateRight(head2, 4);
    cout << "Rotated list: ";
    printList(result2);
    cout << "Expected: 2 -> 0 -> 1 -> nullptr" << endl;
    cout << endl;

    // LeetCode custom test case 3: head = [1], k = 99
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {1};
    ListNode* head3 = createList(nums3);
    cout << "Initial list: ";
    printList(head3);
    cout << "k = 99" << endl;
    ListNode* result3 = s.rotateRight(head3, 99);
    cout << "Rotated list: ";
    printList(result3);
    cout << "Expected: 1 -> nullptr" << endl;
    cout << endl;

    return 0;
}
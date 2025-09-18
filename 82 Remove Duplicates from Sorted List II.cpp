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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* current = head;
        
        while(current != nullptr) {
            if(current->next != nullptr && current->val == current->next->val) {
                while(current->next != nullptr && current->val == current->next->val) {
                    current = current->next;
                }
                pre->next = current->next;
            } else {
                pre = pre->next;
            }
            current = current->next;
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
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

    // LeetCode default test case 1: head = [1,2,3,3,4,4,5]
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 2, 3, 3, 4, 4, 5};
    ListNode* head1 = createList(nums1);
    cout << "Initial list: ";
    printList(head1);
    ListNode* result1 = s.deleteDuplicates(head1);
    cout << "Final list: ";
    printList(result1);
    cout << "Expected: 1 -> 2 -> 5 -> nullptr" << endl;
    cout << endl;

    // LeetCode default test case 2: head = [1,1,1,2,3]
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {1, 1, 1, 2, 3};
    ListNode* head2 = createList(nums2);
    cout << "Initial list: ";
    printList(head2);
    ListNode* result2 = s.deleteDuplicates(head2);
    cout << "Final list: ";
    printList(result2);
    cout << "Expected: 2 -> 3 -> nullptr" << endl;
    cout << endl;

    // LeetCode custom test case 3: head = []
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {};
    ListNode* head3 = createList(nums3);
    cout << "Initial list: ";
    printList(head3);
    ListNode* result3 = s.deleteDuplicates(head3);
    cout << "Final list: ";
    printList(result3);
    cout << "Expected: nullptr" << endl;
    cout << endl;

    // LeetCode custom test case 4: head = [1,1,1]
    cout << "Test Case 4:" << endl;
    vector<int> nums4 = {1, 1, 1};
    ListNode* head4 = createList(nums4);
    cout << "Initial list: ";
    printList(head4);
    ListNode* result4 = s.deleteDuplicates(head4);
    cout << "Final list: ";
    printList(result4);
    cout << "Expected: nullptr" << endl;
    cout << endl;

    return 0;
}
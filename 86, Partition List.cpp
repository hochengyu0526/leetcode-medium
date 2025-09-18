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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small_dummy = new ListNode(0);
        ListNode* start = small_dummy;
        ListNode* large_dummy = new ListNode(0);
        ListNode* connect = large_dummy;
        ListNode* current = head;
        while(current != nullptr) {
            if(current->val < x) {
                small_dummy->next = current;
                small_dummy = small_dummy->next;
            } else {
                large_dummy->next = current;
                large_dummy = large_dummy->next;
            }
            current = current->next;
        }
        large_dummy->next = nullptr;
        small_dummy->next = connect->next;
        return start->next;
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

    // LeetCode default test case 1: head = [1,4,3,2,5,2], x = 3
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 4, 3, 2, 5, 2};
    ListNode* head1 = createList(nums1);
    cout << "Initial list: ";
    printList(head1);
    ListNode* result1 = s.partition(head1, 3);
    cout << "Partitioned list: ";
    printList(result1);
    cout << "Expected: 1 -> 2 -> 2 -> 4 -> 3 -> 5 -> nullptr" << endl;
    cout << endl;

    // LeetCode default test case 2: head = [2,1], x = 2
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {2, 1};
    ListNode* head2 = createList(nums2);
    cout << "Initial list: ";
    printList(head2);
    ListNode* result2 = s.partition(head2, 2);
    cout << "Partitioned list: ";
    printList(result2);
    cout << "Expected: 1 -> 2 -> nullptr" << endl;
    cout << endl;
    
    // LeetCode custom test case 3: head = [1], x = 0
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {1};
    ListNode* head3 = createList(nums3);
    cout << "Initial list: ";
    printList(head3);
    ListNode* result3 = s.partition(head3, 0);
    cout << "Partitioned list: ";
    printList(result3);
    cout << "Expected: 1 -> nullptr" << endl;
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;
        ListNode* prelocation = dummy;
        int c = 0;
        vector<int> v;
        while(current != nullptr) {
            if (c == left - 1) {
                current = current->next;
                c++;
            } else if (c < left - 1) {
                current = current->next;
                prelocation = prelocation->next;
                c++;
            } else {
                if (c < right) {
                    v.push_back(current->val);
                    current = current->next;
                    c++;
                } else if (c == right) {
                    v.push_back(current->val);
                    current = current->next;
                    for (int i = v.size() - 1; i >= 0; i--) {
                        prelocation->next->val = v[i];
                        prelocation = prelocation->next;
                    }
                    prelocation->next = current;
                    break;
                }
            }
        }
        return dummy->next;
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

    // LeetCode default test case 1: head = [1,2,3,4,5], left = 2, right = 4
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(nums1);
    cout << "Initial list: ";
    printList(head1);
    ListNode* result1 = s.reverseBetween(head1, 2, 4);
    cout << "Reversed list: ";
    printList(result1);
    cout << "Expected: 1 -> 4 -> 3 -> 2 -> 5 -> nullptr" << endl;
    cout << endl;

    // LeetCode default test case 2: head = [5], left = 1, right = 1
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {5};
    ListNode* head2 = createList(nums2);
    cout << "Initial list: ";
    printList(head2);
    ListNode* result2 = s.reverseBetween(head2, 1, 1);
    cout << "Reversed list: ";
    printList(result2);
    cout << "Expected: 5 -> nullptr" << endl;
    cout << endl;

    // LeetCode custom test case 3: head = [1,2,3,4,5], left = 1, right = 5
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {1, 2, 3, 4, 5};
    ListNode* head3 = createList(nums3);
    cout << "Initial list: ";
    printList(head3);
    ListNode* result3 = s.reverseBetween(head3, 1, 5);
    cout << "Reversed list: ";
    printList(result3);
    cout << "Expected: 5 -> 4 -> 3 -> 2 -> 1 -> nullptr" << endl;
    cout << endl;

    return 0;
}
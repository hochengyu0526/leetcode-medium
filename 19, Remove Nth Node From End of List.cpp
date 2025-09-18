#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Create a dummy node to handle the edge case of removing the head
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    // Move the fast pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (fast->next == NULL) {
            // This case should not happen based on problem constraints
            // but is good practice to include.
            return head; 
        }
        fast = fast->next;
    }

    // Move both pointers until the fast pointer reaches the end
    // The slow pointer will stop at the node just before the one to be removed
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node from the end
    struct ListNode* node_to_delete = slow->next;
    slow->next = slow->next->next;
    
    free(node_to_delete); // Free the memory of the removed node

    return dummy.next;
}

// Helper function to create a linked list from an array
struct ListNode* createList(int* nums, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = nums[0];
    head->next = NULL;
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = nums[i];
        current->next = NULL;
    }
    return head;
}

// Helper function to print a linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // LeetCode default test case 1: head = [1,2,3,4,5], n = 2
    printf("Test Case 1:\n");
    int nums1[] = {1, 2, 3, 4, 5};
    struct ListNode* head1 = createList(nums1, 5);
    printf("Initial list: ");
    printList(head1);
    head1 = removeNthFromEnd(head1, 2);
    printf("Result list: ");
    printList(head1);
    printf("Expected: 1 -> 2 -> 3 -> 5 -> NULL\n\n");

    // LeetCode default test case 2: head = [1], n = 1
    printf("Test Case 2:\n");
    int nums2[] = {1};
    struct ListNode* head2 = createList(nums2, 1);
    printf("Initial list: ");
    printList(head2);
    head2 = removeNthFromEnd(head2, 1);
    printf("Result list: ");
    printList(head2);
    printf("Expected: NULL\n\n");
    
    // LeetCode default test case 3: head = [1,2], n = 1
    printf("Test Case 3:\n");
    int nums3[] = {1, 2};
    struct ListNode* head3 = createList(nums3, 2);
    printf("Initial list: ");
    printList(head3);
    head3 = removeNthFromEnd(head3, 1);
    printf("Result list: ");
    printList(head3);
    printf("Expected: 1 -> NULL\n\n");
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    // Dummy node to handle the case where the head itself needs to be swapped.
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    struct ListNode* first = head;

    while (first != NULL && first->next != NULL) {
        struct ListNode* second = first->next;
        
        // Swapping the pointers
        prev->next = second;
        first->next = second->next;
        second->next = first;
        
        // Move pointers forward for the next pair
        prev = first;
        first = first->next;
    }
    
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
    // LeetCode default test case 1: head = [1,2,3,4]
    printf("Test Case 1:\n");
    int nums1[] = {1, 2, 3, 4};
    struct ListNode* head1 = createList(nums1, 4);
    printf("Initial list: ");
    printList(head1);
    head1 = swapPairs(head1);
    printf("Swapped list: ");
    printList(head1);
    printf("Expected: 2 -> 1 -> 4 -> 3 -> NULL\n\n");
    
    // LeetCode default test case 2: head = []
    printf("Test Case 2:\n");
    int nums2[] = {};
    struct ListNode* head2 = createList(nums2, 0);
    printf("Initial list: ");
    printList(head2);
    head2 = swapPairs(head2);
    printf("Swapped list: ");
    printList(head2);
    printf("Expected: NULL\n\n");
    
    // LeetCode default test case 3: head = [1]
    printf("Test Case 3:\n");
    int nums3[] = {1};
    struct ListNode* head3 = createList(nums3, 1);
    printf("Initial list: ");
    printList(head3);
    head3 = swapPairs(head3);
    printf("Swapped list: ");
    printList(head3);
    printf("Expected: 1 -> NULL\n\n");

    return 0;
}
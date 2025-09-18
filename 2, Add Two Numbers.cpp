#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;
        
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        int digit = sum % 10;
        
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = digit;
        current->next = NULL;
        
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
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
    // LeetCode default test case 1: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    printf("Test Case 1:\n");
    int nums1_1[] = {2, 4, 3};
    int nums1_2[] = {5, 6, 4};
    struct ListNode* l1_1 = createList(nums1_1, 3);
    struct ListNode* l1_2 = createList(nums1_2, 3);
    printf("Input: ");
    printList(l1_1);
    printf("       + ");
    printList(l1_2);
    struct ListNode* result1 = addTwoNumbers(l1_1, l1_2);
    printf("Result: ");
    printList(result1);
    printf("Expected: 7 -> 0 -> 8 -> NULL\n\n");

    // LeetCode default test case 2: (0) + (0)
    printf("Test Case 2:\n");
    int nums2_1[] = {0};
    int nums2_2[] = {0};
    struct ListNode* l2_1 = createList(nums2_1, 1);
    struct ListNode* l2_2 = createList(nums2_2, 1);
    printf("Input: ");
    printList(l2_1);
    printf("       + ");
    printList(l2_2);
    struct ListNode* result2 = addTwoNumbers(l2_1, l2_2);
    printf("Result: ");
    printList(result2);
    printf("Expected: 0 -> NULL\n\n");
    
    // LeetCode default test case 3: (9,9,9,9,9,9,9) + (9,9,9,9)
    printf("Test Case 3:\n");
    int nums3_1[] = {9, 9, 9, 9, 9, 9, 9};
    int nums3_2[] = {9, 9, 9, 9};
    struct ListNode* l3_1 = createList(nums3_1, 7);
    struct ListNode* l3_2 = createList(nums3_2, 4);
    printf("Input: ");
    printList(l3_1);
    printf("       + ");
    printList(l3_2);
    struct ListNode* result3 = addTwoNumbers(l3_1, l3_2);
    printf("Result: ");
    printList(result3);
    printf("Expected: 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1 -> NULL\n\n");

    return 0;
}
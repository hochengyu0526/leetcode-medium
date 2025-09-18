#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool canJump(int* nums, int numsSize) {
    int max_reach = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        // If the current index is beyond the max reachable index,
        // it's impossible to proceed.
        if (i > max_reach) {
            return false;
        }
        
        // Update the max reachable index
        if (i + nums[i] > max_reach) {
            max_reach = i + nums[i];
        }
        
        // If we can already reach the end, we're done
        if (max_reach >= numsSize - 1) {
            return true;
        }
    }
    
    return max_reach >= numsSize - 1;
}

int main() {
    // LeetCode default test case 1: nums = [2,3,1,1,4]
    printf("Test Case 1:\n");
    int nums1[] = {2, 3, 1, 1, 4};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Input: [2,3,1,1,4]\n");
    printf("Result: %s\n", canJump(nums1, numsSize1) ? "true" : "false");
    printf("Expected: true\n\n");

    // LeetCode default test case 2: nums = [3,2,1,0,4]
    printf("Test Case 2:\n");
    int nums2[] = {3, 2, 1, 0, 4};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Input: [3,2,1,0,4]\n");
    printf("Result: %s\n", canJump(nums2, numsSize2) ? "true" : "false");
    printf("Expected: false\n\n");
    
    // Custom test case 3: nums = [0]
    printf("Test Case 3:\n");
    int nums3[] = {0};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Input: [0]\n");
    printf("Result: %s\n", canJump(nums3, numsSize3) ? "true" : "false");
    printf("Expected: true\n\n");

    return 0;
}
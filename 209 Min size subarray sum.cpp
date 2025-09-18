#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minLength = INT_MAX;
        
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            
            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};

void printResult(int target, const vector<int>& nums, int result) {
    cout << "Input: target = " << target << ", nums = {";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    cout << "}" << endl;
    cout << "Minimum subarray length: " << result << endl;
    cout << "--------------------" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int target1 = 7;
    printResult(target1, nums1, solution.minSubArrayLen(target1, nums1)); // Expected: 2
    
    // Test case 2 from LeetCode
    vector<int> nums2 = {1, 4, 4};
    int target2 = 4;
    printResult(target2, nums2, solution.minSubArrayLen(target2, nums2)); // Expected: 1

    // Test case 3 from LeetCode
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    int target3 = 11;
    printResult(target3, nums3, solution.minSubArrayLen(target3, nums3)); // Expected: 0
    
    // Additional test case
    vector<int> nums4 = {1, 2, 3, 4, 5};
    int target4 = 15;
    printResult(target4, nums4, solution.minSubArrayLen(target4, nums4)); // Expected: 5

    return 0;
}
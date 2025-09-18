#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int mx = 0;
        
        for (int num : nums) {
            // Only start a sequence check if the current number is the potential start of a sequence.
            // A number `n` is a start if `n-1` is not in the set.
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Find the length of the consecutive sequence
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }
                
                // Update the maximum streak found so far
                mx = max(mx, currentStreak);
            }
        }
        
        return mx;
    }
};

void printResult(const vector<int>& nums, int result) {
    cout << "Input: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    cout << "Longest consecutive sequence length: " << result << endl;
    cout << "--------------------" << endl;
}

int main() {
    Solution solution;

    // Test case 1 from LeetCode
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    printResult(nums1, solution.longestConsecutive(nums1)); // Expected: 4 (from 1, 2, 3, 4)

    // Test case 2 from LeetCode
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    printResult(nums2, solution.longestConsecutive(nums2)); // Expected: 9 (from 0 to 8)

    // Test case 3 with empty input
    vector<int> nums3 = {};
    printResult(nums3, solution.longestConsecutive(nums3)); // Expected: 0
    
    // Test case 4 with a single element
    vector<int> nums4 = {5};
    printResult(nums4, solution.longestConsecutive(nums4)); // Expected: 1
    
    return 0;
}
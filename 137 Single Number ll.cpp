#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};

void printResult(const vector<int>& nums, int result) {
    cout << "Input: {";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    cout << "}" << endl;
    cout << "Single number: " << result << endl;
    cout << "--------------------" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    vector<int> nums1 = {2, 2, 3, 2};
    printResult(nums1, solution.singleNumber(nums1)); // Expected: 3
    
    // Test case 2 from LeetCode
    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};
    printResult(nums2, solution.singleNumber(nums2)); // Expected: 99
    
    // Additional Test case
    vector<int> nums3 = {1, 1, 1, 4};
    printResult(nums3, solution.singleNumber(nums3)); // Expected: 4
    
    return 0;
}
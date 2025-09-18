#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        long long mn_diff = LLONG_MAX;
        int result = 0;
        
        for (size_t i = 0; i < nums.size(); ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                long long current_sum = (long long)nums[i] + nums[left] + nums[right];
                long long diff = abs(target - current_sum);

                if (diff < mn_diff) {
                    mn_diff = diff;
                    result = current_sum;
                }
                
                if (current_sum < target) {
                    left++;
                } else if (current_sum > target) {
                    right--;
                } else {
                    return current_sum; // Found the exact target
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: nums = [-1,2,1,-4], target = 1
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    cout << "Input: nums = [-1,2,1,-4], target = 1" << endl;
    cout << "Result: " << s.threeSumClosest(nums1, target1) << endl;
    cout << "Expected: 2 ((-1 + 2 + 1) = 2)" << endl;
    cout << endl;

    // LeetCode default test case 2: nums = [0,0,0], target = 1
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    cout << "Input: nums = [0,0,0], target = 1" << endl;
    cout << "Result: " << s.threeSumClosest(nums2, target2) << endl;
    cout << "Expected: 0" << endl;
    cout << endl;
    
    // Custom test case 3: nums = [1,1,1,1], target = -100
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {1, 1, 1, 1};
    int target3 = -100;
    cout << "Input: nums = [1,1,1,1], target = -100" << endl;
    cout << "Result: " << s.threeSumClosest(nums3, target3) << endl;
    cout << "Expected: 3" << endl;
    cout << endl;
    
    return 0;
}
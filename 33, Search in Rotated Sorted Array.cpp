#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[left] <= nums[mid]) {
                // Check if target is in the sorted left half
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Otherwise, the right half must be sorted
            else {
                // Check if target is in the sorted right half
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

// Helper function to print a vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution s;

    // LeetCode default test case 1: nums = [4,5,6,7,0,1,2], target = 0
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "Input: nums = [4,5,6,7,0,1,2], target = 0" << endl;
    cout << "Result: " << s.search(nums1, target1) << endl;
    cout << "Expected: 4" << endl;
    cout << endl;

    // LeetCode default test case 2: nums = [4,5,6,7,0,1,2], target = 3
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << "Input: nums = [4,5,6,7,0,1,2], target = 3" << endl;
    cout << "Result: " << s.search(nums2, target2) << endl;
    cout << "Expected: -1" << endl;
    cout << endl;
    
    // LeetCode default test case 3: nums = [1], target = 1
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {1};
    int target3 = 1;
    cout << "Input: nums = [1], target = 1" << endl;
    cout << "Result: " << s.search(nums3, target3) << endl;
    cout << "Expected: 0" << endl;
    cout << endl;

    return 0;
}
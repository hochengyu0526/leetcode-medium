#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = find_first(nums, target);
        if (first == -1) {
            return {-1, -1};
        }
        int last = find_last(nums, target);
        return {first, last};
    }

private:
    int find_first(const vector<int>& nums, int target) {
        int index = -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            if (nums[mid] == target) {
                index = mid;
            }
        }
        return index;
    }

    int find_last(const vector<int>& nums, int target) {
        int index = -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (nums[mid] == target) {
                index = mid;
            }
        }
        return index;
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

    // LeetCode default test case 1: nums = [5,7,7,8,8,10], target = 8
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    cout << "Input: nums = [5,7,7,8,8,10], target = 8" << endl;
    vector<int> result1 = s.searchRange(nums1, target1);
    cout << "Output: ";
    printVector(result1);
    cout << "Expected: [3, 4]" << endl;
    cout << endl;

    // LeetCode default test case 2: nums = [5,7,7,8,8,10], target = 6
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    cout << "Input: nums = [5,7,7,8,8,10], target = 6" << endl;
    vector<int> result2 = s.searchRange(nums2, target2);
    cout << "Output: ";
    printVector(result2);
    cout << "Expected: [-1, -1]" << endl;
    cout << endl;

    // LeetCode default test case 3: nums = [], target = 0
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {};
    int target3 = 0;
    cout << "Input: nums = [], target = 0" << endl;
    vector<int> result3 = s.searchRange(nums3, target3);
    cout << "Output: ";
    printVector(result3);
    cout << "Expected: [-1, -1]" << endl;
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxsum = INT_MIN, currentsum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            currentsum = max(nums[i], currentsum + nums[i]);
            mxsum = max(currentsum, mxsum);
        }
        return mxsum;
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

    // LeetCode default test case 1: nums = [-2,1,-3,4,-1,2,1,-5,4]
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Input: ";
    printVector(nums1);
    cout << "Maximum subarray sum: " << s.maxSubArray(nums1) << endl;
    cout << "Expected: 6" << endl;
    cout << "Explanation: [4,-1,2,1] has the largest sum = 6." << endl;
    cout << endl;

    // LeetCode default test case 2: nums = [1]
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {1};
    cout << "Input: ";
    printVector(nums2);
    cout << "Maximum subarray sum: " << s.maxSubArray(nums2) << endl;
    cout << "Expected: 1" << endl;
    cout << endl;

    // LeetCode default test case 3: nums = [5,4,-1,7,8]
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << "Input: ";
    printVector(nums3);
    cout << "Maximum subarray sum: " << s.maxSubArray(nums3) << endl;
    cout << "Expected: 23" << endl;
    cout << endl;

    return 0;
}
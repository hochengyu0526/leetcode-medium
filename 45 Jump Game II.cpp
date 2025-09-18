#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int count = 0, furth = 0, current_end = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            furth = max(furth, i + nums[i]);
            if (i == current_end) {
                count++;
                current_end = furth;
            }
        }
        return count;
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

    // LeetCode default test case 1: nums = [2,3,1,1,4]
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Input: ";
    printVector(nums1);
    cout << "Minimum jumps: " << s.jump(nums1) << endl;
    cout << "Expected: 2" << endl;
    cout << endl;

    // LeetCode default test case 2: nums = [2,3,0,1,4]
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Input: ";
    printVector(nums2);
    cout << "Minimum jumps: " << s.jump(nums2) << endl;
    cout << "Expected: 2" << endl;
    cout << endl;

    // Custom test case 3: nums = [1]
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {1};
    cout << "Input: ";
    printVector(nums3);
    cout << "Minimum jumps: " << s.jump(nums3) << endl;
    cout << "Expected: 0" << endl;
    cout << endl;

    return 0;
}
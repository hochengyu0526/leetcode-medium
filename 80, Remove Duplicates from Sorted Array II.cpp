#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        
        int n = 2; // Start with the first two elements, which are always valid
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[n - 2]) {
                nums[n] = nums[i];
                n++;
            }
        }
        return n;
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

    // LeetCode default test case 1: nums = [1,1,1,2,2,3]
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = s.removeDuplicates(nums1);
    cout << "Original nums: [1,1,1,2,2,3]" << endl;
    cout << "Expected k = 5, nums = [1,1,2,2,3,_]" << endl;
    cout << "Your k = " << k1 << endl;
    cout << "Your nums up to k: ";
    for (int i = 0; i < k1; ++i) {
        cout << nums1[i] << (i == k1 - 1 ? "" : ", ");
    }
    cout << endl << endl;

    // LeetCode default test case 2: nums = [0,0,1,1,1,1,2,3,3]
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int k2 = s.removeDuplicates(nums2);
    cout << "Original nums: [0,0,1,1,1,1,2,3,3]" << endl;
    cout << "Expected k = 7, nums = [0,0,1,1,2,3,3,_,_]" << endl;
    cout << "Your k = " << k2 << endl;
    cout << "Your nums up to k: ";
    for (int i = 0; i < k2; ++i) {
        cout << nums2[i] << (i == k2 - 1 ? "" : ", ");
    }
    cout << endl << endl;

    return 0;
}
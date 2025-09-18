#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
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

    // LeetCode default test case 1: nums = [2,0,2,1,1,0]
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    cout << "Original array: ";
    printVector(nums1);
    s.sortColors(nums1);
    cout << "Sorted array: ";
    printVector(nums1);
    cout << "Expected: [0, 0, 1, 1, 2, 2]" << endl;
    cout << endl;

    // LeetCode default test case 2: nums = [2,0,1]
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {2, 0, 1};
    cout << "Original array: ";
    printVector(nums2);
    s.sortColors(nums2);
    cout << "Sorted array: ";
    printVector(nums2);
    cout << "Expected: [0, 1, 2]" << endl;
    cout << endl;

    return 0;
}
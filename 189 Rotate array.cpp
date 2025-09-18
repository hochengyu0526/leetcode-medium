#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // 處理 k 大於 n 的情況
        
        // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.end());
        
        // Step 2: Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Step 3: Reverse the remaining n-k elements
        reverse(nums.begin() + k, nums.end());
    }
};

void printVector(const vector<int>& nums) {
    cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    cout << "Initial array: ";
    printVector(nums1);
    solution.rotate(nums1, k1);
    cout << "Rotated array (k=" << k1 << "): ";
    printVector(nums1); // Expected: [5, 6, 7, 1, 2, 3, 4]
    cout << "--------------------" << endl;
    
    // Test case 2 from LeetCode
    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    cout << "Initial array: ";
    printVector(nums2);
    solution.rotate(nums2, k2);
    cout << "Rotated array (k=" << k2 << "): ";
    printVector(nums2); // Expected: [3, 99, -1, -100]
    cout << "--------------------" << endl;
    
    return 0;
}
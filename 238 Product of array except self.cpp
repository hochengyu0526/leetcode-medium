#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        // First Pass: Calculate left products
        int left_product = 1;
        for (int i = 0; i < n; i++) {
            result[i] = left_product;
            left_product *= nums[i];
        }

        // Second Pass: Calculate right products and combine
        int right_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= right_product;
            right_product *= nums[i];
        }

        return result;
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Input: ";
    printVector(nums1);
    vector<int> result1 = solution.productExceptSelf(nums1);
    cout << "Output: ";
    printVector(result1); // Expected: [24, 12, 8, 6]
    cout << "--------------------" << endl;
    
    // Test case 2 from LeetCode
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    cout << "Input: ";
    printVector(nums2);
    vector<int> result2 = solution.productExceptSelf(nums2);
    cout << "Output: ";
    printVector(result2); // Expected: [0, 0, 9, 0, 0]
    cout << "--------------------" << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (!next_permutation(nums.begin(), nums.end())) {
            // If the current permutation is the last, next_permutation returns false
            // and rearranges the range to the first permutation.
            sort(nums.begin(), nums.end());
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

    // LeetCode default test case 1: nums = [1,2,3]
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 2, 3};
    cout << "Initial array: ";
    printVector(nums1);
    s.nextPermutation(nums1);
    cout << "Next permutation: ";
    printVector(nums1);
    cout << "Expected: [1, 3, 2]" << endl;
    cout << endl;

    // LeetCode default test case 2: nums = [3,2,1]
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {3, 2, 1};
    cout << "Initial array: ";
    printVector(nums2);
    s.nextPermutation(nums2);
    cout << "Next permutation: ";
    printVector(nums2);
    cout << "Expected: [1, 2, 3]" << endl;
    cout << endl;
    
    // LeetCode default test case 3: nums = [1,1,5]
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {1, 1, 5};
    cout << "Initial array: ";
    printVector(nums3);
    s.nextPermutation(nums3);
    cout << "Next permutation: ";
    printVector(nums3);
    cout << "Expected: [1, 5, 1]" << endl;
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 2; ++i) {
            // Skip duplicate for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second and third elements
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};

// Helper function to print a vector of vectors
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << (j == result[i].size() - 1 ? "" : ", ");
        }
        cout << "]" << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution s;

    // LeetCode default test case 1: nums = [-1,0,1,2,-1,-4]
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    cout << "Input: [-1,0,1,2,-1,-4]" << endl;
    vector<vector<int>> result1 = s.threeSum(nums1);
    cout << "Output: ";
    printResult(result1);
    cout << "Expected: [[-1,-1,2],[-1,0,1]] (order may vary)" << endl;
    cout << endl;

    // LeetCode default test case 2: nums = [0,1,1]
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {0, 1, 1};
    cout << "Input: [0,1,1]" << endl;
    vector<vector<int>> result2 = s.threeSum(nums2);
    cout << "Output: ";
    printResult(result2);
    cout << "Expected: []" << endl;
    cout << endl;
    
    // LeetCode default test case 3: nums = [0,0,0]
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {0, 0, 0};
    cout << "Input: [0,0,0]" << endl;
    vector<vector<int>> result3 = s.threeSum(nums3);
    cout << "Output: ";
    printResult(result3);
    cout << "Expected: [[0,0,0]]" << endl;
    cout << endl;
    
    return 0;
}
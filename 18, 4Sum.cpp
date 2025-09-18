#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

// Helper function to print a vector of vectors of integers
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

    // LeetCode default test case 1: nums = [1,0,-1,0,-2,2], target = 0
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    cout << "Input: nums = [1,0,-1,0,-2,2], target = 0" << endl;
    vector<vector<int>> result1 = s.fourSum(nums1, target1);
    cout << "Output: ";
    printResult(result1);
    cout << "Expected: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]" << endl;
    cout << endl;
    
    // LeetCode default test case 2: nums = [2,2,2,2,2], target = 8
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    cout << "Input: nums = [2,2,2,2,2], target = 8" << endl;
    vector<vector<int>> result2 = s.fourSum(nums2, target2);
    cout << "Output: ";
    printResult(result2);
    cout << "Expected: [[2,2,2,2]]" << endl;
    cout << endl;

    return 0;
}
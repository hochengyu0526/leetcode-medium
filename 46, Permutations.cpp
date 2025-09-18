#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteRecursive(nums, 0, result);
        return result;
    }
private:
    void permuteRecursive(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            permuteRecursive(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
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

    // LeetCode default test case 1: nums = [1,2,3]
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 2, 3};
    cout << "Input: [1,2,3]" << endl;
    vector<vector<int>> result1 = s.permute(nums1);
    cout << "Output:" << endl;
    printResult(result1);
    cout << "Expected Output (order may vary): [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]" << endl;
    cout << endl;

    // LeetCode default test case 2: nums = [0,1]
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {0, 1};
    cout << "Input: [0,1]" << endl;
    vector<vector<int>> result2 = s.permute(nums2);
    cout << "Output:" << endl;
    printResult(result2);
    cout << "Expected Output (order may vary): [[0,1],[1,0]]" << endl;
    cout << endl;
    
    // LeetCode default test case 3: nums = [1]
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {1};
    cout << "Input: [1]" << endl;
    vector<vector<int>> result3 = s.permute(nums3);
    cout << "Output:" << endl;
    printResult(result3);
    cout << "Expected Output: [[1]]" << endl;
    cout << endl;

    return 0;
}
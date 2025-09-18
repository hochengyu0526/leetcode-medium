#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); ++i) {
            backtrack(nums, result, current, i, 0, used);
        }
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, int arraysize, int start, vector<bool>& used) {
        if (current.size() == arraysize) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, result, current, arraysize, i + 1, used);
            current.pop_back();
            used[i] = false;
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

    // LeetCode default test case 1: nums = [1,2,2]
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 2, 2};
    vector<vector<int>> result1 = s.subsetsWithDup(nums1);
    cout << "Input: [1,2,2]" << endl;
    cout << "Expected Output (order may vary): [[],[1],[1,2],[1,2,2],[2],[2,2]]" << endl;
    cout << "Your Output: ";
    printResult(result1);
    cout << endl;

    // LeetCode default test case 2: nums = [0]
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {0};
    vector<vector<int>> result2 = s.subsetsWithDup(nums2);
    cout << "Input: [0]" << endl;
    cout << "Expected Output: [[],[0]]" << endl;
    cout << "Your Output: ";
    printResult(result2);
    cout << endl;

    return 0;
}
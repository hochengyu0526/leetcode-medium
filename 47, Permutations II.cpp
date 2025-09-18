#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> current;
        sort(nums.begin(), nums.end());
        permute(nums, current, result, used);
        return result;
    }
private:
    void permute(vector<int>& nums, vector<int>& current, vector<vector<int>>& result, vector<bool>& used) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            used[i] = true;
            current.push_back(nums[i]);
            permute(nums, current, result, used);
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

    // LeetCode default test case 1: nums = [1,1,2]
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 1, 2};
    cout << "Input: [1,1,2]" << endl;
    vector<vector<int>> result1 = s.permuteUnique(nums1);
    cout << "Output:" << endl;
    printResult(result1);
    cout << "Expected Output: [[1,1,2],[1,2,1],[2,1,1]]" << endl;
    cout << endl;

    // LeetCode default test case 2: nums = [2,2,1,1]
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {2, 2, 1, 1};
    cout << "Input: [2,2,1,1]" << endl;
    vector<vector<int>> result2 = s.permuteUnique(nums2);
    cout << "Output:" << endl;
    printResult(result2);
    cout << "Expected Output (order may vary): [[1,1,2,2],[1,2,1,2],[1,2,2,1],[2,1,1,2],[2,1,2,1],[2,2,1,1]]" << endl;
    cout << endl;

    return 0;
}
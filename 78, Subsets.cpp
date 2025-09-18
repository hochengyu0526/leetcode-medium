#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        for (int i = 0; i <= nums.size(); ++i) {
            backtrack(nums, result, current, i, 0);
        }
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, int arraysize, int start) {
        if (current.size() == arraysize) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            backtrack(nums, result, current, arraysize, i + 1);
            current.pop_back();
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
    vector<vector<int>> result1 = s.subsets(nums1);
    cout << "Input: [1,2,3]" << endl;
    cout << "Expected Output (order may vary): [[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]" << endl;
    cout << "Your Output: ";
    printResult(result1);
    cout << endl;

    // LeetCode default test case 2: nums = [0]
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {0};
    vector<vector<int>> result2 = s.subsets(nums2);
    cout << "Input: [0]" << endl;
    cout << "Expected Output: [[],[0]]" << endl;
    cout << "Your Output: ";
    printResult(result2);
    cout << endl;

    return 0;
}
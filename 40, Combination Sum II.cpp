#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current, result);
        return result;
    }
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) {
                break;
            }
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current, result);
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

    // LeetCode default test case 1: candidates = [10,1,2,7,6,1,5], target = 8
    cout << "Test Case 1:" << endl;
    vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;
    cout << "Candidates: [10,1,2,7,6,1,5], Target: 8" << endl;
    vector<vector<int>> result1 = s.combinationSum2(candidates1, target1);
    cout << "Output: ";
    printResult(result1);
    cout << "Expected: [[1,1,6],[1,2,5],[1,7],[2,6]] (order may vary)" << endl;
    cout << endl;

    // LeetCode default test case 2: candidates = [2,5,2,1,2], target = 5
    cout << "Test Case 2:" << endl;
    vector<int> candidates2 = {2, 5, 2, 1, 2};
    int target2 = 5;
    cout << "Candidates: [2,5,2,1,2], Target: 5" << endl;
    vector<vector<int>> result2 = s.combinationSum2(candidates2, target2);
    cout << "Output: ";
    printResult(result2);
    cout << "Expected: [[1,2,2],[5]] (order may vary)" << endl;
    cout << endl;
    
    return 0;
}
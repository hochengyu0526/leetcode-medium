#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            if (target < candidates[i]) {
                continue;
            }
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, result);
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

    // LeetCode default test case 1: candidates = [2,3,6,7], target = 7
    cout << "Test Case 1:" << endl;
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    cout << "Candidates: [2,3,6,7], Target: 7" << endl;
    vector<vector<int>> result1 = s.combinationSum(candidates1, target1);
    cout << "Output: ";
    printResult(result1);
    cout << "Expected: [[2,2,3],[7]] (order may vary)" << endl;
    cout << endl;

    // LeetCode default test case 2: candidates = [2,3,5], target = 8
    cout << "Test Case 2:" << endl;
    vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    cout << "Candidates: [2,3,5], Target: 8" << endl;
    vector<vector<int>> result2 = s.combinationSum(candidates2, target2);
    cout << "Output: ";
    printResult(result2);
    cout << "Expected: [[2,2,2,2],[2,3,3],[3,5]] (order may vary)" << endl;
    cout << endl;

    // LeetCode custom test case 3: candidates = [2], target = 1
    cout << "Test Case 3:" << endl;
    vector<int> candidates3 = {2};
    int target3 = 1;
    cout << "Candidates: [2], Target: 1" << endl;
    vector<vector<int>> result3 = s.combinationSum(candidates3, target3);
    cout << "Output: ";
    printResult(result3);
    cout << "Expected: []" << endl;
    cout << endl;
    
    return 0;
}
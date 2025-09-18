#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};

// Helper function to print a vector of vectors
void printIntervals(const vector<vector<int>>& intervals) {
    cout << "[";
    for (size_t i = 0; i < intervals.size(); ++i) {
        cout << "[" << intervals[i][0] << ", " << intervals[i][1] << "]" << (i == intervals.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution s;

    // LeetCode default test case 1: intervals = [[1,3],[2,6],[8,10],[15,18]]
    cout << "Test Case 1:" << endl;
    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    cout << "Original intervals: ";
    printIntervals(intervals1);
    vector<vector<int>> result1 = s.merge(intervals1);
    cout << "Merged intervals: ";
    printIntervals(result1);
    cout << "Expected: [[1, 6], [8, 10], [15, 18]]" << endl;
    cout << endl;

    // LeetCode default test case 2: intervals = [[1,4],[4,5]]
    cout << "Test Case 2:" << endl;
    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    cout << "Original intervals: ";
    printIntervals(intervals2);
    vector<vector<int>> result2 = s.merge(intervals2);
    cout << "Merged intervals: ";
    printIntervals(result2);
    cout << "Expected: [[1, 5]]" << endl;
    cout << endl;
    
    // LeetCode custom test case 3: intervals = [[1,4],[0,4]]
    cout << "Test Case 3:" << endl;
    vector<vector<int>> intervals3 = {{1, 4}, {0, 4}};
    cout << "Original intervals: ";
    printIntervals(intervals3);
    vector<vector<int>> result3 = s.merge(intervals3);
    cout << "Merged intervals: ";
    printIntervals(result3);
    cout << "Expected: [[0, 4]]" << endl;
    cout << endl;

    return 0;
}
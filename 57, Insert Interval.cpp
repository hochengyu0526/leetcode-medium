#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool placed = false;
        
        for (const auto& interval : intervals) {
            if (interval[1] < newInterval[0]) {
                // Case 1: The current interval is completely before the new interval.
                result.push_back(interval);
            } else if (interval[0] > newInterval[1]) {
                // Case 2: The current interval is completely after the new interval.
                // If the new interval hasn't been placed yet, place it now.
                if (!placed) {
                    result.push_back(newInterval);
                    placed = true;
                }
                result.push_back(interval);
            } else {
                // Case 3: The current interval overlaps with the new interval.
                // Merge them by updating the new interval's boundaries.
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
        }
        
        // If the new interval was never placed (e.g., it's the last one or empty list)
        if (!placed) {
            result.push_back(newInterval);
        }
        
        return result;
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

    // LeetCode default test case 1: intervals = [[1,3],[6,9]], newInterval = [2,5]
    cout << "Test Case 1:" << endl;
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    cout << "Intervals: ";
    printIntervals(intervals1);
    cout << "New Interval: [2, 5]" << endl;
    vector<vector<int>> result1 = s.insert(intervals1, newInterval1);
    cout << "Result: ";
    printIntervals(result1);
    cout << "Expected: [[1, 5], [6, 9]]" << endl;
    cout << endl;

    // LeetCode default test case 2: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    cout << "Test Case 2:" << endl;
    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    cout << "Intervals: ";
    printIntervals(intervals2);
    cout << "New Interval: [4, 8]" << endl;
    vector<vector<int>> result2 = s.insert(intervals2, newInterval2);
    cout << "Result: ";
    printIntervals(result2);
    cout << "Expected: [[1, 2], [3, 10], [12, 16]]" << endl;
    cout << endl;

    // LeetCode default test case 3: intervals = [], newInterval = [5,7]
    cout << "Test Case 3:" << endl;
    vector<vector<int>> intervals3 = {};
    vector<int> newInterval3 = {5, 7};
    cout << "Intervals: []" << endl;
    cout << "New Interval: [5, 7]" << endl;
    vector<vector<int>> result3 = s.insert(intervals3, newInterval3);
    cout << "Result: ";
    printIntervals(result3);
    cout << "Expected: [[5, 7]]" << endl;
    cout << endl;

    return 0;
}
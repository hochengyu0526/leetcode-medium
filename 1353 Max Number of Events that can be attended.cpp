#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sort(events.begin(), events.end());
        int result = 0;
        int i = 0;
        int n = events.size();
        int day = 1;

        while (i < n || !minHeap.empty()) {
            if (minHeap.empty()) {
                day = events[i][0];
            }
            // Add all events that start on or before the current day to the heap
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i++][1]); 
            }
            // Remove all events that have already ended
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
            // Attend the event that ends the earliest
            if (!minHeap.empty()) {
                minHeap.pop();
                result++;
                day++;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    vector<vector<int>> events1 = {{1, 2}, {2, 3}, {3, 4}};
    cout << "Events: [[1,2],[2,3],[3,4]]" << endl;
    cout << "Max events attended: " << solution.maxEvents(events1) << endl; // Expected output: 3
    cout << "--------------------" << endl;
    
    // Test case 2 from LeetCode
    vector<vector<int>> events2 = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
    cout << "Events: [[1,2],[2,3],[3,4],[1,2]]" << endl;
    cout << "Max events attended: " << solution.maxEvents(events2) << endl; // Expected output: 4
    cout << "--------------------" << endl;
    
    // Additional Test Case
    vector<vector<int>> events3 = {{1, 4}, {4, 4}, {2, 2}, {3, 4}, {1, 1}};
    cout << "Events: [[1,4],[4,4],[2,2],[3,4],[1,1]]" << endl;
    cout << "Max events attended: " << solution.maxEvents(events3) << endl; // Expected output: 4
    cout << "--------------------" << endl;

    return 0;
}
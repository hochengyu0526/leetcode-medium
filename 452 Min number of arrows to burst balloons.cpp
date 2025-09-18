#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        // Sort the balloons based on their end coordinate
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int current_end = points[0][1];

        // Iterate through the sorted balloons
        for (size_t i = 1; i < points.size(); ++i) {
            // If the current balloon starts after the last arrow's shot point,
            // we need a new arrow.
            if (points[i][0] > current_end) {
                arrows++;
                current_end = points[i][1];
            }
        }

        return arrows;
    }
};

void printResult(const vector<vector<int>>& points, int result) {
    cout << "Input points: ";
    cout << "[";
    for (const auto& p : points) {
        cout << "[" << p[0] << "," << p[1] << "]";
    }
    cout << "]" << endl;
    cout << "Minimum arrows needed: " << result << endl;
    cout << "--------------------" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    vector<vector<int>> points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    printResult(points1, solution.findMinArrowShots(points1)); // Expected: 2

    // Test case 2 from LeetCode
    vector<vector<int>> points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    printResult(points2, solution.findMinArrowShots(points2)); // Expected: 4

    // Test case 3 from LeetCode
    vector<vector<int>> points3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    printResult(points3, solution.findMinArrowShots(points3)); // Expected: 2

    return 0;
}
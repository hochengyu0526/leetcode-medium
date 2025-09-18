#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        
        while (left < right) {
            int current_area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, current_area);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};

// Helper function to print a vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution s;

    // LeetCode default test case 1: height = [1,8,6,2,5,4,8,3,7]
    cout << "Test Case 1:" << endl;
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Input: ";
    printVector(height1);
    cout << "Maximum Area: " << s.maxArea(height1) << endl;
    cout << "Expected: 49" << endl;
    cout << endl;

    // LeetCode default test case 2: height = [1,1]
    cout << "Test Case 2:" << endl;
    vector<int> height2 = {1, 1};
    cout << "Input: ";
    printVector(height2);
    cout << "Maximum Area: " << s.maxArea(height2) << endl;
    cout << "Expected: 1" << endl;
    cout << endl;
    
    // Custom test case 3: height = [4,3,2,1,4]
    cout << "Test Case 3:" << endl;
    vector<int> height3 = {4, 3, 2, 1, 4};
    cout << "Input: ";
    printVector(height3);
    cout << "Maximum Area: " << s.maxArea(height3) << endl;
    cout << "Expected: 16" << endl;
    cout << endl;

    return 0;
}
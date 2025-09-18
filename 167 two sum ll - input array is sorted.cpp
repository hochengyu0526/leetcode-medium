#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum > target) {
                right--;
            } else if (sum < target) {
                left++;
            } else {
                break;
            }
        }
        
        return {left + 1, right + 1};
    }
};

void printResult(const vector<int>& result) {
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
}

int main() {
    Solution solution;

    // Test Case 1 from LeetCode
    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    cout << "Test Case 1: numbers = {2, 7, 11, 15}, target = 9" << endl;
    vector<int> result1 = solution.twoSum(numbers1, target1);
    cout << "Result: ";
    printResult(result1); // Expected: [1, 2]
    cout << "--------------------" << endl;

    // Test Case 2 from LeetCode
    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    cout << "Test Case 2: numbers = {2, 3, 4}, target = 6" << endl;
    vector<int> result2 = solution.twoSum(numbers2, target2);
    cout << "Result: ";
    printResult(result2); // Expected: [1, 3]
    cout << "--------------------" << endl;
    
    // Test Case 3 from LeetCode
    vector<int> numbers3 = {-1, 0};
    int target3 = -1;
    cout << "Test Case 3: numbers = {-1, 0}, target = -1" << endl;
    vector<int> result3 = solution.twoSum(numbers3, target3);
    cout << "Result: ";
    printResult(result3); // Expected: [1, 2]
    cout << "--------------------" << endl;
    
    return 0;
}
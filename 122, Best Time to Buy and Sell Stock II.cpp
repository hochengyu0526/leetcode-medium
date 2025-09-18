#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) {
                result += prices[i] - prices[i-1];
            }
        }
        return result;
    }
};

void printResult(const vector<int>& prices, int result) {
    cout << "Prices: [";
    for (size_t i = 0; i < prices.size(); ++i) {
        cout << prices[i] << (i == prices.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    cout << "Maximum profit: " << result << endl;
    cout << "--------------------" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    printResult(prices1, solution.maxProfit(prices1)); // Expected: 7 ( (5-1) + (6-3) )

    // Test case 2 from LeetCode
    vector<int> prices2 = {1, 2, 3, 4, 5};
    printResult(prices2, solution.maxProfit(prices2)); // Expected: 4 ( (2-1) + (3-2) + (4-3) + (5-4) )

    // Test case 3 from LeetCode
    vector<int> prices3 = {7, 6, 4, 3, 1};
    printResult(prices3, solution.maxProfit(prices3)); // Expected: 0

    return 0;
}
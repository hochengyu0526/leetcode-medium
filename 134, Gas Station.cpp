#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate, although not used in your final code, it's a useful header for vector operations.

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current_gas = 0;
        int start_index = 0;
        int total_gas_diff = 0;
        
        for (int i = 0; i < gas.size(); ++i) {
            int gas_diff = gas[i] - cost[i];
            current_gas += gas_diff;
            total_gas_diff += gas_diff;

            // If we run out of gas at the current station,
            // we must start from the next station.
            if (current_gas < 0) {
                start_index = i + 1;
                current_gas = 0;
            }
        }

        // If total gas is less than total cost, no solution exists.
        if (total_gas_diff < 0) {
            return -1;
        }

        return start_index;
    }
};

void printResult(const vector<int>& gas, const vector<int>& cost, int result) {
    cout << "Gas: [";
    for (size_t i = 0; i < gas.size(); ++i) {
        cout << gas[i] << (i == gas.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    cout << "Cost: [";
    for (size_t i = 0; i < cost.size(); ++i) {
        cout << cost[i] << (i == cost.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    cout << "Starting index: " << result << endl;
    cout << "--------------------" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    printResult(gas1, cost1, solution.canCompleteCircuit(gas1, cost1)); // Expected: 3

    // Test case 2 from LeetCode
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    printResult(gas2, cost2, solution.canCompleteCircuit(gas2, cost2)); // Expected: -1
    
    // Additional Test case
    vector<int> gas3 = {5, 8, 2, 8};
    vector<int> cost3 = {6, 5, 6, 6};
    printResult(gas3, cost3, solution.canCompleteCircuit(gas3, cost3)); // Expected: 3
    
    return 0;
}
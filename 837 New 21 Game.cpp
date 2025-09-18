#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + maxPts + 1, 0.0);
        
        // Base cases: if the score is between k and n, Alice wins
        for(int i = k; i <= n; i++) {
            dp[i] = 1.0;
        }
        
        // Use a sliding window to calculate the sum of probabilities
        double sum = 0.0;
        for(int i = k; i < k + maxPts; i++) {
            sum += dp[i];
        }
        
        // Dynamic Programming: Calculate probabilities from k-1 down to 0
        for(int x = k - 1; x >= 0; x--) {
            dp[x] = sum / maxPts;
            sum += dp[x] - dp[x + maxPts];
        }
        
        return dp[0];
    }
};

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode: n=10, k=1, maxPts=10
    int n1 = 10, k1 = 1, maxPts1 = 10;
    cout << "Test Case 1 (n=10, k=1, maxPts=10):" << endl;
    cout << "Result: " << solution.new21Game(n1, k1, maxPts1) << endl; // Expected: 1.00000
    cout << "--------------------" << endl;
    
    // Test case 2 from LeetCode: n=6, k=1, maxPts=10
    int n2 = 6, k2 = 1, maxPts2 = 10;
    cout << "Test Case 2 (n=6, k=1, maxPts=10):" << endl;
    cout << "Result: " << solution.new21Game(n2, k2, maxPts2) << endl; // Expected: 0.60000
    cout << "--------------------" << endl;
    
    // Test case 3 from LeetCode: n=21, k=17, maxPts=10
    int n3 = 21, k3 = 17, maxPts3 = 10;
    cout << "Test Case 3 (n=21, k=17, maxPts=10):" << endl;
    cout << "Result: " << solution.new21Game(n3, k3, maxPts3) << endl; // Expected: 0.73278
    cout << "--------------------" << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        long long prev = LLONG_MIN;
        for (int num : nums) {
            long long L = max((long long)num - k, prev + 1);
            if (L <= (long long)num + k) {
                count++;
                prev = L;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    // 測試輸入
    vector<int> nums = {4, 4, 4, 4};
    int k = 1;

    int result = sol.maxDistinctElements(nums, k);
    cout << "Output: " << result << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> v(value, 0);
        int mn = INT_MAX;
        int minkey = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                int k = abs(nums[i]) / value;
                nums[i] += value * (k + 1);
            }
            v[nums[i] % value]++;
        }
        while (v[minkey % value] != 0) {
            v[minkey % value]--;
            minkey++;
        }
        return minkey;
    }
};

int main() {
    Solution sol;

    int n, value;
    cout << "輸入陣列大小 n: ";
    cin >> n;
    cout << "輸入 value: ";
    cin >> value;

    vector<int> nums(n);
    cout << "輸入 " << n << " 個整數 (以空白分隔): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.findSmallestInteger(nums, value);
    cout << "最小整數結果: " << result << endl;

    return 0;
}

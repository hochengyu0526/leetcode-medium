#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int k = nums.size() - 1; k >= 2; k--) {
            int j = k - 1;
            int i = 0;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    // 測試資料
    vector<int> nums = {2, 2, 3, 4};
    int result = sol.triangleNumber(nums);

    cout << "結果: " << result << endl;  // 預期輸出 3

    return 0;
}

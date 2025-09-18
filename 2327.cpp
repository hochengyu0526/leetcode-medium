#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
// 保留你原始的 LeetCode Solution 程式碼
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n);
        const int mod = 1e9 + 7;
        long long s=0;
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(i-delay<0){
                dp[i]=0;
                continue;
            }
            s+=dp[i-delay];
            if(i>=forget)s-=dp[i-forget];
            s = (s % mod + mod) % mod;
            dp[i]+=s;
        }
        long long result=0;
        int c=n-1;
        while(forget--){
            result+=dp[c];
            c--;
        }
        return result % mod;
    }
};

// 主函式，用於測試
int main() {
    Solution sol;
    
    // 範例一
    int n1 = 6;
    int delay1 = 2;
    int forget1 = 4;
    cout << "ex1: " << sol.peopleAwareOfSecret(n1, delay1, forget1) << endl;

    // 範例二
    int n2 = 4;
    int delay2 = 1;
    int forget2 = 3;
    cout << "ex2: " << sol.peopleAwareOfSecret(n2, delay2, forget2) << endl;
    
    return 0;
}
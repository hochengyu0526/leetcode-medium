#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string s;
        unordered_map<long long, int> m;

        // 判斷正負號
        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)) s += "-";

        // 轉 long long 避免 overflow
        long long n1 = llabs((long long)numerator), n2 = llabs((long long)denominator);

        // 整數部分
        s += to_string(n1 / n2);

        long long remainder = n1 % n2;
        if (remainder == 0) return s;

        s += ".";
        int n = s.size() - 1;
        m[remainder] = n;

        // 模擬小數部分
        while (remainder != 0) {
            remainder *= 10;
            s += to_string(remainder / n2);
            remainder = remainder % n2;
            n = s.size();

            if (m.count(remainder)) {
                if (s[m[remainder]] == '.') s.insert(m[remainder] + 1, "(");
                else s.insert(m[remainder], "(");
                s += ")";
                return s;
            }
            m[remainder] = n;
        }
        return s;
    }
};

int main() {
    Solution sol;

    // LeetCode 預設測資
    cout << sol.fractionToDecimal(1, 2) << endl;   // "0.5"
    cout << sol.fractionToDecimal(2, 1) << endl;   // "2"
    cout << sol.fractionToDecimal(2, 3) << endl;   // "0.(6)"

    return 0;
}

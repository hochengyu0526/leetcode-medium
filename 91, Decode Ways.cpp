#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        vector<int> dp;
        for(int i = 0; i <= s.size(); ++i) {
            int tmp = 0;
            if (i == 0 || i == 1) {
                tmp = 1;
                dp.push_back(tmp);
                continue;
            }
            if (s[i-1] != '0') {
                tmp += dp[i-1];
            }
            if (s[i-2] == '2' && s[i-1] >= '0' && s[i-1] <= '6') {
                tmp += dp[i-2];
            } else if (s[i-2] == '1') {
                tmp += dp[i-2];
            }
            dp.push_back(tmp);
        }
        return dp[s.size()];
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: s = "12"
    string s1 = "12";
    cout << "Test Case 1:" << endl;
    cout << "s = \"" << s1 << "\"" << endl;
    cout << "Number of decodings: " << s.numDecodings(s1) << endl;
    cout << "Expected: 2" << endl; // "12" -> "AB", "L"
    cout << endl;

    // LeetCode default test case 2: s = "226"
    string s2 = "226";
    cout << "Test Case 2:" << endl;
    cout << "s = \"" << s2 << "\"" << endl;
    cout << "Number of decodings: " << s.numDecodings(s2) << endl;
    cout << "Expected: 3" << endl; // "226" -> "BBF", "VF", "BZ"
    cout << endl;

    // LeetCode default test case 3: s = "0"
    string s3 = "0";
    cout << "Test Case 3:" << endl;
    cout << "s = \"" << s3 << "\"" << endl;
    cout << "Number of decodings: " << s.numDecodings(s3) << endl;
    cout << "Expected: 0" << endl;
    cout << endl;

    // LeetCode custom test case 4: s = "10"
    string s4 = "10";
    cout << "Test Case 4:" << endl;
    cout << "s = \"" << s4 << "\"" << endl;
    cout << "Number of decodings: " << s.numDecodings(s4) << endl;
    cout << "Expected: 1" << endl; // "10" -> "J"
    cout << endl;

    // LeetCode custom test case 5: s = "100"
    string s5 = "100";
    cout << "Test Case 5:" << endl;
    cout << "s = \"" << s5 << "\"" << endl;
    cout << "Number of decodings: " << s.numDecodings(s5) << endl;
    cout << "Expected: 0" << endl;
    cout << endl;

    // LeetCode custom test case 6: s = "27"
    string s6 = "27";
    cout << "Test Case 6:" << endl;
    cout << "s = \"" << s6 << "\"" << endl;
    cout << "Number of decodings: " << s.numDecodings(s6) << endl;
    cout << "Expected: 1" << endl; // "27" -> "BG"
    cout << endl;

    return 0;
}
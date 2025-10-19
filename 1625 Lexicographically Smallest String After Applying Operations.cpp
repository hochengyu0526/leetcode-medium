#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> visit;
        string result = s;
        q.push(s);
        visit.insert(s);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            result = min(result, curr);

            // 奇數位加 a (mod 10)
            string s1 = curr;
            for (int i = 1; i < s1.size(); i += 2) {
                int tmp = s1[i] - '0';
                tmp = (tmp + a) % 10;
                s1[i] = tmp + '0';
            }
            if (!visit.count(s1)) {
                visit.insert(s1);
                q.push(s1);
            }

            // 右旋 b 位
            string rotated = curr.substr(curr.size() - b) + curr.substr(0, curr.size() - b);
            if (!visit.count(rotated)) {
                visit.insert(rotated);
                q.push(rotated);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // 範例輸入
    string s;
    int a, b;
    cout << "輸入字串 s: ";
    cin >> s;
    cout << "輸入 a: ";
    cin >> a;
    cout << "輸入 b: ";
    cin >> b;

    string ans = sol.findLexSmallestString(s, a, b);
    cout << "字典序最小的結果: " << ans << endl;

    return 0;
}

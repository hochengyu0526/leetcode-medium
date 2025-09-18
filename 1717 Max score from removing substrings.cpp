#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // We will process the string based on which pair gives a higher score.
        // Let's call the higher-scoring pair "primary" and the other "secondary".
        string s_copy = s;
        int score = 0;

        // Step 1: Process the higher-scoring pair first
        if (x >= y) {
            // Process "ab" first
            string remaining = processString(s_copy, 'a', 'b', x, score);
            // Then process "ba" from the remaining string
            processString(remaining, 'b', 'a', y, score);
        } else {
            // Process "ba" first
            string remaining = processString(s_copy, 'b', 'a', y, score);
            // Then process "ab" from the remaining string
            processString(remaining, 'a', 'b', x, score);
        }

        return score;
    }

private:
    string processString(string s, char c1, char c2, int pts, int& score) {
        stack<char> st;
        for (char ch : s) {
            if (ch == c2 && !st.empty() && st.top() == c1) {
                st.pop();
                score += pts;
            } else {
                st.push(ch);
            }
        }
        string remaining = "";
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());
        return remaining;
    }
};

int main() {
    Solution sol;
    
    // Test case 1 from LeetCode
    string s1 = "cdbcbbaaabab";
    int x1 = 4, y1 = 5;
    cout << "String: " << s1 << ", x: " << x1 << ", y: " << y1 << endl;
    cout << "Maximum gain: " << sol.maximumGain(s1, x1, y1) << endl; // Expected: 13
    cout << "--------------------" << endl;

    // Test case 2 from LeetCode
    string s2 = "aabbaaxybbaabb";
    int x2 = 5, y2 = 4;
    cout << "String: " << s2 << ", x: " << x2 << ", y: " << y2 << endl;
    cout << "Maximum gain: " << sol.maximumGain(s2, x2, y2) << endl; // Expected: 20
    cout << "--------------------" << endl;

    return 0;
}
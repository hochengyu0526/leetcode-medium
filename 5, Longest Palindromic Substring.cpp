#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        
        int start = 0;
        int maxLength = 1;
        
        for (int i = 0; i < s.size(); ++i) {
            // Odd-length palindromes (e.g., "aba")
            expandAroundCenter(s, i, i, start, maxLength);
            
            // Even-length palindromes (e.g., "abba")
            expandAroundCenter(s, i, i + 1, start, maxLength);
        }
        
        return s.substr(start, maxLength);
    }

private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLength) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            int currentLength = right - left + 1;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = left;
            }
            left--;
            right++;
        }
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: "babad"
    cout << "Test Case 1:" << endl;
    string s1 = "babad";
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Longest Palindromic Substring: \"" << s.longestPalindrome(s1) << "\"" << endl;
    cout << "Expected: \"bab\" or \"aba\"" << endl;
    cout << endl;

    // LeetCode default test case 2: "cbbd"
    cout << "Test Case 2:" << endl;
    string s2 = "cbbd";
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Longest Palindromic Substring: \"" << s.longestPalindrome(s2) << "\"" << endl;
    cout << "Expected: \"bb\"" << endl;
    cout << endl;

    // Custom test case 3: "a"
    cout << "Test Case 3:" << endl;
    string s3 = "a";
    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Longest Palindromic Substring: \"" << s.longestPalindrome(s3) << "\"" << endl;
    cout << "Expected: \"a\"" << endl;
    cout << endl;

    return 0;
}
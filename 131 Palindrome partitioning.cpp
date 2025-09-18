#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        dfs(result, 0, path, s);
        return result;
    }
private:
    void dfs(vector<vector<string>> &result, int index, vector<string> &path, const string &s) {
        if (index == s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            // Check if the substring from index to i is a palindrome
            if (isPalindrome(s, index, i)) {
                string sub = s.substr(index, i - index + 1);
                path.push_back(sub);
                dfs(result, i + 1, path, s);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

// Helper function to print the result
void printResult(const string& input, const vector<vector<string>>& result) {
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Result partitions:" << endl;
    for (const auto& partition : result) {
        cout << "[";
        for (size_t i = 0; i < partition.size(); ++i) {
            cout << "\"" << partition[i] << "\"" << (i == partition.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
    cout << "--------------------" << endl;
}

int main() {
    Solution solution;

    // Test case 1 from LeetCode
    string s1 = "aab";
    printResult(s1, solution.partition(s1)); // Expected: [["a", "a", "b"], ["aa", "b"]]

    // Test case 2 from LeetCode
    string s2 = "a";
    printResult(s2, solution.partition(s2)); // Expected: [["a"]]
    
    // Test case 3
    string s3 = "efe";
    printResult(s3, solution.partition(s3)); // Expected: [["e", "f", "e"], ["efe"]]
    
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> samegroup;
        for (const string& word : strs) {
            string s = word;
            sort(s.begin(), s.end());
            samegroup[s].push_back(word);
        }
        for (auto& w : samegroup) {
            result.push_back(w.second);
        }
        return result;
    }
};

// Helper function to print a vector of vectors of strings
void printResult(const vector<vector<string>>& result) {
    cout << "[" << endl;
    for (const auto& group : result) {
        cout << "  [";
        for (size_t i = 0; i < group.size(); ++i) {
            cout << "\"" << group[i] << "\"" << (i == group.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution s;

    // LeetCode default test case 1: strs = ["eat","tea","tan","ate","nat","bat"]
    cout << "Test Case 1:" << endl;
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    cout << "Input: [\"eat\", \"tea\", \"tan\", \"ate\", \"nat\", \"bat\"]" << endl;
    vector<vector<string>> result1 = s.groupAnagrams(strs1);
    cout << "Output (order of groups and strings may vary):" << endl;
    printResult(result1);
    cout << "Expected Output (one possible order): [[\"bat\"],[\"nat\",\"tan\"],[\"ate\",\"eat\",\"tea\"]]" << endl;
    cout << endl;

    // LeetCode default test case 2: strs = [""]
    cout << "Test Case 2:" << endl;
    vector<string> strs2 = {""};
    cout << "Input: [\"\"]" << endl;
    vector<vector<string>> result2 = s.groupAnagrams(strs2);
    cout << "Output:" << endl;
    printResult(result2);
    cout << "Expected Output: [[\"\"]]" << endl;
    cout << endl;

    // LeetCode default test case 3: strs = ["a"]
    cout << "Test Case 3:" << endl;
    vector<string> strs3 = {"a"};
    cout << "Input: [\"a\"]" << endl;
    vector<vector<string>> result3 = s.groupAnagrams(strs3);
    cout << "Output:" << endl;
    printResult(result3);
    cout << "Expected Output: [[\"a\"]]" << endl;
    cout << endl;

    return 0;
}
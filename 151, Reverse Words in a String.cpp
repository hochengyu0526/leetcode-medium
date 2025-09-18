#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string result = "";
        
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        
        if (words.empty()) {
            return "";
        }
        
        for (int i = words.size() - 1; i > 0; --i) {
            result += words[i] + " ";
        }
        result += words[0];
        
        return result;
    }
};

void printResult(const string& input, const string& output) {
    cout << "Input string: \"" << input << "\"" << endl;
    cout << "Reversed string: \"" << output << "\"" << endl;
    cout << "--------------------" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    string s1 = "the sky is blue";
    printResult(s1, solution.reverseWords(s1)); // Expected: "blue is sky the"
    
    // Test case 2 from LeetCode
    string s2 = "  hello world  ";
    printResult(s2, solution.reverseWords(s2)); // Expected: "world hello"

    // Test case 3 from LeetCode
    string s3 = "a good   example";
    printResult(s3, solution.reverseWords(s3)); // Expected: "example good a"

    // Test case 4
    string s4 = "singleword";
    printResult(s4, solution.reverseWords(s4)); // Expected: "singleword"
    
    return 0;
}
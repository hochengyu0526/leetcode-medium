#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;
        while(getline(ss, token, '/')){
            if(token == "" || token == ".") {
                continue;
            }
            if(token == ".."){
                if(!stack.empty()){
                    stack.pop_back();
                }
            } else {
                stack.push_back(token);
            }
        }
        string result = "";
        for(size_t i = 0; i < stack.size(); ++i){
            result += "/" + stack[i];
        }
        if (result.empty()) {
            return "/";
        }
        return result;
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: path = "/home/"
    string path1 = "/home/";
    cout << "Test Case 1:" << endl;
    cout << "Input: \"" << path1 << "\"" << endl;
    cout << "Output: \"" << s.simplifyPath(path1) << "\"" << endl;
    cout << "Expected: \"/home\"" << endl;
    cout << endl;

    // LeetCode default test case 2: path = "/../"
    string path2 = "/../";
    cout << "Test Case 2:" << endl;
    cout << "Input: \"" << path2 << "\"" << endl;
    cout << "Output: \"" << s.simplifyPath(path2) << "\"" << endl;
    cout << "Expected: \"/\"" << endl;
    cout << endl;
    
    // LeetCode default test case 3: path = "/home//foo/"
    string path3 = "/home//foo/";
    cout << "Test Case 3:" << endl;
    cout << "Input: \"" << path3 << "\"" << endl;
    cout << "Output: \"" << s.simplifyPath(path3) << "\"" << endl;
    cout << "Expected: \"/home/foo\"" << endl;
    cout << endl;

    // Custom test case 4: path = "/a/./b/../../c/"
    string path4 = "/a/./b/../../c/";
    cout << "Test Case 4:" << endl;
    cout << "Input: \"" << path4 << "\"" << endl;
    cout << "Output: \"" << s.simplifyPath(path4) << "\"" << endl;
    cout << "Expected: \"/c\"" << endl;
    cout << endl;

    return 0;
}
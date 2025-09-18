#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==1)return stoi(tokens[0]);
        vector<long long> v; // Use long long to avoid potential overflow during intermediate calculations
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                long long end=v.back();
                v.pop_back();
                long long start=v.back();
                v.pop_back();
                v.push_back(start+end);
            }
            else if(tokens[i]=="-"){
                long long end=v.back();
                v.pop_back();
                long long start=v.back();
                v.pop_back();
                v.push_back(start-end);
            }
            else if(tokens[i]=="*"){
                long long end=v.back();
                v.pop_back();
                long long start=v.back();
                v.pop_back();
                v.push_back(start*end);
            }
            else if(tokens[i]=="/"){
                long long end=v.back();
                v.pop_back();
                long long start=v.back();
                v.pop_back();
                v.push_back(start/end);
            }
            else{
                v.push_back(stoi(tokens[i]));
            }
        }
        return v[0];
    }
};

void printResult(const string& testCase, int result) {
    cout << "Test Case: " << testCase << endl;
    cout << "Result: " << result << endl;
    cout << "--------------------" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    printResult("tokens1 = {\"2\", \"1\", \"+\", \"3\", \"*\"}", solution.evalRPN(tokens1)); // Expected: 9
    
    // Test case 2 from LeetCode
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    printResult("tokens2 = {\"4\", \"13\", \"5\", \"/\", \"+\"}", solution.evalRPN(tokens2)); // Expected: 6
    
    // Test case 3 from LeetCode
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    printResult("tokens3 = {\"10\", \"6\", \"9\", \"3\", \"+\", \"-11\", \"*\", \"/\", \"*\", \"17\", \"+\", \"5\", \"+\"}", solution.evalRPN(tokens3)); // Expected: 22
    
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>result;
        vector<string>segment;
        backtrack(result,segment,0,s);
        return result;
    }
private:
    void backtrack(vector<string>&result,vector<string>segment,int start,const string &s){
        if(segment.size()==4){
            if(start==s.size()){
                result.push_back(join(segment));
            }
            return;
        }
        for(int len=1;len<=3;len++){
            if(start+len>s.size())break;
            string seg=s.substr(start, len);
            if(isok(seg)){
                segment.push_back(seg);
                backtrack(result,segment,start+len,s);
                segment.pop_back();
            }
        }
    }
    string join(const vector<string> &segment) {
        return segment[0] + "." + segment[1] + "." + segment[2] + "." + segment[3];
    }
    bool isok(const string &seg){
        if(seg.size()>1&&seg[0]=='0')return false;
        if(seg.empty()) return false;
        try {
            int n=stoi(seg);
            return n>=0&&n<=255;
        } catch (const std::out_of_range& oor) {
            return false;
        }
    }
};

void printResult(const string& input, const vector<string>& result) {
    cout << "Input string: \"" << input << "\"" << endl;
    cout << "Restored IP addresses:" << endl;
    for (const auto& ip : result) {
        cout << ip << endl;
    }
    cout << "--------------------" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    string s1 = "25525511135";
    printResult(s1, solution.restoreIpAddresses(s1)); // Expected: {"255.255.11.135", "255.255.111.35"}

    // Test case 2 from LeetCode
    string s2 = "0000";
    printResult(s2, solution.restoreIpAddresses(s2)); // Expected: {"0.0.0.0"}

    // Test case 3 from LeetCode
    string s3 = "101023";
    printResult(s3, solution.restoreIpAddresses(s3)); // Expected: {"10.10.2.3", "10.10.23.0", "10.102.3.0", "101.0.2.3", "1.0.10.23"}

    return 0;
}
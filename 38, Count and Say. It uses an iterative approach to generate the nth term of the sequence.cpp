#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        
        string result = "1";
        for (int i = 1; i < n; ++i) {
            string tmp = "";
            int count = 1;
            for (size_t j = 0; j < result.size(); ++j) {
                if (j + 1 < result.size() && result[j] == result[j+1]) {
                    count++;
                } else {
                    tmp += to_string(count);
                    tmp += result[j];
                    count = 1;
                }
            }
            result = tmp;
        }
        return result;
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: n = 1
    int n1 = 1;
    cout << "Test Case 1:" << endl;
    cout << "n = " << n1 << endl;
    cout << "Result: \"" << s.countAndSay(n1) << "\"" << endl;
    cout << "Expected: \"1\"" << endl;
    cout << endl;

    // LeetCode default test case 2: n = 4
    int n2 = 4;
    cout << "Test Case 2:" << endl;
    cout << "n = " << n2 << endl;
    cout << "Result: \"" << s.countAndSay(n2) << "\"" << endl;
    cout << "Expected: \"1211\"" << endl;
    cout << endl;

    // Custom test case 3: n = 6
    int n3 = 6;
    cout << "Test Case 3:" << endl;
    cout << "n = " << n3 << endl;
    cout << "Result: \"" << s.countAndSay(n3) << "\"" << endl;
    cout << "Expected: \"312211\"" << endl;
    cout << endl;

    return 0;
}
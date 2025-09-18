#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int m = num1.size();
        int n = num2.size();
        vector<int> result(m + n, 0);

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        string final_result = "";
        int i = 0;
        while (i < result.size() - 1 && result[i] == 0) {
            i++;
        }

        while (i < result.size()) {
            final_result += to_string(result[i]);
            i++;
        }

        return final_result;
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: num1 = "2", num2 = "3"
    string num1_1 = "2";
    string num2_1 = "3";
    cout << "Test Case 1:" << endl;
    cout << "num1 = \"" << num1_1 << "\", num2 = \"" << num2_1 << "\"" << endl;
    cout << "Result: " << s.multiply(num1_1, num2_1) << endl;
    cout << "Expected: \"6\"" << endl;
    cout << endl;

    // LeetCode default test case 2: num1 = "123", num2 = "456"
    string num1_2 = "123";
    string num2_2 = "456";
    cout << "Test Case 2:" << endl;
    cout << "num1 = \"" << num1_2 << "\", num2 = \"" << num2_2 << "\"" << endl;
    cout << "Result: " << s.multiply(num1_2, num2_2) << endl;
    cout << "Expected: \"56088\"" << endl;
    cout << endl;
    
    // Custom test case 3: num1 = "999", num2 = "999"
    string num1_3 = "999";
    string num2_3 = "999";
    cout << "Test Case 3:" << endl;
    cout << "num1 = \"" << num1_3 << "\", num2 = \"" << num2_3 << "\"" << endl;
    cout << "Result: " << s.multiply(num1_3, num2_3) << endl;
    cout << "Expected: \"998001\"" << endl;
    cout << endl;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int current1 = 0, current2 = 0;
        int n1 = version1.size(), n2 = version2.size();
        bool flag1 = false, flag2 = false;
        
        while(current1 < n1 || current2 < n2) {
            int num1, num2;
            
            if(flag1) num1 = 0;
            else {
                size_t pos1 = version1.find('.', current1);
                if(pos1 == string::npos) {
                    num1 = stoi(version1.substr(current1, n1 - current1));
                    current1 = n1;
                    flag1 = true;
                } else {
                    num1 = stoi(version1.substr(current1, pos1 - current1));
                    current1 = pos1 + 1;
                }
            }
            
            if(flag2) num2 = 0;
            else {
                size_t pos2 = version2.find('.', current2);
                if(pos2 == string::npos) {
                    num2 = stoi(version2.substr(current2, n2 - current2));
                    current2 = n2;
                    flag2 = true;
                } else {
                    num2 = stoi(version2.substr(current2, pos2 - current2));
                    current2 = pos2 + 1;
                }
            }
            
            if(num1 > num2) return 1;
            if(num1 < num2) return -1;
        }
        
        return 0;
    }
};

int main() {
    string v1, v2;
    cout << "Enter version1: ";
    cin >> v1;
    cout << "Enter version2: ";
    cin >> v2;
    
    Solution sol;
    int result = sol.compareVersion(v1, v2);
    
    if(result == 1) cout << v1 << " > " << v2 << endl;
    else if(result == -1) cout << v1 << " < " << v2 << endl;
    else cout << v1 << " == " << v2 << endl;
    
    return 0;
}

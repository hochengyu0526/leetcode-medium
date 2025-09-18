#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> m;
        int mx=0;
        int left=0,right=0;
        for(int i=0;i<fruits.size();i++){
            m[fruits[i]]++;
            if(i==0){
                mx++;
                right++;
                continue;
            }
            right++;
            while(m.size()>2){
                m[fruits[left]]--;
                if(m[fruits[left]]==0)m.erase(fruits[left]);
                left++;
            }
            mx=max(mx,right-left);
        }
        return mx;
    }
};

int main() {
    Solution solution;
    
    // Test case 1 from LeetCode
    vector<int> fruits1 = {1, 2, 1};
    cout << "Test Case 1: " << solution.totalFruit(fruits1) << endl; // Expected output: 3
    
    // Test case 2 from LeetCode
    vector<int> fruits2 = {0, 1, 2, 2};
    cout << "Test Case 2: " << solution.totalFruit(fruits2) << endl; // Expected output: 3
    
    // Test case 3 from LeetCode
    vector<int> fruits3 = {1, 2, 3, 2, 2};
    cout << "Test Case 3: " << solution.totalFruit(fruits3) << endl; // Expected output: 4

    return 0;
}
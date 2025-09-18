#include <iostream>

using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd_x,odd_y,even_x,even_y;
        odd_x=(n%2==0)?n/2:(n+1)/2;
        odd_y=(m%2==0)?m/2:(m+1)/2;
        even_x=n/2;
        even_y=m/2;
        long long result=odd_x*even_y+odd_y*even_x;
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: n = 3, m = 2
    int n1 = 3, m1 = 2;
    cout << "Test Case 1: n = " << n1 << ", m = " << m1 << endl;
    cout << "Result: " << solution.flowerGame(n1, m1) << endl; // Expected output: 3
    
    // Test Case 2: n = 1, m = 1
    int n2 = 1, m2 = 1;
    cout << "Test Case 2: n = " << n2 << ", m = " << m2 << endl;
    cout << "Result: " << solution.flowerGame(n2, m2) << endl; // Expected output: 0
    
    // Additional Test Case
    int n3 = 4, m3 = 5;
    cout << "Test Case 3: n = " << n3 << ", m = " << m3 << endl;
    cout << "Result: " << solution.flowerGame(n3, m3) << endl; // Expected output: 10

    return 0;
}
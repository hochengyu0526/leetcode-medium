#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> valcount;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int i : nums2) {
            valcount[i]++;
        }
    }
    
    void add(int index, int val) {
        int tmp = nums2[index];
        valcount[tmp]--;
        nums2[index] += val;
        valcount[nums2[index]]++;
        return;
    }
    
    int count(int tot) {
        int c = 0;
        for(int i : nums1) {
            int t = tot - i;
            if (valcount.count(t)) {
                c += valcount[t];
            }
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

int main() {
    // Test Case from LeetCode
    vector<int> nums1 = {1, 1, 2, 2, 2, 3};
    vector<int> nums2 = {1, 4, 5, 2, 5, 4};
    FindSumPairs* obj = new FindSumPairs(nums1, nums2);

    cout << "Initial count for total 7: " << obj->count(7) << endl; // Expected: 8
    
    obj->add(3, 2); // nums2 becomes [1, 4, 5, 4, 5, 4]
    cout << "After add(3, 2), count for total 8: " << obj->count(8) << endl; // Expected: 2
    
    cout << "After add(3, 2), count for total 4: " << obj->count(4) << endl; // Expected: 1
    
    obj->add(2, 1); // nums2 becomes [1, 4, 6, 4, 5, 4]
    cout << "After add(2, 1), count for total 9: " << obj->count(9) << endl; // Expected: 2
    
    return 0;
}
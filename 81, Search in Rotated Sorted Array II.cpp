#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        
        while(left <= right){
            mid = left + (right - left) / 2; // Avoids potential integer overflow
            if(nums[mid] == target) return true;
            
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++;
                right--;
            }
            else if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;

    // LeetCode default test case 1: nums = [2,5,6,0,0,1,2], target = 0
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    cout << "Nums: [2,5,6,0,0,1,2], Target: 0" << endl;
    cout << "Result: " << (s.search(nums1, target1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;

    // LeetCode default test case 2: nums = [2,5,6,0,0,1,2], target = 3
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;
    cout << "Nums: [2,5,6,0,0,1,2], Target: 3" << endl;
    cout << "Result: " << (s.search(nums2, target2) ? "true" : "false") << endl;
    cout << "Expected: false" << endl;
    cout << endl;

    // Custom test case 3: nums = [1,0,1,1,1], target = 0
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {1, 0, 1, 1, 1};
    int target3 = 0;
    cout << "Nums: [1,0,1,1,1], Target: 0" << endl;
    cout << "Result: " << (s.search(nums3, target3) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;

    // Custom test case 4: nums = [1,1,3,1], target = 3
    cout << "Test Case 4:" << endl;
    vector<int> nums4 = {1, 1, 3, 1};
    int target4 = 3;
    cout << "Nums: [1,1,3,1], Target: 3" << endl;
    cout << "Result: " << (s.search(nums4, target4) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << endl;

    return 0;
}
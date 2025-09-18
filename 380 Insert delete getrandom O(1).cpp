#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

class RandomizedSet {
private:
    // unordered_map 用來快速檢查元素是否存在，並儲存其在 vector 中的索引
    unordered_map<int, int> val_to_index;
    // vector 用來儲存所有元素，方便O(1)時間隨機存取
    vector<int> nums;

public:
    RandomizedSet() {
        // 不需要任何額外操作，成員變數會自動初始化
        srand(time(0)); // 初始化隨機數生成器
    }
    
    bool insert(int val) {
        if (val_to_index.count(val)) {
            return false;
        }
        nums.push_back(val);
        val_to_index[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!val_to_index.count(val)) {
            return false;
        }
        
        int index_to_remove = val_to_index[val];
        int last_val = nums.back();

        // 將要刪除的元素與最後一個元素交換位置
        nums[index_to_remove] = last_val;
        val_to_index[last_val] = index_to_remove;

        // 刪除最後一個元素
        nums.pop_back();
        val_to_index.erase(val);

        return true;
    }
    
    int getRandom() {
        int random_index = rand() % nums.size();
        return nums[random_index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    cout << "Testing RandomizedSet..." << endl;
    RandomizedSet* obj = new RandomizedSet();

    // Test case from LeetCode
    cout << "insert(1): " << (obj->insert(1) ? "true" : "false") << endl;    // returns true
    cout << "remove(2): " << (obj->remove(2) ? "true" : "false") << endl;    // returns false
    cout << "insert(2): " << (obj->insert(2) ? "true" : "false") << endl;    // returns true

    cout << "getRandom(): " << obj->getRandom() << endl;                      // returns 1 or 2
    cout << "getRandom(): " << obj->getRandom() << endl;                      // returns 1 or 2

    cout << "remove(1): " << (obj->remove(1) ? "true" : "false") << endl;    // returns true
    cout << "insert(2): " << (obj->insert(2) ? "true" : "false") << endl;    // returns false

    cout << "getRandom(): " << obj->getRandom() << endl;                      // returns 2
    cout << "getRandom(): " << obj->getRandom() << endl;                      // returns 2

    return 0;
}
#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class MinStack {
private:
    stack<int> s; // The main stack to store all elements
    stack<int> min_stack; // The auxiliary stack to store minimums
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        // Push the new value onto min_stack if it's the new minimum.
        // Or if min_stack is empty.
        // Note: Pushing the current minimum again handles duplicates and ensures
        // the top of min_stack always corresponds to the minimum of the main stack.
        if (min_stack.empty() || val <= min_stack.top()) {
            min_stack.push(val);
        }
    }
    
    void pop() {
        if (s.empty()) {
            return;
        }
        // If the element being popped from the main stack is the current minimum,
        // pop it from the min_stack as well.
        if (s.top() == min_stack.top()) {
            min_stack.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    cout << "Testing MinStack..." << endl;
    MinStack minStack;

    // Test Case 1 from LeetCode
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    cout << "After pushing -2, 0, -3:" << endl;
    cout << "getMin() should be -3. Result: " << minStack.getMin() << endl; // returns -3
    
    minStack.pop();
    cout << "After popping top element:" << endl;
    cout << "top() should be 0. Result: " << minStack.top() << endl; // returns 0
    
    cout << "getMin() should be -2. Result: " << minStack.getMin() << endl; // returns -2
    cout << "--------------------" << endl;

    // Additional test case to check duplicates and order
    MinStack minStack2;
    minStack2.push(5);
    minStack2.push(4);
    minStack2.push(4);
    minStack2.push(3);
    
    cout << "Testing with duplicates..." << endl;
    cout << "getMin() should be 3. Result: " << minStack2.getMin() << endl; // returns 3
    minStack2.pop(); // pop 3
    cout << "After popping 3, getMin() should be 4. Result: " << minStack2.getMin() << endl; // returns 4
    minStack2.pop(); // pop 4
    cout << "After popping 4, getMin() should be 4. Result: " << minStack2.getMin() << endl; // returns 4
    
    return 0;
}
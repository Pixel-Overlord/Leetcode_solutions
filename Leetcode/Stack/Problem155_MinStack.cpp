/* 
 * 155. Min Stack
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * 
 * Implement the MinStack class:
 * 
 * MinStack() initializes the stack object.
 * void push(int value) pushes the element value onto the stack.
 * void pop() removes the element on the top of the stack.
 * int top() gets the top element of the stack.
 * int getMin() retrieves the minimum element in the stack.
 * You must implement a solution with O(1) time complexity for each function.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * 
 * Output
 * [null,null,null,null,-3,null,0,-2]
 * 
 * Explanation
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin(); // return -3
 * minStack.pop();
 * minStack.top();    // return 0
 * minStack.getMin(); // return -2
 */

 #include <iostream>
 #include <vector>
 #include <stack>
 using namespace std;

 class MinStack {
 public:
     stack<pair<int, int>> s; // stack of val and min value;

     MinStack() {
         
     }
     
     void push(int value) {
         // we will push val and minimum value in the vector.

         if (s.empty()) {
            s.push({value, value});
         }
         else {
            int minValue = min(value, s.top().second);
            s.push({value, minValue});
         }
     }
     
     void pop() {
         s.pop();
     }
     
     int top() {
         return s.top().first;
     }
     
     int getMin() {
         return s.top().second;
     }
 };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 int main() {
    MinStack* obj = new MinStack();
    // int value = 5;
    obj->push(-1);
    obj->push(0);
    obj->push(-3);
    obj->push(4);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();

    cout << "top : " << param_3;
    cout << "Min in stack is : " << param_4;
 }
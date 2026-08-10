/*
Problem: Implement stack using array
Link: https://www.geeksforgeeks.org/problems/implement-stack-using-array/1
Difficulty: Easy
Approach: Arrays
Time Complexity: 
    - isEmpty(): O(1)
    - isFull(): O(1)
    - push(): O(1)
    - pop(): O(1)
    - peek(): O(1)
Space Complexity: O(n)
Note:
    
*/

class myStack {
    vector<int> stack;
    int n;
public:
    
    myStack(int n) {
        this->n = n;
    }

    bool isEmpty() {
        return stack.size() == 0;
    }

    bool isFull() {
        return stack.size() == n;
    }

    void push(int x) {
        if (stack.size() + 1 <= n)
            stack.emplace_back(x);
    }

    void pop() {
        if (stack.size() > 0)
            stack.pop_back();
    }

    int peek() {
        return (stack.size() > 0) ? stack.back() : -1;
    }
};
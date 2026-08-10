/*
Problem: 232. Implement Queue using Stacks
Link: https://leetcode.com/problems/implement-queue-using-stacks/description/
Difficulty: Easy
Approach: Stacks
Time Complexity: 
    - push(): O(n)
    - pop(): O(1)
    - peek(): O(1)
    - empty(): O(1)
Note:
    
*/

class MyQueue {
    stack<int> in, out;
public:
    MyQueue() {}
    
    void push(int x) {
        in.emplace(x);
    }
    
    int pop() {
        if (out.empty()){
            while (!in.empty()){
                out.emplace(in.top());
                in.pop();
            }
        }

        if (out.empty())
            return 0;

        int ans = out.top();
        out.pop();
        return ans;
    }
    
    int peek() {
        if (out.empty()){
            while (!in.empty()){
                out.emplace(in.top());
                in.pop();
            }
        }

        if (out.empty())
            return 0;
            
        return out.top();
    }
    
    bool empty() {
        return out.empty() && in.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
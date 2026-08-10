/*
Problem: 155. Min Stack
Link: https://leetcode.com/problems/min-stack/description/
Difficulty: Medium
Approach: Stacks
Time Complexity: 
    - push(): O(1)
    - pop(): O(1)
    - top(): O(1)
    - getMin(): O(1)
Note:
    
*/

class MinStack {
    stack<pair<int, int>> st;
public:
    MinStack() {}
    
    void push(int value) {
        if (st.empty()){
            st.push({value, value});
            return;
        }

        int currMin = st.top().second;
        if (value < currMin)
            st.push({value, value});
        else
            st.push({value, st.top().second});
    }
    
    void pop() {
        if (!st.empty())
            st.pop();
    }
    
    int top() {
        if (!st.empty())
            return st.top().first;
        
        return 0;
    }
    
    int getMin() {
        if (!st.empty())
            return st.top().second;
        
        return 0;
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
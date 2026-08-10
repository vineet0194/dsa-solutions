/*
Problem: 225. Implement Stack using Queues
Link: https://leetcode.com/problems/implement-stack-using-queues/description/
Difficulty: Easy
Approach: Queues
Time Complexity: 
    - push(): O(n)
    - pop(): O(1)
    - top(): O(1)
    - empty(): O(1)
Note:
    
*/

class MyStack {
    queue<int> main, temp;
public:
    MyStack() {}
    
    void push(int x) {
        while (!main.empty()){
            temp.emplace(main.front());
            main.pop();
        }

        main.emplace(x);
        
        while (!temp.empty()){
            main.emplace(temp.front());
            temp.pop();
        }

    }
    
    int pop() {
        if (main.empty())
            return 0;
        
        int ans = main.front();
        main.pop();

        return ans;
    }
    
    int top() {
        if (main.empty())
            return 0;

        return main.front();
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


// ! FOLLOW UP: use only 1 stack    ---     push it back into the same queue

class MyStack {
    queue<int> main;
public:
    MyStack() {}
    
    void push(int x) {
        int n = main.size();    // size before pushing (elements before x)
        main.push(x);

        if (main.size() == 0)
            return;

        for (int i=0; i<n; i++){
            main.emplace(main.front());
            main.pop();
        }
    }
    
    int pop() {
        if (main.empty())
            return 0;
        
        int ans = main.front();
        main.pop();

        return ans;
    }
    
    int top() {
        if (main.empty())
            return 0;

        return main.front();
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
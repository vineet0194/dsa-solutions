/*
Problem: Queue Using Array
Link: https://www.geeksforgeeks.org/problems/implement-queue-using-array/1
Difficulty: Easy
Approach: Arrays
Time Complexity:
    - isEmpty(): O(1)
    - isFull(): O(1)
    - enqueue(): O(1)
    - dequeue(): O(n)
    - getFront(): O(1)
    - getRear(): O(1) 
Note:
    
*/

class myQueue {
    vector<int> queue;
    int n;
public:
    myQueue(int n) {
        this->n = n;
    }

    bool isEmpty() {
        return queue.size() == 0;
    }

    bool isFull() {
        return queue.size() == n;
    }

    void enqueue(int x) {
        if (queue.size() + 1 <= n)
            queue.emplace_back(x);
    }

    void dequeue() {
        int temp = queue.back();
        
        for (int i=0; i<queue.size()-1; i++)
            queue[i] = queue[i+1];
        
        queue.pop_back();
    }

    int getFront() {
        return (queue.size() > 0) ? queue[0] : -1;
    }

    int getRear() {
        return (queue.size() > 0) ? queue[queue.size()-1] : -1;
    }
};
/*
Problem: 295. Find Median from Data Stream
Link: https://leetcode.com/problems/find-median-from-data-stream/description/
Difficulty: Hard
Approach: Heaps
Time Complexity:
    - addNum(): O(log n)
    - findMedian(): O(1)
Note:
    
*/

class MedianFinder {
public:
    priority_queue<double> left;
    priority_queue<double, vector<double>, greater<double>> right;

    MedianFinder() {}
    
    void addNum(int num) {
        if (left.empty() || num < left.top())
            left.emplace(num);
        else
            right.emplace(num);
        
        // maintain that either
        // (left) = (right) or (left) = (right)+1

        while (left.size() > right.size()+1){
            right.emplace(left.top());
            left.pop();
        }

        while (right.size() > left.size()){
            left.emplace(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.size() == right.size())
            return (left.top() + right.top())/2;
        
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
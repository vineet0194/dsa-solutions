/*
Problem: Min Cost to Connect Ropes
Link: https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
Difficulty: Medium
Approach: Heaps
Time Complexity: O(N*logN)
Note:
    
*/

class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto& num: arr)
            pq.push(num);
        
        int cost = 0;
        
        while (pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            cost += a+b;
            pq.push(a+b);
        }
        
        return cost;
    }
};
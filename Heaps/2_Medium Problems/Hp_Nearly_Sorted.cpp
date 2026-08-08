/*
Problem: Nearly sorted / Sort a k-sorted array
Link: https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1
Difficulty: Medium
Approach: Min Heap
Time Complexity: O(nlogk)
Note:
    
*/

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i=0;
        for (auto& num: arr){
            if (pq.size() < k+1)
                pq.emplace(num);
            else{
                arr[i++] = pq.top();
                pq.pop();
                pq.push(num);
            }
        }
        
        while(!pq.empty()){
            arr[i++] = pq.top();
            pq.pop();
        }
    }
};
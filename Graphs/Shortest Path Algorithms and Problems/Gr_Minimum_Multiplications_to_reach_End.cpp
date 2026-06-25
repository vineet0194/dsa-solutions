/*
Problem: Minimum Multiplications to reach End
Link: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
Difficulty: Medium
Approach: BFS
Time Complexity: O(VE) => O(1000*N) => O(N)
Note:
    
*/

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        if (start == end)
            return 0;
        
        queue<pair<int, int>> q;
        q.push({0, start});
        
        vector<int> dist(1000, INT_MAX);
        dist[start] = 0;
        
        while (!q.empty()){
            int currOps = q.front().first;
            int curr = q.front().second;
            q.pop();
            if (curr == end)
                return currOps;
            for (auto& elem : arr){
                int nextVal = (curr*elem)%1000;
                if (dist[nextVal] > currOps+1){
                    q.push({currOps+1, nextVal});
                    dist[nextVal] = currOps+1;
                }
            }
        }
        
        return -1;
    }
};
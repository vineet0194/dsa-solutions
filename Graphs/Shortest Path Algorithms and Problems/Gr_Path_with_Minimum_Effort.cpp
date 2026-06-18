/*
Problem: https://leetcode.com/problems/path-with-minimum-effort/description/
Link: 1631. Path With Minimum Effort
Difficulty: Medium
Approach: Dijkstra
Time Complexity: O(m*n*log(m*n))
Note:
    newEff = max (abs diff between next and curr, maxeff seen till now in path)
    if this newEff < maxEff in reaching neigh (dist[neigh])
    then update dist[neigh] = newEff

    but if i dont use minEff, what if i reach last node using some value lets say x and another path which i later use uses val x-1?
    
    That's exactly the question Dijkstra's correctness answers.
    The reason you can return immediately when you pop the destination is that the priority queue always pops the
    node with the smallest effort currently known, and for this problem the effort metric satisfies Dijkstra's requirements.
*/

class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        return true;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        pq.push({0, {0,0}});
        dist[0][0] = 0;

        int minEff = INT_MAX;        // minEff of all the paths

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        while (!pq.empty()){
            // this is u
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            int maxEff = pq.top().first;   // maxEff in path
            pq.pop();
            if (i == m-1 && j == n-1)
                return maxEff;
            for (int k=0; k<4; k++){
                int nextI = i+dr[k];
                int nextJ = j+dc[k];
                if (isValid(nextI, nextJ, m, n)){
                    // newEff = max (abs diff between next and curr, maxeff seen till now in path)
                    // if this newEff < maxEff in reaching neigh (dist[neigh])
                    // then update dist[neigh] = newEff
                    int newEff = max(abs(heights[nextI][nextJ]-heights[i][j]), maxEff);
                    if (newEff < dist[nextI][nextJ]){
                        dist[nextI][nextJ] = newEff;
                        pq.push({newEff, {nextI, nextJ}});
                    }
                }
            
            }
        }
        return -1;
    }
};
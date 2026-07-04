/*
Problem: 2492. Minimum Score of a Path Between Two Cities
Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/?envType=daily-question&envId=2026-07-04
Difficulty: Medium
Approach: BFS with PQ (Modified Dijkstra)
Time Complexity: O(E log V)
Note:
    
*/

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> neighbours(n+1);

        for (auto& road : roads){
            int u = road[0], v = road[1], w = road[2];
            neighbours[u].push_back({v, w});
            neighbours[v].push_back({u, w});
        }

        vector<bool> visited(n+1, false);

        vector<int> edgeWt(n+1, INT_MAX);   // min edgeWt to reach i

        // {minWt encountered till curr, curr}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({INT_MAX, 1});

        int mini = INT_MAX;
        while (!pq.empty()){
            int minWt = pq.top().first;     // minWt encountered in reaching u
            int u = pq.top().second;
            pq.pop();

            if (minWt > edgeWt[u])
                continue;

            if (minWt < mini)
                mini = minWt;

            for (auto& neigh: neighbours[u]){
                int v = neigh.first;
                int wt = neigh.second;
                int miniTemp = min(minWt, wt);
                if (visited[v]==0 || miniTemp < edgeWt[v]){
                    visited[v] = 1;
                    edgeWt[v] = miniTemp;
                    pq.push({miniTemp, v});
                }
            }
        }

        return mini;
    }
};
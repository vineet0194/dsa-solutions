/*
Problem: 743. Network Delay Time
Link: https://leetcode.com/problems/network-delay-time/
Difficulty: Medium
Approach: Queue based relaxation (BFS)      ,       optimal approach -> Topological Sorting
Time Complexity: O(VE)
Note:
    I used a queue based relaxation system similar to bfs but not exactly

    ! scroll down for optimal solution
*/

class Solution {
public:
    void queueRelaxation(int src, vector<vector<pair<int, int>>>& neighbours, vector<int>& delayTime){
        queue<pair<int, int>> q;
        
        q.push({src, 0});
        delayTime[src]=0;

        int qsize = q.size();
        while(!q.empty()){
            qsize = q.size();
            for (int i=0; i<qsize; i++){
                int curr = q.front().first;
                int currDelay = q.front().second;
                q.pop();
                for (auto& neigh: neighbours[curr]){
                    int next = neigh.first;
                    int nextDelay = currDelay + neigh.second;
                    if (delayTime[next] == -1 || nextDelay < delayTime[next]){
                        delayTime[next] = nextDelay;
                        q.push({next, nextDelay});
                    }
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> neighbours(n+1);
        vector<int> delayTime(n+1, -1);

        for (auto& edge : times){
            neighbours[edge[0]].push_back({edge[1], edge[2]});
        }

        queueRelaxation(k, neighbours, delayTime);

        int maxTime=-1;
        for (int i=1; i<n+1; i++){
            if (delayTime[i] == -1)
                return -1;
            if (maxTime < delayTime[i])
                maxTime = delayTime[i];
        }

        return maxTime;
    }
};

// ------------------------------------------------------------------------------------------------------------------ //

// OPTIMAL SOLUTION => will post when i study djikstra


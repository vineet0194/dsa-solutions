/*
Problem: Finish Time of Tasks I
Link: https://leetcode.com/contest/biweekly-contest-185/problems/finish-time-of-tasks-i/description/
Difficulty: Medium
Approach: DFS
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    void dfs(int curr, vector<vector<int>>& neighbours, vector<int>& baseTime, vector<long long>& finishTime){
        if (neighbours[curr].size()==0){
            finishTime[curr] = baseTime[curr];
            return;
        }
        long long earliest = LLONG_MAX;
        long long latest = LLONG_MIN;
        for (auto& neigh : neighbours[curr]){
            dfs(neigh, neighbours, baseTime, finishTime);
            long long childFinish = finishTime[neigh];
            earliest = min(earliest, childFinish);
            latest = max(latest, childFinish);
        }

        long long ownDuration = (latest-earliest) + baseTime[curr];
        finishTime[curr] = latest + ownDuration;

        return;
    }
    
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> neighbours(n);
        vector<long long> finishTime(n);
        for (auto& edge: edges){
            neighbours[edge[0]].push_back(edge[1]);
        }
        dfs(0, neighbours, baseTime, finishTime);

        return finishTime[0];
    }
};
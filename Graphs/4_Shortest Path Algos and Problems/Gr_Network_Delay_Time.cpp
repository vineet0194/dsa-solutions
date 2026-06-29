/*
Problem: 743. Network Delay Time
Link: https://leetcode.com/problems/network-delay-time/
Difficulty: Medium
Approach: Queue based relaxation (BFS)      ,       optimal approach -> Dijkstra
Time Complexity: O(VE)                      ,           O(V+E)
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

// OPTIMAL SOLUTION => using dijkstra

/*
why skip stale entries in the priority queue.

Since priority_queue does not support decrease-key,
we push a new (distance, node) pair whenever a shorter
path is found. This means the same node may appear
multiple times in the heap.

Example:
1 --10--> 2
1 --1-->  3
3 --1-->  2

We first push (10,2), then later discover a shorter
path through node 3 and push (2,2). When (10,2) is
eventually popped, dist[2] is already 2, so this
entry is outdated and can be ignored.

*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> neighbours(n+1);
        for (auto& time : times){
            neighbours[time[0]].push_back({time[1], time[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({maxDelay, k});
        while (!pq.empty()){
            int currDelay = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (currDelay > dist[u])            // to remove stale entries
                continue;
            for (auto& neigh : neighbours[u]){
                int v = neigh.first;
                int wt = neigh.second;
                if (dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxDelay=0;
        for (int i=1; i<n+1; i++){
            if (dist[i] == INT_MAX)
                return -1;
            if (dist[i] > maxDelay)
                maxDelay = dist[i];
        }
        return maxDelay;
    }
};
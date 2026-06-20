/*
Problem: 1976. Number of Ways to Arrive at Destination
Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
Difficulty: Medium
Approach: Dijkstra
Time Complexity: O((V+E)logV)
Note:
    if you reach a node such that the dist[v] is improving
        if improving => you copy the number of ways you reached u (ways[u]) to ways[v] and update the shortest dist
        if equal => you add already found number of ways (ways[v]), and current (ways[u]) and MOD
*/

#define ll long long

class Solution {
public:
    static const int MOD = (int) 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> neighbours(n);

        for (auto& road : roads){
            neighbours[road[0]].push_back({road[1], road[2]});
            neighbours[road[1]].push_back({road[0], road[2]});
        }

        vector<ll> dist(n, LLONG_MAX);
        dist[0] = 0;

        vector<int> ways(n, 0);
        ways[0] = 1;

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            ll currwt = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (currwt > dist[u])
                continue;
            for (auto& neigh : neighbours[u]){
                int v = neigh.first;
                int wt = neigh.second;
                if (dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                    ways[v] = ways[u];
                }
                else if (dist[v] == dist[u] + wt){
                    ways[v] = (ways[v] + ways[u])%MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};
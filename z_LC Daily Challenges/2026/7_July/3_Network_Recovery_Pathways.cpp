/*
Problem: 3620. Network Recovery Pathways
Link: https://leetcode.com/problems/network-recovery-pathways/description/?envType=daily-question&envId=2026-07-03
Difficulty: Hard
Approach: BS + BFS TopoSort
Time Complexity: O((V+E)logE)​
Note:
    
*/

class Solution {
public:
int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        
        // 1. Build adjacency list for online nodes
        vector<vector<pair<int, long long>>> adj(n);
        vector<int> indegree(n, 0);
        vector<long long> unique_costs;

        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            long long cost = e[2];
            
            // Ignore edges connected to any offline nodes
            if (online[u] && online[v]) {
                adj[u].push_back({v, cost});
                indegree[v]++;
                unique_costs.push_back(cost);
            }
        }

        // If there are no valid edges at all, no path is possible
        if (unique_costs.empty()) return -1;

        // 2. Compute Global Topological Sort using Kahn's Algorithm
        vector<int> topo;
        topo.reserve(n);
        queue<int> q;
        
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (const auto& edge : adj[u]) {
                if (--indegree[edge.first] == 0) {
                    q.push(edge.first);
                }
            }
        }

        // 3. Prepare search space of unique edge costs
        sort(unique_costs.begin(), unique_costs.end());
        unique_costs.erase(unique(unique_costs.begin(), unique_costs.end()), unique_costs.end());

        // 4. Verification lambda: Shortest path on DAG ensuring total cost <= k
        const long long INF = 1e18; 
        auto check = [&](long long mid) {
            vector<long long> dist(n, INF);
            dist[0] = 0;
            
            for (int u : topo) {
                if (dist[u] == INF) continue;
                
                for (const auto& edge : adj[u]) {
                    int v = edge.first;
                    long long cost = edge.second;
                    
                    // Only traverse edges that meet our minimum score requirement
                    if (cost >= mid) {
                        dist[v] = min(dist[v], dist[u] + cost);
                    }
                }
            }
            return dist[n - 1] <= k;
        };

        // If not even the smallest edge weight allows a valid path, fail early
        if (!check(unique_costs[0])) {
            return -1;
        }

        // 5. Binary search to find the maximum possible minimum edge
        int low = 0, high = unique_costs.size() - 1;
        int ans_idx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(unique_costs[mid])) {
                ans_idx = mid;
                low = mid + 1;  // Try to find a higher minimum score
            } else {
                high = mid - 1; // Threshold too strict, lower it
            }
        }

        return ans_idx != -1 ? static_cast<int>(unique_costs[ans_idx]) : -1;
    }
};
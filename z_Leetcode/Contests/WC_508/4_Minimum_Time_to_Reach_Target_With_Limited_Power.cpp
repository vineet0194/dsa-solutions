/*
Problem: Minimum Time to Reach Target With Limited Power
Link: https://leetcode.com/contest/weekly-contest-508/problems/minimum-time-to-reach-target-with-limited-power/
Difficulty: Medium
Approach: Modified Dijkstra
Time Complexity: 
Note:
    
*/

class Solution {
public:
    const long long INF = LLONG_MAX;

    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges,
                                      int power, vector<int>& cost,
                                      int source, int target) {

        if (source == target)
            return {0, power};

        vector<vector<pair<int,int>>> neighbours(n);

        for (auto &edge : edges) {
            neighbours[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<vector<long long>> dist(n, vector<long long>(power + 1, INF));

        using State = tuple<long long,int,int>; // time, power, node

        priority_queue<State, vector<State>, greater<State>> pq;

        dist[source][power] = 0;
        pq.push({0, power, source});

        long long bestTime = INF;
        long long bestPower = -1;

        while (!pq.empty()) {

            auto [time, remPower, u] = pq.top();
            pq.pop();

            if (time > dist[u][remPower])
                continue;

            if (time > bestTime)
                break;

            if (u == target) {
                if (time < bestTime) {
                    bestTime = time;
                    bestPower = remPower;
                } else if (time == bestTime) {
                    bestPower = max(bestPower, (long long)remPower);
                }
                continue;
            }

            if (remPower < cost[u])
                continue;

            int nextPower = remPower - cost[u];

            for (auto &[v, wt] : neighbours[u]) {

                long long newTime = time + wt;

                // Dominance check:
                // If we've already reached v with >= nextPower
                // and <= newTime, skip this state.
                bool dominated = false;
                for (int p = nextPower; p <= power; p++) {
                    if (dist[v][p] <= newTime) {
                        dominated = true;
                        break;
                    }
                }

                if (dominated)
                    continue;

                if (newTime < dist[v][nextPower]) {
                    dist[v][nextPower] = newTime;
                    pq.push({newTime, nextPower, v});
                }
            }
        }

        if (bestTime == INF)
            return {-1, -1};

        return {bestTime, bestPower};
    }
};©leetcode
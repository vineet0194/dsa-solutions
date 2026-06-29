/*
Problem: Bellman-Ford
Link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
Difficulty: Medium
Approach: DP (Bellman Ford)
Time Complexity: O(VE) or O(V^2)
Note:
    edge relax every edge for (V-1) times

    why (V-1)? because if there are v nodes from src->v (including both) then max number of edges that can be between them is v-1
    what we are basically doing in bellman-ford (and dijkstra) is checking if going through another path through 1 node could
    give use better weights, then 2 nodes then 3 and so on. at max there can be v-1 edges in between => we do relaxing for v-1 steps

    ! bellman ford does not work for negative weight "cycles" but does for negative weight "edges"
    bellamn ford guarantees that after at max v-1 iterations of the algo, distance array is final and no more iterations can reduce
    the distance but if we were to do try the updation 1 more time and the array gets updated => negative weight cycle present

    TC => O(V-1 * E) => O(VE), at worst, all nodes connected to all other nodes => E = V => TC = O(V^2)
*/

class Solution {
  public:
    bool implementBellmanFord(int V, vector<int>& dist, vector<vector<pair<int, int>>>& neighbours){
        for (int i=0; i<V-1; i++){
            bool updated = true;
            for (int u=0; u<V; u++){
                for (auto& neigh : neighbours[u]){
                    int v = neigh.first;
                    int wt = neigh.second;
                    if (dist[u]!=1e8 && dist[v] > dist[u] + wt){
                        dist[v] = dist[u] + wt;
                        updated = true;
                    }
                }
            }
            if (!updated)       // early break if no updations are done
                break;
        }
        
        for (int u=0; u<V; u++){
            for (auto& neigh : neighbours[u]){
                int v = neigh.first;
                int wt = neigh.second;
                if (dist[v]!=1e8 && dist[v] > dist[u] + wt)
                    return false;
            }
        }
        return true;
    }
  
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<vector<pair<int, int>>> neighbours(V);
        
        for (auto& edge : edges){
            neighbours[edge[0]].push_back({edge[1], edge[2]});
        }
        
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        bool valid = implementBellmanFord(V, dist, neighbours);
        
        if (!valid){
            return {-1};
        }
        
        return dist;
    }
};

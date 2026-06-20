/*
Problem: MST using Prim's Algorithm
Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
Difficulty: Medium
Approach: Greedy BFS (Prim's Alrogithm)
Time Complexity: 
Note:
    consider edges as a pair of {dist from u to v, v} and not (total weight of src->v) as we used to do earlier
*/


//  Approach 1 - to find only the cost of the MST
class Solution {
  public:
    int implementPrims(vector<vector<pair<int, int>>>& neighbours, vector<bool>& inMST){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});    // {edge wt, u}
        
        int mstCost = 0;
        
        while (!pq.empty()){
            int wt_u = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (!inMST[u]){
                inMST[u] = true;
                mstCost += wt_u;
                for (auto& neigh: neighbours[u]){
                    int v = neigh.first;
                    int wt_v = neigh.second;
                    if (!inMST[v])                  // optional but performance boost (basically not taking visited)
                        pq.push({wt_v, v});         // we dont put them in MST here, but just push into the PQ
                }                                   // so that when they are popped later => they are included in the MST
            }
        }
        
        return mstCost;
    }
  
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> neighbours(V);
        
        for (auto& edge: edges){
            neighbours[edge[0]].push_back({edge[1], edge[2]});
            neighbours[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<bool> inMST(V, false);
        
        int mstCost = implementPrims(neighbours, inMST);
        
        return mstCost;
    }
};


// Approach 2 - to find the edges included in the MST

class Solution {
  public:
    vector<vector<int>> implementPrims(vector<vector<pair<int, int>>>& neighbours, vector<bool>& inMST){
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {-1, 0}});    // {edge wt, {parent, u}}
        
        vector<vector<int>> mstEdges;
        
        while (!pq.empty()){
            int wt_u = pq.top().first;
            int parent = pq.top().second.first;
            int u = pq.top().second.second;
            pq.pop();
            if (!inMST[u]){
                inMST[u] = true;

                if (parent != -1)               // if parent = -1, edge: (-1 ---> 0), we dont want this => it is only for init
                    mstEdges.push_back({parent, u, wt_u});

                for (auto& neigh: neighbours[u]){
                    int v = neigh.first;
                    int wt_v = neigh.second;
                    if (!inMST[v])
                        pq.push({wt_v, {u, v}});
                }
            }
        }
        
        return mstEdges;
    }
  
    vector<vector<int>> spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> neighbours(V);
        
        for (auto& edge: edges){
            neighbours[edge[0]].push_back({edge[1], edge[2]});
            neighbours[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<bool> inMST(V, false);
        vector<vector<int>> mstEdges = implementPrims(neighbours, inMST);
        
        return mstEdges;
    }
};
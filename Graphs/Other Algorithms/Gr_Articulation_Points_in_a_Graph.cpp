/*
Problem: Articulation Point - I
Link: https://www.geeksforgeeks.org/problems/articulation-point-1/1
Difficulty: Hard
Approach: DFS (Tarjan's Algo)
Time Complexity: O((V+E) + (AlogA)) for DSF+Sorting => O(V+E)
                    worst case: A = V
Note:
    articulation point conditions:
        1.  if root node:
                count the number of disconnected children
                    if (disconnectedChildren > 1) => root is AP
        2. if not root node:
                check if bridge or alt path in v's subgraph to u
                in both cases => removing u causes graph to disconnect
        
    ! how do we know a child is disconnected if it is not visited? (for root condition)
        if it was connected => would have been visited by previous neighbour's DFS tree
        => current node (u) is the only point connecting the subgraph to that child
        => u is an AP
    ? root can never be AP with <= 1 child, as then it simply becomes a leaf node (disposable)
*/

class Solution {
  public:
    int time=0;
    vector<int> dt, low;
    
    void tarjan(int u, int par, vector<int> adj[], vector<bool>& visited, unordered_set<int>& ans){
        visited[u] = 1;
        dt[u] = low[u] = ++time;
        int disconnectedChildren=0;
        for (auto& v : adj[u]){
            if (visited[v]){
                if (v == par)
                    continue;
                else
                    low[u] = min(low[u], dt[v]);
            }
            else{
                disconnectedChildren++;
                tarjan(v, u, adj, visited, ans);
                low[u] = min(low[u], low[v]);
                
                if (par!=-1 && low[v] >= dt[u]){   // bridge/alt path to u
                    ans.insert(u);          // in both cases, removing u => disconnects
                }
            }
        }
        if (par==-1 && disconnectedChildren > 1)    // root node
            ans.insert(u);
    }
    
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        dt.resize(V);
        low.resize(V);
        
        unordered_set<int> ansSet;
        vector<bool> visited(V, 0);
        
        // Don't need this until disconnected graph
        // for (int i = 0; i < V; i++) {
        //     if (!visited[i])
        //         tarjan(i, -1, adj, visited, ansSet);
        // }
        
        tarjan(0, -1, adj, visited, ansSet);
        
        vector<int> ans;
        for (auto& v : ansSet){
            ans.push_back(v);
        }
        
        sort(ans.begin(), ans.end());
        
        if (ans.size()==0)
            return {-1};

        return ans;
    }
};
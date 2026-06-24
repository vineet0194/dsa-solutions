/*
Problem: 1192. Critical Connections in a Network
Link: https://leetcode.com/problems/critical-connections-in-a-network/
Difficulty: Hard
Approach: Tarjan's Algo
Time Complexity: O(E)
Note:
    for this algo, maintain a few things:
        1. a global time variable which updates before each node
        2. a dt array (tracks the first time a node is discovered)
        3. a low array (tracks the oldest ancestor current node can escape to)

    init time=0
    use DFS{
        init dt[u]=low[u] = ++time

        for all neighbours of u => v{
            if (v is not visited){
                visit v and its subgraph, it will give you the low value of v (by visitng all nodes in v's subgraph),
                low value for v => oldest ancestor you can escape to from v or from any other node in v's subgraph
                                this could possibly be through some other route or a back edge
                                ! => The oldest discovery time reachable from the entire DFS subtree rooted at v.

                low[u] = min(low[u], low[v]) => will put whatever low u get from any of the v's to low[u]
                        ! =>    Whatever escape route v found, maybe I can also use that escape route IF it is smaller than my current low

                to check if (u->v) is a bridge:
                    if (low[v] > dt[u])
                        ! BRIDGE !
                            ? this means v's entire subtree cannot reach: any ancestor of u or even u
                            ? now since v cannot escape to an ancestor occuring before u then in order to process v,
                            ? we must go through the only route available to us i.e (u->v) ==> this makes this edge a bridge
            }
            else{
                if (v is parent)
                    ignore
                if (v is not a parent){
                    => this node is already visited but it isnt a parent => we are forming a loop
                    since we are forming a loop here, def this u->v edge wont be a bridge but this
                    can indeed give us a lower ancestor value
                    => low[u] = min(low[u], dt[v])
                }
            }
        }

    }
*/

class Solution {
public:
    int time=0;
    vector<int> dt, low;
    void dfs(int u, int par, vector<vector<int>>& neighbours, vector<bool>& visited, vector<vector<int>>& ans){
        visited[u] = 1;
        dt[u] = low[u] = ++time;
        for (auto& v : neighbours[u]){
            if (!visited[v]){
                dfs(v, u, neighbours, visited, ans);
                low[u] = min(low[u], low[v]);

                if (low[v] > dt[u]){
                    ans.push_back({u, v});
                }
            }
            else if (visited[v]){
                if (v == par)
                    continue;
                else
                    low[u] = min(low[u], dt[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> neighbours(n);
        for (auto& conn : connections){
            neighbours[conn[0]].push_back(conn[1]);  
            neighbours[conn[1]].push_back(conn[0]);            
        }

        vector<bool> visited(n, 0);
        vector<vector<int>> ans;

        time=0;
        dt.resize(n);
        low.resize(n);

        dfs(0, -1, neighbours, visited, ans);

        return ans;
    }
};
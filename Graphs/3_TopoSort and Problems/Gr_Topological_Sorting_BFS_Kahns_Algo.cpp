/*
Problem: Topological Sort BFS
Link: https://www.geeksforgeeks.org/problems/topological-sort/1
Difficulty: Medium
Approach: BFS (topological sorting)
Time Complexity: O(V+E)
Note:
    first, calc indegree for all nodes, if a node has indegree 0 => we can start from here (as it has no dependencies)
    => push that node into the queue and call bfs

    as we iterate in bfs, pick a node (front) as curr, pop and get into ans and for all its children, do indegree -= 1
    if at any point we encounter a neighbour with indegree which has become = 0 (after decrement)
    then push that node into the queue and repeat the process.

    at the end, if ans.size() != V => a cycle was detected because few nodes werent reachable
    else
        return res
*/

class Solution {
  public:
    void bfs(queue<int>& q, vector<vector<int>>& neighbours, vector<int>& indegree, vector<int>& res){
        int qsize = q.size();
        while (!q.empty()){
            qsize = q.size();
            for (int i=0; i<qsize; i++){
                int curr = q.front();
                q.pop();
                res.push_back(curr);
                for (auto& neigh: neighbours[curr]){
                    indegree[neigh]--;
                    if (indegree[neigh]==0)
                        q.push(neigh);
                }
            }
        }
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> neighbours(V, vector<int>{});
        vector<int> indegree(V,0);
        
        for (auto& edge : edges){
            neighbours[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        queue<int> q;
        vector<int> res;
        for (int i=0; i<V; i++){
            if (indegree[i]==0)
                q.push(i);
        }
        
        bfs(q, neighbours, indegree, res);
        
        return res;
    }
};
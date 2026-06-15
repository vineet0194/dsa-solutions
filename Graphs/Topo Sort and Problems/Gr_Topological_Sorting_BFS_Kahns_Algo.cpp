/*
Problem: Topological Sort BFS
Link: https://www.geeksforgeeks.org/problems/topological-sort/1
Difficulty: Medium
Approach: BFS (topological sorting)
Time Complexity: O(V+E)
Note:
    need to update
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

    bool isCyclic(int V, vector<vector<int>> &edges) {
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
        
        return !(res.size()==V);
    }
};
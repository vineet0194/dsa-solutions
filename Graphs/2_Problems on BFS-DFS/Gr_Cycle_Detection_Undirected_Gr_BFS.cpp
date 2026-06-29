/*
Problem: Undirected Graph Cycle
Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
Difficulty: Medium
Approach: BFS
Time Complexity: O(V+E)
Note:
    maintain a (curr) parent for which node which keeps track of the last visited node at current node
    if you come accross a neighbour which is already visited but is not a parent (normally parent can also be accounted
    as a neighbour hence return true wrongly), then return true (cycle detected!) else continue and check the next neighbour

    if a neighbour is not visited => visit and dfs there

    do this for all non-visited nodes in the graph => to account for inaccessible nodes (if graph has multiple components)
*/

 class Solution {
  public:
    bool bfs(int curr, int parent, vector<vector<int>>& adjList, vector<bool>& visited){
        queue<pair<int, int>> q;
        
        q.push({curr, parent});
        visited[curr] = 1;
        
        int qsize = q.size();
        
        while (!q.empty()){
            qsize = q.size();
            for (int k=0; k<qsize; k++){
                int i = q.front().first;            // curr
                int par = q.front().second;         // parent
                q.pop();
                for (auto& neigh : adjList[i]){     // next
                    if (visited[neigh]){
                        if (neigh == par)
                            continue;
                        else
                            return true;
                    }
                    else{
                        visited[neigh] = 1;
                        q.push({neigh, i});
                    }
                }
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        for (int i=0; i<edges.size(); i++){
            if (edges[i][0] == edges[i][1])
                return true;
        }

        if (V<3)
            return false;
            
        vector<vector<int>> adjList(V);
        for (int i=0; i<edges.size(); i++){
            adjList[edges[i][0]].emplace_back(edges[i][1]);
            adjList[edges[i][1]].emplace_back(edges[i][0]);
        }

        vector<bool> visited(V,0);
        
        bool ans = false;
        for (int i=0; i<V; i++){
            if (!visited[i]){
                ans = ans || bfs(i, -1, adjList, visited);
            }
        }
        
        return ans;
    }
};
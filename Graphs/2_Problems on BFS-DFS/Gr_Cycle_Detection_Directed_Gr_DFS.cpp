/*
Problem: Directed Graph Cycle
Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
Difficulty: Medium
Approach: DFS (Topological Sort)
Time Complexity: O(V+E)
Note:
    dfs() is basically cycleCheck()
    check cycle for each neighbour of curr in current callstack

    A cycle is detected if we encounter a node with state == 1
    which means neighbour is already in callstack => already being visited
    meaning there is a back edge in the current DFS path.
*/

class Solution {
  public:
      bool dfs(int curr, vector<vector<int>>& neighbours, vector<int>& state){
        state[curr]=1;

        for (auto& neigh: neighbours[curr]){
            if (state[neigh]==1)
                return true;
            else if (state[neigh]==0 && dfs(neigh, neighbours, state))
                return true;
        }

        state[curr]=2;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> state(V, 0);   // 0-not visited, 1-visiting (in call stack), 2-visited

        vector<vector<int>> neighbours(V, vector<int>{});
        for (auto& e : edges){
            neighbours[e[0]].push_back(e[1]);
        }

        for (int i=0; i<V; i++){
            if (state[i]==0 && dfs(i, neighbours, state))
                return true;
        }
        
        return false;
    }
};
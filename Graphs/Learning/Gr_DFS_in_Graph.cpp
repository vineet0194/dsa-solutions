/*
Problem: DFS of Graph
Link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
Difficulty: Easy
Approach: BFS in Graph using stack and recursion
Time Complexity: O(V+E)
Note:
    for iterative DFS, used a stack instead of a queue like in BFS and proceeded the same way
    here, pushing the children in a reverse manner helps to keep the adj order while printing

    for recursive, instead of using a stack, we use the logic of recursiona and see if a neighbour is not visited,
    perform DFS with that neighbour, mark visit only when you acutally visit the node
*/

// fails on GFG since this iterative DFS approach does not match the recursive DFS order
class Solution {
  public:
    vector<int> dfs(vector<vector<int>> &adj) {
        vector<int> ans;
        unordered_map<int, bool> visited;

        stack<int> st;
        st.push(0);
        visited[0] = true;
        
        while (!st.empty()){
            int curr = st.top();
            st.pop();
            ans.push_back(curr);
            for (int i=adj[curr].size()-1; i>=0; i--){
                if (!visited[adj[curr][i]]){
                    visited[adj[curr][i]] = true;
                    st.push(adj[curr][i]);
                }
            }
        }
        
        return ans;
    }
};

/* --------------------------------------------------------------------------------------------------------------- */

// Recursive Approach (accepted on GFG)

class Solution {
  public:
    void performDFS(int curr, vector<vector<int>>& adj, unordered_map<int, bool>& visited, vector<int>& ans){
        visited[curr] = true;
        ans.push_back(curr);
        
        for (auto& neigh : adj[curr]){
            if (!visited[neigh])
                performDFS(neigh, adj, visited, ans);
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        unordered_map<int, bool> visited;
        vector<int> ans;
        performDFS(0, adj, visited, ans);
        
        return ans;
    }
};
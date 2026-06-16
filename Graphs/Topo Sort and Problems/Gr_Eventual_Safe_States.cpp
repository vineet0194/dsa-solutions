/*
Problem: 802. Find Eventual Safe States
Link: https://leetcode.com/problems/find-eventual-safe-states/description/
Difficulty: Medium
Approach: DFS (topological sorting)
Time Complexity: O(V+E+VlogV) => O(V+E)
Note:
    we use the idea of dfs topological sorting
    we start from a parent node which is not yet visited (state=0), and call a dfs cycle check function on it
    if for any neighbour, we find a non-terminal point (i.e later in recursion we find a node of state=1) => loop detected
    if a loop is detected => parent can never be a safe node as the loop will never be terminal neither will the nodes
        that had occured in this path (IDEALLY, we should have used state=3 to mark unsafe nodes but here 1 works for both unsafe & visiting nodes)
    if we reach a point with no more neighbour remaining and no loops found => terminal point reached, take this into the answer
    and set its state as 2 and return false => no loop detected for this node

    iterate over all non-visited nodes (state=0) and do dfs checks
    in the end, return a sorted array as answer
*/

class Solution {
public:
    bool dfsCycleCheck(int curr, vector<vector<int>>& graph, vector<int>& state, vector<int>& safeNodes){
        state[curr] = 1;
        for (auto& neigh: graph[curr]){
            if (state[neigh]==1){
                return true;
            }
            if (state[neigh]==0 && dfsCycleCheck(neigh, graph, state, safeNodes)){
                return true;
            }
        }
        state[curr] = 2;
        safeNodes.push_back(curr);
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> state(V, 0);

        vector<int> safeNodes;
        for (int i=0; i<V; i++){
            if (state[i]==0)
                dfsCycleCheck(i, graph, state, safeNodes);
        }

        sort(safeNodes.begin(), safeNodes.end());
        
        return safeNodes;
    }
};
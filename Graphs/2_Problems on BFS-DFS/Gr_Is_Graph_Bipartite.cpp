/*
Problem: 785. Is Graph Bipartite?
Link: https://leetcode.com/problems/is-graph-bipartite/
Difficulty: Medium
Approach: DFS
Time Complexity: O(V+E)
Note:
    A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

    ! trick:
        try and colour the graph nodes in 2 diff colours such that 2 adjacent nodes never occur with the same colour
        if you are able to do so => graph is bipartite, else not bipartite

    ? intuition:
        if graph is bipartite, every edge will look like B->G   [ one node from Blue, another from green ]
            hence doing exactly what the question asked us to.
        if you see an edge doing B->B or G->G   [ 2 nodes from the same colour ] => graph is not bipartite
            as our defintion has failed
*/

class Solution {
public:
    bool ans = true;

    void dfs(int u, int prevCol, vector<vector<int>>& graph, vector<int>& colour){
        colour[u] = (prevCol==-1 || prevCol==2) ? 1 : 2;

        if (ans == false)           // early exit
            return;

        for (auto& v: graph[u]){
            if (colour[v] == 0){                    // not visited
                dfs(v, colour[u], graph, colour);
            }
            else if (colour[v] == colour[u]){            // visited v and same colour
                ans = false;
                return;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> colour(n, 0);
        // 0 --> not coloured (not visited)
        // 1 --> blue
        // 2 --> green
        
        for (int i=0; i<n; i++){
            if (colour[i] == 0)
                dfs(i, -1, graph, colour);  // prevCol = -1 => init
        }

        return ans;
    }
};
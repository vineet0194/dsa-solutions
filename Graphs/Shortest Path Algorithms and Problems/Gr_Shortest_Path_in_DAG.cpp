/*
Problem: Shortest path in Directed Acyclic Graph
Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
Difficulty: Medium
Approach: Queue based relation (BFS)
Time Complexity: O(VE)
Note:
    ! BFS guarantees shortest paths only in unweighted graphs because it explores nodes by the number of edges traversed, not by the
    ! total path weight. When edge weights differ, the path with fewer edges may not have the minimum cost.

    This is why the first solution is not optimal (however it is accepted on GFG due to lower constraints)

    ! scroll down for optimal solution !
*/

class Solution {
  public:
    void bfsDistFill(int src, vector<vector<pair<int,int>>>& neighbours, vector<int>& dist){
        queue<pair<int,int>> q;
        
        q.push({src, 0});
        dist[src]=0;
        
        int qsize=q.size();
        while (!q.empty()){
            qsize = q.size();
            for (int i=0; i<qsize; i++){
                int currNode = q.front().first;
                int currDist = q.front().second;
                q.pop();
                for (auto& neigh : neighbours[currNode]){
                    int next = neigh.first;
                    int nextDist = currDist+neigh.second;
                    if (dist[next] == -1 || nextDist < dist[next]){
                        q.push({next, nextDist});
                        dist[next] = nextDist;
                    }
                }
            }
        }
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<int> dist(V, -1);
        vector<vector<pair<int,int>>> neighbours(V);
        
        
        for (int i=0; i<E; i++){
            neighbours[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        bfsDistFill(0, neighbours, dist);
        
        return dist;
    }
};


// ------------------------------------------------------------------------------------------------------------------ //

// OPTIMAL SOLUTION => O(V+E)

/*
For a weighted DAG, use Topological Sort + Edge Relaxation.

Why it works?
    A DAG has no cycles, so we can arrange nodes in a topological order:

When processing a node u, all possible paths that can reach u have already been considered. Therefore, dist[u] is final, and you can safely relax its outgoing edges.
*/


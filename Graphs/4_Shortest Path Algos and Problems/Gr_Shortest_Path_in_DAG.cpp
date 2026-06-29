/*
Problem: Shortest path in Directed Acyclic Graph
Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
Difficulty: Medium
Approach: Queue based relaxation (BFS)      ,       optimal approach: Topological Sorting
Time Complexity: O(VE)      ,       optimal: O(2(V+E)) => O(V+E)
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

When processing a node u, all possible paths that can reach u have already been considered.
Therefore, dist[u] is final, and you can safely relax its outgoing edges.

:::::::::::::::::::::::::::::::::::::::::::::::
             :: ALGORITHM STEPS ::

1) do a topo sort on the graph
2) take the nodes out of stack and 'relax' them

:::::::::::::::::::::::::::::::::::::::::::::::

!   if (currDist == -1)         // current node is unreachable => dont relax
    continue;

    how did an unreachable node reach into the stack?
    becos we did dfsTopo for all non-visited node, it might have created its own dfs tree in the forest
    (disconnected component)
*/

class Solution {
  public:
    void dfsTopo(int src, vector<vector<pair<int, int>>>& neighbours, vector<bool>& visited, stack<int>& st){
        visited[src] = 1;
        for (auto& neigh : neighbours[src]){
            int next = neigh.first;
            if (!visited[next]){
                dfsTopo(next, neighbours, visited, st);
            }
        }
        st.push(src);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> neighbours(V);
        
        for (int i=0; i<E; i++){
            neighbours[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        vector<bool> visited(V, 0);
        
        stack<int> topoSt;
        
        for (int i=0; i<V; i++){
            if (!visited[i])
                dfsTopo(i, neighbours, visited, topoSt);
        }
        
        vector<int> dist(V, -1);
        dist[0] = 0;
        
        while (!topoSt.empty()){
            int curr = topoSt.top();
            int currDist = dist[curr];
            topoSt.pop();
            if (currDist == -1)         // current node is unreachable => dont relax
                continue;
            for (auto& neigh : neighbours[curr]){           // relaxation
                int next = neigh.first;
                int nextDist = currDist + neigh.second;
                if (dist[next] == -1 || nextDist < dist[next])
                    dist[next] = nextDist;
            }
        }
        
        return dist;
    }
};

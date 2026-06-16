/*
Problem: Shortest Path in Undirected Graph
Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
Difficulty: Medium
Approach: BFS (topological sort)
Time Complexity: O(V+E)
Note:
    we maintain a dist array which maps distance from src to node for all verticies, instantiated with -1
    at every step, we do +1 in currDist (this marks -> the distance covered to reach this node from src)
    now for all neighbours of current, if dist[neigh] == -1 => first time visiting this neighbour node => set dist and push to q
    or if currDist+1 < dist[neigh] => new dist we found is less than previously calculated distance (from older visits)
            => set the new dist and push to q
    if a node's dist remains -1 => it is unreachable from the source, return the dist array at the end of program

    ! why do not need to maintain a parent here in queue for bfs topo ! =>  undirectd graph questions
    we might think that when we visit a node, it would also calculate the distance for the parent node, should we bother
    to create a "visited" array or maintain a parent to not-consider already visited nodes? NO
    because - 1) you might visit a already visited node again (to find a better/optimal path with lesser dist)
            - 2) at any node (curr) when curr checks dist for all neighs, it does so for the parent too,
                 currDist+1 will always be > currDist-1, parent node will always be currDist-1 (1 lesser than reaching the current)
                 so distance for src->parent->curr->parent will always be greater than src->parent->curr
                 hence, it will never be updated (since we account for minimum dist updates only)

    ! This type of queue/BFS method works for unweighted graphs ONLY !
    When every edge has the same weight (usually 1), the number of edges in a path is directly proportional to its total cost.
    BFS explores vertices level by level => When every edge has the same weight (usually 1), the number of edges in a path is
    directly proportional to its total cost => Shortest path cost = Minimum number of edges
    Since BFS always reaches nodes using the fewest edges first, the first time a node is visited, its shortest distance is guaranteed

    ! BFS guarantees shortest paths only in unweighted graphs because it explores nodes by the number of edges traversed, not by the
    ! total path weight. When edge weights differ, the path with fewer edges may not have the minimum cost.
*/

class Solution {
  public:
    void bfsDistFill(int src, vector<vector<int>>& neighbours, vector<int>& dist){
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
                    // if (dist[neigh] == -1 || currDist+1 < dist[neigh]){       // need not use this
                    if (dist[neigh] == -1){                     // ! bfs guarntees shortest path at first visit
                        q.push({neigh, currDist+1});            // ! given that it is an unweighted graph
                        dist[neigh] = currDist+1;
                    }
                }
            }
        }
    }
  
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<int> dist(V, -1);
        vector<vector<int>> neighbours(V, vector<int>{});
        
        for (int i=0; i<edges.size(); i++){
            neighbours[edges[i][0]].push_back(edges[i][1]);
            neighbours[edges[i][1]].push_back(edges[i][0]);
        }
        
        bfsDistFill(src, neighbours, dist);
        
        return dist;
    }
};

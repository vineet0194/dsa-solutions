/*
Problem: BFS of graph
Link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
Difficulty: Easy
Approach: BFS in Graph using queue
Time Complexity: O(V+E)     The while loop processes each vertex once => V iterations total.
                            For each processed vertex, you iterate through its adjacency list.
                            Forall, the total number of neighbor iterations equals the total size of all adjacency lists.
                            => total of number of neighbour iterations = number of edges = E
Note:
    basically the same thing we did in level order of trees, get the start/root in a queue, get a qsize variable
    to emulate a section of queue that represents the current level
    while (q is not empty)
        for (i from 0 to qsize-1)
            curr = front
            pop curr
            get all the non-visited children/neighbours of curr into the queue
            mark the children/neighbours as visited

*/

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans;
        unordered_map<int, bool> visited;

        queue<int> q;
        q.push(0);
        visited[0] = true;
        int qsize = q.size();
        
        while (!q.empty()){
            qsize = q.size();
            for (int i=0; i<qsize; i++){
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for (auto& neigh : adj[curr]){
                    if (!visited[neigh]){
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }
        }
        
        return ans;
    }
};
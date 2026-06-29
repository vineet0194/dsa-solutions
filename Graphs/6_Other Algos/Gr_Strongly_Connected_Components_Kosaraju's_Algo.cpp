/*
Problem: Count Strongly Connected Components
Link: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
Difficulty: Medium
Approach: Reverse DFS (Kosaraju's Algorithm)
Time Complexity: O(V+E)
Note:
    steps:
        1. get nodes in stack (topological order)
        2. transpose the graph
        3. do dfs according to the stack nodes on transpose graph

    intuition:
        1) consider SCCs in a directed graph as individual points then that graph would become a DAG
        with each node as an SCC connected by 1 single edge
            ? if this wasnt the case (back edge or cyclic) => SCCs would merge to form a bigger SCC
        
        now, you can get proper sequence of a DAG using topological sorting

        2) now if you try DFS node wise without transpose => you will by mistake traverse entire graph
            as we have a structure similar to A->B->C and stack is top-> ABC] where A, B and C are SCCs
                ? to prevent so, we flip the edges (transpose)
                ? our new graph becomes A<-B<-C     now traversing through A, only lets us traverse through SCC A, not the entire graph
                ? any time we encounter a non-visited node in the stack => we have found a new SCC
*/

class Solution {
  public:
    void findTopologicalOrder(int u, vector<vector<int>>& neighbours, vector<bool>& visited, stack<int>& st){
        visited[u] = true;
        
        for (auto& v: neighbours[u]){
            if (!visited[v])
                findTopologicalOrder(v, neighbours, visited, st);
        }
        
        st.push(u);
    }
    
    void doDFS(int u, vector<vector<int>>& tNeighbours, vector<bool>& visited){
        visited[u] = true;
        
        for (auto& v: tNeighbours[u]){
            if (!visited[v])
                doDFS(v, tNeighbours, visited);
        }
    }
  
    int implementKosaraju(int V, vector<vector<int>> &edges){
        vector<vector<int>> neighbours(V);
        for (auto& edge: edges){
            neighbours[edge[0]].push_back(edge[1]);
        }
        
        vector<bool> visited(V, false);
        stack<int> st;
        
        //  1. finding topological order of graph
        for (int i=0; i<V; i++){
            if (!visited[i])
                findTopologicalOrder(i, neighbours, visited, st);
        }
        
        // 2. getting the transpose of graph
        vector<vector<int>> transposeNeighbours(V);
        for (auto& edge: edges){
            transposeNeighbours[edge[1]].push_back(edge[0]);
        }
        fill(visited.begin(), visited.end(), false);
        
        // 3. doing dfs in the topological order
        int SCC=0;
        while (!st.empty()){
            int u = st.top();
            st.pop();
            
            if (!visited[u]){
                SCC++;
                doDFS(u, transposeNeighbours, visited);
            }
            
        }
        
        return SCC;
    }
  
    int kosaraju(int V, vector<vector<int>> &edges){
        int ans = implementKosaraju(V, edges);
        return ans;
    }
};
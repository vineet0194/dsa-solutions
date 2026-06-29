/*
Problem: Topological Sort DFS
Link: https://www.geeksforgeeks.org/problems/topological-sort/1
Difficulty: Medium
Approach: DFS (topological sorting)
Time Complexity: O(V+E)
Note:
    Topolical sorting is the linear order of vertices such that for every pair of nodes (u->v) in a DAG,
    vertex u comes before v. There can be multiple possible topological sort orders for a graph.

    Idea: DFS
    Intuition: Dependency solving, stack => LIFO, so we recursively search for a node with no further dependants,
                this node will either have dependants of its own (then this node should be pushed first (so that last out))
                or this node will be an independent node => can be pushed first (we will but does not matter => will depend on what
                order are you calling your dfs functions in, be default we follow an index sorted order (0 to n) through visited array) 
    
    ! The DFS itself guarantees that by the time a node is pushed into the stack,
    ! all of its dependencies (reachable descendants) have already been processed.

    if you need the order (only result) => maintain a stack     !!
    if you do not need the order => utilise callstack           !!
    eg: course schedule 1 and 2 ==> 1 requires only result, 2 requires the order of result

    Cycle Detected using TopoSorting DFS in Directed Graphs
        Undirected Graph:
        -----------------
        A cycle exists if we reach a visited node that is NOT the parent.

        Example:
        0 -- 1

        When DFS goes 0 -> 1, node 1 will see 0 again.
        This does NOT form a cycle because it is simply the same edge
        being traversed in the opposite direction.

        Hence:
        if (visited[neigh] && neigh != parent)
            cycle = true;


        Directed Graph:
        ---------------
        The parent check does NOT work.

        Example (NO cycle):
        0 -> 1
        |    |
        v    v
        2 <-/

        DFS: 0 -> 1 -> 2

        Later, DFS returns to 0 and examines edge 0 -> 2.
        Node 2 is already visited, but this does NOT imply a cycle.

        Thus, in a directed graph:
        visited[neigh] == true
        is NOT sufficient to conclude a cycle.

        Reason:
        A directed edge to an already visited node can be:
        1. Back Edge   -> forms a cycle
        2. Cross Edge  -> no cycle
        3. Forward Edge-> no cycle

        Therefore we need 3 states:

        state[node] =
        0 : unvisited
        1 : currently in recursion stack (visiting)
        2 : fully processed (visited)
*/

class Solution {
  public:
    void dfs(int curr, vector<vector<int>>& neighbours, vector<bool>& visited, stack<int>& st){
        visited[curr] = true;
        for (auto& neigh : neighbours[curr]){
            if (!visited[neigh])
                dfs(neigh, neighbours, visited, st);
        }
        st.push(curr);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> ans={};
        
        vector<vector<int>> neighbours(V, vector<int>{});
        for (int i=0; i<edges.size(); i++){
            neighbours[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<bool> visited(V, false);
        stack<int> st;
        
        for (int i=0; i<V; i++){
            if (!visited[i])
                dfs(i, neighbours, visited, st);
        }

        /*
            The visited array does NOT represent whether a node has remaining dependencies or whether it is "ready" to be processed.
            Instead, it simply means:
                -> this node has already been discovered and fully explored in some previous DFS call.

            So when we check:
            if (!visited[i]) dfs(i);
                It does NOT mean:
                            -> "i has no unmet dependencies"

                It means:
                            -> "i has not been reached by any previous DFS traversal"

            Key intuition:
                visited[i] == false  ⇒  node i is in no previous DFS tree yet
                so it becomes the ROOT of a new DFS tree
        */
        
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
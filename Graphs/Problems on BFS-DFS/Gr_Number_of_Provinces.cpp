/*
Problem: 547. Number of Provinces      // Number of connected components
Link: https://leetcode.com/problems/number-of-provinces/
Difficulty: Medium
Approach: BFS
Time Complexity: O(n^2)
Note:
    for each non-visited node, apply BFS and visit all the nodes you can from that starting node,
    increase the provFound counter when you are done traversing all accessible nodes from the starting node
    then go for the next non-visited node and apply BFS from that node, repeating the process

    here we have an adjacency matrix instead of a list => O(V+E) for BFS turns to O(V^2)
    since a for loop is iterating for each non-visited loop, its V + V^2 => O(V^2)
*/

class Solution {
public:
    void bfs(int i, vector<vector<int>>& isConnected, vector<bool>& visited){
        queue<int> q;

        q.push(i);
        visited[i] = true;
        int qsize = q.size();

        while (!q.empty()){
            qsize = q.size();
            for (int i=0; i<qsize; i++){
                int curr = q.front();
                q.pop();
                for (int j=0; j<isConnected.size(); j++){
                    if (isConnected[curr][j]==1 && !visited[j]){
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int provincesFound=0;
        int V = isConnected.size();
        vector<bool> visited(V,0);

        for (int i=0; i<V; i++){
            if (!visited[i]){
                bfs(i, isConnected, visited);
                provincesFound++;
            }
        }
        return provincesFound;
    }
};
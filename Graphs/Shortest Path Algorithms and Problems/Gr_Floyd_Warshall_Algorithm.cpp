/*
Problem: Floyd Warshall Algorithm
Link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
Difficulty: Medium
Approach: DP (Floyd Warshall)
Time Complexity: O(V^3)
Note:
    all pair shortest path algorithm

    for all pair of vertices (i, j) try to find a vertex (k) such that distance of going from (i) to (j) THROUGH (k)
    is less than directly going from (i) to (j)

    1e8 check is done so as to not accidently consider false positive paths as here, we consider 1e8 = INF
*/

class Solution {
  public:
    void implementFloydWarshall(int V, vector<vector<int>>& dist){
        for (int k=0; k<V; k++){
            for (int i=0; i<V; i++){
                for (int j=0; j<V; j++){
                    if (dist[i][k] != 1e8 && dist[k][j] != 1e8)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
  
    void floydWarshall(vector<vector<int>> &dist) {
        int V = dist.size();
        
        implementFloydWarshall(V, dist);
        return;
    }
};
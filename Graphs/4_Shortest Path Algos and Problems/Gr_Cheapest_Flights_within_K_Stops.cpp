/*
Problem: 
Link: 
Difficulty: 
Approach: 
Time Complexity: 
Note:
    The temporary distance array ensures that the relaxations performed in the current iteration do not affect
    other relaxations in the same iteration. This guarantees that the ith iteration only computes shortest
    paths using at most i edges. Without the temporary array, newly relaxed distances can be reused immediately,
    effectively allowing paths with multiple additional edges within a single iteration.
*/

class Solution {
public:
    void bellmanFord(vector<vector<int>>& flights, vector<int>& dist, int k){
        for (int i=0; i<k+1; i++){
            vector<int> temp=dist;  // makes sure relaxations performed in the current iteration
                                    //does not affect other relaxations in the same iteration.
            for (auto& flight : flights){
                int u = flight[0];
                int v = flight[1];
                int wt = flight[2];
                // for temp, WRITE is allowed, READ is NOT
                // WRITE => only stores the best value to reach node
                // READ => allows to use that value as source for another relaxation
                // you are allowed to WRITE the best value but not to READ it until the next iteration that allows 1 more edge
                // so you read the old value => dist[u]
                if (dist[u] != INT_MAX && temp[v] > dist[u] + wt)
                    temp[v] = dist[u] + wt;
            }
            dist = temp;
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        bellmanFord(flights, dist, k);

        if (dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};
/*
Problem: MST using Kruskal's Algorithm
Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1
Difficulty: Medium
Approach: Greedy BFS (Kruskal's Algorithm)
Time Complexity: O(ElogE)​
Note:
    Preferred for sparse graphs MST findings

    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return a[2] < b[2];
    });

    EXPLANATION:
        1. sort(...)
        - Built-in C++ function
        - Sorts elements in a given range

        2. edges.begin(), edges.end()
        - Defines the range to sort (entire vector)

        3. [](auto &a, auto &b)
        - Lambda function (anonymous function)
        - Acts as comparator
        - a and b are two edges (vector<int>)

        4. auto &
        - auto → compiler detects type (vector<int>)
        - & → reference (avoids copying, faster)

        5. a[2], b[2]
        - 3rd element of each edge = weight

        6. return a[2] < b[2]
        - If true → a comes before b
        - Sorts in ascending order of weight

*/

class DisJointSetUnion{
public:
    int n;
    vector<int> leader, rank;
    
    DisJointSetUnion(int n){
        for (int i=0; i<n; i++){
            leader.push_back(i);
            rank.push_back(0);
        }
    }
    
    int findLeader(int x){
        if (leader[x] == x)
            return x;
        int leader = findLeader(leader[x]);
        leader[x] = leader;
        return leader;
    }
    
    void doUnionByRank(int u, int v){
        int leaderOfU = findLeader(u);
        int leaderOfV = findLeader(v);
        
        if (leaderOfU == leaderOfV)
            return;
        
        if (rank[leaderOfU] == rank[leaderOfV]){
            leader[leaderOfV] = leaderOfU;
            rank[leaderOfU]++;
        }
        else if (rank[leaderOfU] > rank[leaderOfV]){
            leader[leaderOfV] = leaderOfU;
            rank[leaderOfU]++;
        }
        else{
            leader[leaderOfU] = leaderOfV;
            rank[leaderOfV]++;
        }
    }
    
    int implementKruskal(vector<vector<int>>& edges){
        sort(edges.begin(), edges.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });
        int cost = 0;
        for (auto& edge : edges){
            int wt = edge[2];
            
            int leaderOfU = findLeader(edge[0]);
            int leaderOfV = findLeader(edge[1]);
            
            // ! if both leaders are same => same group => will form cycle => DONT TAKE EDGE !
            // if not same :
            if (leaderOfU != leaderOfV){    
                // picking an edge = doing union of 2 vertices => consider that edge weight in MST cost
                doUnionByRank(edge[0], edge[1]);
                cost += wt;
            }
        }
        return cost;
    }
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        DisJointSetUnion myDSU(V);
        int cost = myDSU.implementKruskal(edges);
        
        return cost;
    }
};
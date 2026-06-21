/*
Problem: Disjoint Set (Union Find)
Link: -
Difficulty: Easy
Approach: DSU
Time Complexity:
            With both optimizations (path compression + union by rank)
                findLeader() => amortized O(α(n))
                doUnion() => amortized O(α(n))
            where α is the inverse Ackermann function, which is effectively constant for any practical input size.

            Practically => O(1)
Note:
    ! fixed variable names for better understanding
*/

class DisJointSetUnion{
public:
    int n;
    vector<int> par;
    DisJointSetUnion(int n){
        this->n = n;
        for (int i=0; i<n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }
    
    int findLeader(int x){
        if (par[x] == x)        // found leader
            return x;   
        int leader = findLeader(par[x]);
        par[x] = leader;
        return leader;
    }
    
    void doUnion(int a, int b){
        int leaderOfA = findLeader(a);
        int leaderOfB = findLeader(b);
        
        if (leaderOfA == leaderOfB)
            return;

        if (rank[leaderOfA] == rank[leaderOfB]){
            par[leaderOfB] = leaderOfA;
            rank[leaderOfA]++;
        }
        else if (rank[leaderOfA] > rank[leaderOfB])
            par[leaderOfB] = leaderOfA;
        else
            par[leaderOfA] = leaderOfB;
    }
};

class Solution {
  public:
    vector<int> DSU(int n, vector<vector<int>>& queries){
        DisJointSetUnion myDSU(n);
        vector<int> ans;
        
        for (auto& query : queries){
            if (query[0] == 2){
                int repr = myDSU.findLeader(query[1]);
                ans.push_back(repr);
            }
            else if (query[0] == 1)
                myDSU.doUnion(query[1], query[2]);
        }
        
        return ans;
    }
};
/*
Problem: Disjoint set (Union-Find)
Link: https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1
Difficulty: Easy
Approach: DSU
Time Complexity: O(kα(n)) amortized
Note:
    here, we are asked to not do union by rank but instead simply but merge A to B => no need of rank array
*/

class DisJointSetUnion{
public:
    int n;
    vector<int> par;
    DisJointSetUnion(int n){
        this->n = n;
        for (int i=0; i<n+1; i++){
            par.push_back(i);
        }
    }
    
    int findLeader(int x){
        if (par[x] == x)        // found leader
            return x;   
        int parent = findLeader(par[x]);
        par[x] = parent;
        return parent;
    }
    
    void doUnion(int a, int b){
        int leaderOfA = findLeader(a);
        int leaderOfB = findLeader(b);
        
        if (leaderOfA == leaderOfB)
            return;
    
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
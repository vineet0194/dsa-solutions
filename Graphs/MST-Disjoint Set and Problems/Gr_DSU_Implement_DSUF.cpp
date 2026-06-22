/*
Problem: Disjoint set (Union-Find)
Link: https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1
Difficulty: Easy
Approach: DSU
Time Complexity: O(kα(n)) amortized
Note:

*/

class DisJointSetUnion{
public:
    int n;
    vector<int> leader;
    DisJointSetUnion(int n){
        this->n = n;
        for (int i=0; i<n+1; i++){
            leader.push_back(i);
        }
    }
    
    int findLeader(int x){
        if (leader[x] == x)        // found leader
            return x;   
        int parent = findLeader(leader[x]);
        leader[x] = parent;
        return parent;
    }
    
    void doUnion(int a, int b) {
        int leaderOfA = findLeader(a);
        int leaderOfB = findLeader(b);

        if (leaderOfA == leaderOfB)
            return;

        if (rank[leaderOfA] < rank[leaderOfB]) {
            leader[leaderOfA] = leaderOfB;
        }
        else if (rank[leaderOfA] > rank[leaderOfB]) {
            leader[leaderOfB] = leaderOfA;
        }
        else {
            leader[leaderOfB] = leaderOfA;
            rank[leaderOfA]++;
        }
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
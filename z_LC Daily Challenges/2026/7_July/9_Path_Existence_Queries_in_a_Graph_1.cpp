/*
Problem: 3532. Path Existence Queries in a Graph I
Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/?envType=daily-question&envId=2026-07-09
Difficulty: Medium
Approach: DSU
Time Complexity: O(n+q)
Note:
    
*/

class DSU{
public:
    int n;
    vector<int> leader;
    vector<int> rank;

    DSU(int n){
        this-> n = n;
        for (int i=0; i<n; i++){
            leader.push_back(i);
            rank.push_back(0);
        }
    }

    int findLeader(int x){
        if (leader[x] == x)
            return x;
        else
            return leader[x] = findLeader(leader[x]);
    }

    void doUnion(int a, int b){
        int leaderOfA = findLeader(a);
        int leaderOfB = findLeader(b);

        if (leaderOfA == leaderOfB)
            return;
        
        if (rank[leaderOfA] == rank[leaderOfB]){
            leader[leaderOfB] = leaderOfA;
            rank[leaderOfA]++;
        }
        else if (rank[leaderOfA] > rank[leaderOfB])
            leader[leaderOfB] = leaderOfA;
        else
            leader[leaderOfA] = leaderOfB;
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU myDSU(n);

        for (int i=1; i<n; i++){
            if (nums[i]-nums[i-1] <= maxDiff){
                myDSU.doUnion(i, i-1);
            }
        }

        vector<bool> ans = {};
        for (auto& query: queries){
            if (query[0] == query[1]){
                ans.push_back(true);
                continue;
            }
            if (myDSU.findLeader(query[0]) == myDSU.findLeader(query[1]))
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};
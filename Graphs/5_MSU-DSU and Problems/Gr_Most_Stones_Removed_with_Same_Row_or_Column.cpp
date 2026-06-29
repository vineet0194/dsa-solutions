/*
Problem: 947. Most Stones Removed with Same Row or Column
Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
Difficulty: Medium
Approach: DSU
Time Complexity: O(n^2)
Note:
    if (points' leader are same) => they are already grouped together
    else{
        group points together if they have a a common row / col,
        ! this check is necessary (even if their leaders are diff) as points can be totally unrelated (no same common row/col)
        !    and therefore be in diff group - not necessarily require to be grouped
    }
*/

class DSU{
public:
    int n;
    vector<vector<int>> stones;
    vector<int> leader;

    DSU(vector<vector<int>>& stones){
        this->n = stones.size();
        this->stones = stones;
        for (int i=0; i<n; i++){
            leader.push_back(i);    // leader[i] = i (initially => all points are self leaders)
        }
    }

    int findLeader(int stone){
        if (leader[stone] == stone)
            return stone;
        int newLeader = findLeader(leader[stone]);
        leader[stone] = newLeader;
        return newLeader;
    }

    int doUnion(){
        int removed=0;
        for (int i=0; i<stones.size(); i++){
            int leaderOfI = findLeader(i);
            for (int j=i+1; j<stones.size(); j++){
                int leaderOfJ = findLeader(j);
                if (leaderOfI == leaderOfJ)     // we have already removed this node
                    continue;
                else{
                    if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                        leader[leaderOfJ] = leaderOfI;
                        removed++;
                    }
                }
            }
        }
        return removed;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU myDSU(stones);
        int ans = myDSU.doUnion();

        return ans;
    }
};
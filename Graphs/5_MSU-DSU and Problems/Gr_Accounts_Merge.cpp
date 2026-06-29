/*
Problem: 721. Accounts Merge
Link: https://leetcode.com/problems/accounts-merge/description/
Difficulty: Medium (should be Hard)
Approach: DSU
Time Complexity: O(MlogM)   M => total number of email entries of all accounts
Note:
    
*/

class DSU{
public:
    int n;
    vector<int> leader;
    vector<int> rank;

    DSU(int n){
        this->n = n;
        for (int i=0; i<n; i++){
            leader.push_back(i);
            rank.push_back(i);
        }
    }

    int findLeader(int x){
        if (leader[x] == x)
            return x;
        return leader[x] = findLeader(leader[x]);
    }

    void doUnionByRank(int a, int b){
        int leaderOfA = findLeader(a);
        int leaderOfB = findLeader(b);
        if (leaderOfA == leaderOfB)
            return;
        if (rank[leaderOfA] == rank[leaderOfB]){
            leader[leaderOfB] = leaderOfA;
            rank[leaderOfA]++;
        }
        else if (rank[leaderOfA] > rank[leaderOfB]){
            leader[leaderOfB] = leaderOfA;
        }
        else
            leader[leaderOfA] = leaderOfB;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU myDSU(n);

        unordered_map<string, int> map;

        for (int i=0; i<n; i++){
            for (int j=1; j<accounts[i].size(); j++){
                if (map.find(accounts[i][j]) == map.end())
                    map[accounts[i][j]] = i;                // if new found => keep (regardless if its siblings causes union)
                else{                                                                           // => will handle later
                    myDSU.doUnionByRank(map[accounts[i][j]], i);    // if old found => do union
                }
            }
        }

        vector<vector<string>> mergedMails(n);          // for each n, get merged accounts
        for (auto& it: map){
            string mail = it.first;
            int node = myDSU.findLeader(it.second);     // but before that, find the real leader
            mergedMails[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for (int i=0; i<n; i++){
            if (mergedMails[i].size()==0)       // for each non-empty n, put name at 0 position and emails at the following
                continue;
            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto& it : mergedMails[i])
                temp.push_back(it);
            ans.push_back(temp);
        }

        return ans;
    }
};
/*
Problem: 1319. Number of Operations to Make Network Connected
Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
Difficulty: Medium
Approach: DSU (Kruskal's Algo with some manipulation)
Time Complexity: O((N + M) * α(N)) => O((N + M))    N = number of computers (n), M = number of connections
Note:
    1. find number of connections (edges) you can remove => let R
    2. find number of components in graph
    3. for C components, you need C-1 edges to connect
    4. if (R >= C-1) => we need to do C-1 operations to get all components connected
    5. else we can => -1
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
            rank.push_back(0);
        }
    }

    int findLeader(int x){
        if (leader[x] == x)
            return x;
        return leader[x] = findLeader(leader[x]);
    }

    void doUnionByRank(int a, int b){
        int leaderA = findLeader(a);
        int leaderB = findLeader(b);

        if (leaderA == leaderB)
            return;
        if (rank[leaderA] == rank[leaderB]){
            leader[leaderB] = leaderA;
            rank[leaderA]++;
        }
        else if(rank[leaderA] > rank[leaderB])
            leader[leaderB] = leaderA;
        else
            leader[leaderA] = leaderB;
    }

    int giveNumRemovableConns(vector<vector<int>>& connections){
        int removable = 0;
        for (auto& conn : connections){
            int leaderU = findLeader(conn[0]);
            int leaderV = findLeader(conn[1]);
            if (leaderU == leaderV){
                removable++;
            }
            else
                doUnionByRank(conn[0], conn[1]);
        }
        return removable;
    }

    int numOfComponents(){
        int components=0;
        unordered_map<int, int> uniqueLeaders;
        for (int i=0; i<n; i++){
            int ld = findLeader(i);
            if (uniqueLeaders.find(ld)==uniqueLeaders.end()){
                components++;
                uniqueLeaders[ld] = 1;
            }
        }
        return components;
    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU myDSU(n);

        int removable = myDSU.giveNumRemovableConns(connections);
        int comps = myDSU.numOfComponents();

        if (removable >= comps-1)
            return comps-1;
        else
            return -1;
    }
};
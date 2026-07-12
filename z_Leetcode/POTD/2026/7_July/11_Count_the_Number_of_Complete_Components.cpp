/*
Problem: 2685. Count the Number of Complete Components
Link: https://leetcode.com/problems/count-the-number-of-complete-components/?envType=daily-question&envId=2026-07-11
Difficulty: Medium
Approach: DSU + BFS
Time Complexity: O(N+E)
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
            rank.push_back(0);
        }
    }

    int findLeader(int x){
        if (leader[x] == x)
            return x;
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
    int doBFS(int& src, int& nodeCount, vector<vector<int>> neighbours, vector<bool>& visited, vector<int>& inDegree){
        if (nodeCount == 1)
            return 1;

        int inDegSum=0;

        queue<int> q;

        q.push(src);
        inDegSum += inDegree[src];
        visited[src] = true;

        int qsize;

        while (!q.empty()){
            qsize = q.size();
            for (int k=0; k<qsize; k++){
                int u = q.front();
                q.pop();

                for (auto& v: neighbours[u]){
                    if (!visited[v]){
                        visited[v] = true;
                        inDegSum += inDegree[v];

                        if (inDegSum == nodeCount*(nodeCount-1))
                            return 1;

                        q.push(v);
                    }
                }
            }
        }
        return 0;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU myDSU(n);

        vector<int> inDegree(n, 0);

        vector<vector<int>> neighbours(n);

        // edge count per node
        // calc. indegree for each node, edge[1] = v (u->v) means v has an "in" from u
        for (auto& edge: edges){
            myDSU.doUnion(edge[0], edge[1]);

            neighbours[edge[0]].push_back(edge[1]);
            neighbours[edge[1]].push_back(edge[0]);

            inDegree[edge[0]] += 1;
            inDegree[edge[1]] += 1;
        }

        // node count per comp
        // mp[leader] = nodeCount in that component
        unordered_map<int, int> mp;
        for (int i=0; i<n; i++){
            int leader = myDSU.findLeader(i);
            if (mp.find(leader) == mp.end())
                mp[leader] = 1;
            else
                mp[leader] += 1;
        }

        int ans = 0;
        vector<bool> visited(n, false);

        for (auto& item : mp){
            int compLeader = item.first;
            int nodeCount = item.second;
            ans += doBFS(compLeader, nodeCount, neighbours, visited, inDegree);
        }
        return ans;
    }
};
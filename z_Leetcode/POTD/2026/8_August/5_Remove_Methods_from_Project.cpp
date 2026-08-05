/*
Problem: 3310. Remove Methods From Project
Link: https://leetcode.com/problems/remove-methods-from-project/?envType=daily-question&envId=2026-08-05
Difficulty: Medium
Approach: BFS
Time Complexity: O(n+m) for both
Note:
    
*/

// Sol.1 (original)

class Solution {
public:
    bool bfs(int &src, int& k, vector<vector<int>> &neighbours, vector<bool> &vis, vector<bool> &sus){
        queue<int> q;
        q.push(src);

        sus[src] = (src == k) ? true : false;
        vis[src] = true;

        while (!q.empty()){
            int curr = q.front();
            q.pop();

            for (auto& neigh : neighbours[curr]){
                if (!vis[neigh]){
                    if (!sus[curr] && sus[neigh])
                        return true;
                    vis[neigh] = true;
                    sus[neigh] = sus[src];
                    q.push(neigh);
                }
            }
        }

        return false;
    }

    vector<int> returnAll(int n){
        vector<int> arr;

        for (int i=0; i<n; i++)
            arr.push_back(i);
        
        return arr;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> neighbours(n);
        for (auto& edge : invocations)
            neighbours[edge[0]].push_back(edge[1]);
        
        vector<bool> vis(n, false);
        vector<bool> sus(n, false);
        bfs(k, k, neighbours, vis, sus);
        
        vis = vector<bool>(n, false);

        bool flag = false;
        for (int i=0; i<n; i++){
            if (!vis[i] && !sus[i])
                flag = bfs(i, k, neighbours, vis, sus);
            
            if (flag)
                return returnAll(n);
        }

        vector<int> ans;
        for (int i=0; i<n; i++){
            if (!sus[i])
                ans.push_back(i);
        }

        return ans;
    }
};

// Sol.2 (optimised)

class Solution {
public:
    void bfs(int &src, vector<vector<int>> &neighbours, vector<bool> &sus){
        queue<int> q;
        q.push(src);

        sus[src] = true;

        while (!q.empty()){
            int curr = q.front();
            q.pop();

            for (auto& neigh : neighbours[curr]){
                if (!sus[neigh]){
                    sus[neigh] = true;
                    q.push(neigh);
                }
            }
            
        }

    }

    vector<int> returnAll(int n){
        vector<int> arr;

        for (int i=0; i<n; i++)
            arr.push_back(i);
        
        return arr;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> neighbours(n);
        for (auto& edge: invocations)
            neighbours[edge[0]].push_back(edge[1]);

        vector<bool> sus(n, false);
        bfs(k, neighbours, sus);

        bool flag = false;
        for (auto& edge: invocations){
            if (!sus[edge[0]] && sus[edge[1]]){
                flag = true;
                break;
            }
        }

        if (flag)
            return returnAll(n);

        vector<int> ans;
        for (int i=0; i<n; i++){
            if (!sus[i])
                ans.push_back(i);
        }

        return ans;
    }
};
/*
Problem: 210. Course Schedule II
Link: https://leetcode.com/problems/course-schedule-ii/description/
Difficulty: Medium
Approach: DFS (topological sorting)
Time Complexity: 
Note:
    here, do the same as course schedule 1, but also maintain your own stack instead of callstack
    to keep track of the answer array
*/

class Solution {
public:
    bool dfs(int curr, vector<vector<int>>& prereq, vector<int>& state, stack<int>& st){
        state[curr]=1;

        for (auto& neigh: prereq[curr]){
            if (state[neigh]==1)
                return true;
            else if (state[neigh]==0 && dfs(neigh, prereq, state, st))
                return true;
        }

        state[curr]=2;
        st.push(curr);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prereq(numCourses, vector<int>{});
        for (auto& pre: prerequisites){
            prereq[pre[1]].push_back(pre[0]);
        }

        vector<int> state(numCourses, 0);

        stack<int> st;
        for (int i=0; i<numCourses; i++){
            if (state[i]==0 && dfs(i, prereq, state, st))
                return {};          // will return {} if anytime a loop is detected
        }

        // no loop detected, proceed to extract answer from stack
        vector<int> ans;
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
/*
Problem: 207. Course Schedule
Link: https://leetcode.com/problems/course-schedule/description/
Difficulty: Medium
Approach: DFS (topological sorting)
Time Complexity: O(V+E)
Note:
    maintain a 3 variable state for each course instead of a visited array
    where 0-not visited, 1-visiting (in call stack), 2-visited
    if we are recursing for a node, and occur on a neighbour which has state=1 => that neighbour is already
    in our call stack and being visited again => a loop is detected => return true (loop detected);
    if not, continue to set the state of node = 2 (visited) and return false (no loop detected)

    marking node[state] = 2 means taking it out of call stack
    0-->1           for this graph, if start from 0 if we go from 0->1->3, now 3 has no further neighbours
    |   |           we will mark 3 as visited/processed (state=2) and then it will be out of call stack
    V   V           how? because only 0 and 1 have state=1 for now, but 3 has state=2
    2-->3           then we check 1 has no neighbour left non-visited => 1 will also be called out of call stack
                    now we go to next neighbour of 0 i.e 2
                    now we go 0->2->3   we already see that state[3] = 2 i.e eventhough 3 is visited
                    it is not in the current callstack => all the nodes reachable from 3 including itself are processed
                    so we do not visited three and return back to, set its state to 2 (since no neighbours)
                    hence, removing 2 from call stack, then the same with 0.
                    all neighbours of start node processed and no loop detected => return false

    0<--1           if this would have been the case 0->2->3->1, now when we check for 1's neighbour,
    |   ^           we will reach 0, we see that 0 is still in the call stack (state=1)
    V   |           therefore, loop detected => return true
    2-->3

    here dfs() is basically cycleCheck() unless you maintain a stack with it which can be used to keep
    track of the topological order of the courses
*/

class Solution {
public:
    bool dfs(int curr, vector<vector<int>>& prereqs, vector<int>& state){
        state[curr]=1;      // visiting current node

        for (auto& neigh: prereqs[curr]){
            if (state[neigh]==1)
                return true;
            else if (state[neigh]==0 && dfs(neigh, prereqs, state))
                return true;
        }
 
        state[curr]=2;      // visited current node
        return false;       // no loop found
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> state(numCourses, 0);       // 0-not visited, 1-visiting (in call stack), 2-visited

        vector<vector<int>> prereqs(numCourses, vector<int>{});
        for (auto& pre : prerequisites){
            prereqs[pre[1]].push_back(pre[0]);
        }

        for (int i=0; i<numCourses; i++){
            if (state[i]==0 && dfs(i, prereqs, state))
                return false;
        }

        return true;
    }
};
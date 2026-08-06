/*
Problem: 621. Task Scheduler
Link: https://leetcode.com/problems/task-scheduler/description/
Difficulty: Medium
Approach: Heaps
Time Complexity: O(m) => m = tasks.size();
Note:
    
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char& task: tasks)
            freq[task-'A']++;
        
        priority_queue<int> pq;

        for (int& fq: freq){
            if (fq > 0)
                pq.emplace(fq);
        }

        int ans = 0;
        while (!pq.empty()){
            vector<int> temp;
            for (int i=0; i<n+1; i++){
                if (!pq.empty()){
                    temp.emplace_back(pq.top()-1);
                    pq.pop();
                }
            }

            for (int& fq: temp){
                if (fq > 0)
                    pq.emplace(fq);
            }

            if (pq.empty())
                ans += temp.size();
            else
                ans += n+1;
        }

        return ans;
    }
};
/*
Problem: Widest Possible Fence©leetcode
Link: https://leetcode.com/contest/biweekly-contest-188/problems/widest-possible-fence/description/
Difficulty: Medium
Approach: Hashing + Pair Sum Enumeration
Time Complexity: O(n^2 * logn)
Note:
    
*/

class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> F;
        for (int p : planks) {
            F[p]++;
        }
        
        vector<int> U;
        for (auto& kv : F) {
            U.push_back(kv.first);
        }
        
        vector<pair<int, int>> sums;
        int n = U.size();
        
        for (int i = 0; i < n; ++i) {
            if (F[U[i]] >= 2) {
                sums.push_back({U[i] * 2, F[U[i]] / 2});
            }
            for (int j = i + 1; j < n; ++j) {
                sums.push_back({U[i] + U[j], min(F[U[i]], F[U[j]])});
            }
        }
        
        sort(sums.begin(), sums.end());
        
        int max_w = 0;
        for (auto& kv : F) {
            max_w = max(max_w, kv.second);
        }
        
        int sz = sums.size();
        for (int i = 0; i < sz; ) {
            int current_sum = sums[i].first;
            int pair_count = 0;
            
            while (i < sz && sums[i].first == current_sum) {
                pair_count += sums[i].second;
                i++;
            }
            
            int total_width = pair_count;
            if (F.count(current_sum)) {
                total_width += F[current_sum];
            }
            
            max_w = max(max_w, total_width);
        }
        
        return max_w;
    }
};
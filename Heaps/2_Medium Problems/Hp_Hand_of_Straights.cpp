/*
Problem: 846. Hand of Straights
Link: https://leetcode.com/problems/hand-of-straights/
Difficulty: Medium
Approach: Min Heap
Time Complexity: O(n)+O(mlogm)+O(nlogm)
Note:
    
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n%groupSize != 0)
            return false;

        unordered_map<int, int> map;

        for (auto& h: hand)
            map[h]++;

        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

        for (auto& it: map)
            pq.push({it.first, it.second});
        
        while (!pq.empty()){
            vector<pair<int, int>> temp;

            for (int i=0; i<groupSize; i++){
                if (!pq.empty()){
                    int curr = pq.top().first;
                    int freq = pq.top().second - 1;
                    pq.pop();

                    if (i > 0 && curr != (temp[i-1]).first + 1)
                        return false;

                    temp.push_back({curr, freq});
                }
                else if (i>0)
                    return false;
            }
        
            for (auto& it: temp){
                if (it.second > 0)
                    pq.push(it);
            }
        }

        return true;
    }
};
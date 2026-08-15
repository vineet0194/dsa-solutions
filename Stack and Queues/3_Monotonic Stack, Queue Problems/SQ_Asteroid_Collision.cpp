/*
Problem: 735. Asteroid Collision
Link: https://leetcode.com/problems/asteroid-collision/description/
Difficulty: Medium
Approach: Monotonic Stacks
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        int n = asteroids.size();

        for (int i=0; i<n; i++){
            int curr = asteroids[i];

            if (curr < 0){
                bool put = true;
                while (!st.empty() && st.top()>0){
                    int sum = st.top() + curr;
                    if (sum < 0)
                        st.pop();
                    else{
                        if (sum == 0)
                            st.pop();
                        put = false;
                        break;
                    }
                }

                if (put)
                    st.emplace(curr);
            }
            else if (curr > 0)
                st.emplace(curr);
        }

        vector<int> ans;

        while (!st.empty()){
            ans.emplace_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
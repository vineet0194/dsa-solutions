/*
Problem: 42. Trapping Rain Water
Link: https://leetcode.com/problems/trapping-rain-water/description/
Difficulty: Hard
Approach: Monotonic Stacks
Time Complexity: O(n)
Note:
    
*/

// BRUTE: O(n^2)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int ans = 0;
        for (int i=0; i<n; i++){
            int lbHeight = height[i];
            int rbHeight = height[i];
            for (int l=i; l>=0; l--){
                if (height[l] > lbHeight)
                    lbHeight = height[l];
            }
            for (int r=i; r<n; r++){
                if (height[r] > rbHeight)
                    rbHeight = height[r];
            }
            ans += min(lbHeight, rbHeight) - height[i];
        }

        return ans;
    }
};

// OPTIMAL, MAX ARRAY: O(3n)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n);
        leftMax[0] = height[0];

        for (int i=1; i<n; i++)
            leftMax[i] = max(height[i], leftMax[i-1]);
        
        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];

        for (int i=n-2; i>=0; i--)
            rightMax[i] = max(height[i], rightMax[i+1]);

        int ans = 0;
        for (int i=0; i<n; i++){
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }

        return ans;
    }
};

// ANOTHER OPTIMAL, 2P Approach: O(n)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int leftMax = -1, rightMax = -1, l = 0, r = n-1;

        int ans = 0;
        for (int i=0; i<n; i++){
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if (leftMax < rightMax){
                ans += leftMax - height[i];
                l++;
            }
            else{
                ans += rightMax - height[i];
                r--;
            }
        }

        return ans;
    }
};
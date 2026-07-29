/*
Problem: 2220. Minimum Bit Flips to Convert Number
Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
Difficulty: Easy
Approach: Bit Manipulation
Time Complexity: O(1)
Note:
    
*/

/*
 * count the number of differing bits
 */

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;

        for (int i=31; i>=0; i--){
            int ibit_start = (start >> i) & 1;
            int ibit_goal = (goal >> i) & 1;

            if (ibit_start != ibit_goal)
                ans++;
        }
        
        return ans;
    }
};

/*  ANOTHER METHOD:
 *  t = XOR of start and goal
 *  count the number of set bits in t 
 */
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int t = start^goal;
        int ans = 0;
        while (t > 0){
            ans += t%2;
            t /= 2;
        }
        return ans;
    }
};
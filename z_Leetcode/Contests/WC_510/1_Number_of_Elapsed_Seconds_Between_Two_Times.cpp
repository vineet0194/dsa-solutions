/*
Problem: Number of Elapsed Seconds Between Two Times©leetcode
Link: https://leetcode.com/contest/weekly-contest-510/problems/number-of-elapsed-seconds-between-two-times/
Difficulty: Easy
Approach: Time Conversion
Time Complexity: O(1)
Note:
    
*/

class Solution {
public:
    int getTime(int idx, string &str) {
        int time = 0;

        for (int i = 0; i < 2; i++) {
            time = time * 10 + (str[idx] - '0');
            idx++;
        }

        return time;
    }
    
    int totalSeconds(string &str) {
        int hours = getTime(0, str);
        int minutes = getTime(3, str);
        int seconds = getTime(6, str);

        return hours * 3600 + minutes * 60 + seconds;
    }
    
    int secondsBetweenTimes(string startTime, string endTime) {
        int start = totalSeconds(startTime);
        int end = totalSeconds(endTime);

        int diff = end - start;

        return diff;
    }
};
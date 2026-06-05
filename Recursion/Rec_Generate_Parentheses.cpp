/*
Problem: 22. Generate Parentheses
Link: https://leetcode.com/problems/generate-parentheses/
Difficulty: Medium
Approach: Recursive backtracking and solution set generation, then verification
Time Complexity: O(n*(2^n))
Note:
    
*/

class Solution {
public:
    bool isValidParenth(string curr){
        if (curr.size()==0)
            return false;

        int res=0, a=0, b=0;
        for (auto& ch: curr){
            if (res<0)
                return false;
            if (ch == '('){
                res++;
                a++;
            }
            else{
                res--;
                b++;
            }
        }
        if (res>=0 && a==b)
            return true;

        return false;
    }

    void func(vector<string>& ans, int realn, int n, string curr){
        if (n<1){
            if (isValidParenth(curr))
                ans.push_back(curr);
            return;
        }

        curr += "(";
        func(ans, realn, n-1, curr);
        curr.pop_back();
        curr += ")";
        func(ans, realn, n-1, curr);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func(ans, n, n*2, "");
        return ans;   
    }
};
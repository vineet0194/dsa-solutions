/*
Problem: Valid Binary Strings With Cost Limit
Link: https://leetcode.com/problems/valid-binary-strings-with-cost-limit/description/
Contest: Weekly Contest 505
Difficulty: Medium
Approach: DFS using recursion
Time Complexity: O(nx(2^n))
Note:
    generate all strings using recursion,
    filter out the valid ones
*/

class Solution {
public:
    void generateAllStrings(vector<string>& allStrings, int n, int i, string& currString){
        if (i == n){
            if (currString.size()==n)
            allStrings.emplace_back(currString);
            return;
        }
        currString += "0";
        generateAllStrings(allStrings, n, i+1, currString);
        currString.pop_back();
        currString += "1";
        generateAllStrings(allStrings, n, i+1, currString);
        currString.pop_back();
        return;
    }
    
    vector<string> generateValidStrings(int n, int k) {
        vector<string> allStrings;
        string currString="";
        generateAllStrings(allStrings, n, 0, currString);

        vector<string> ans;
        for (int i=0; i<allStrings.size(); i++){
            int cost=0;
            bool consOnes=false;
            for (int j=0; j<allStrings[i].size(); j++){
                if (j>0){
                    if (allStrings[i][j] == '1' && allStrings[i][j-1] == '1'){
                        consOnes = true;
                        break;
                    }
                }
                if (allStrings[i][j] == '1')
                    cost += j;
            }
            if (cost <= k && consOnes==false)
                ans.emplace_back(allStrings[i]);
        }

        return ans;
    }
};
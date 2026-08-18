/*
Problem: The Celebrity Problem
Link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
Difficulty: Medium
Approach: Stack based implementation
Time Complexity: O(n)
Note:
    Intuition
        - Put all people in a stack and compare two candidates at a time.
        - If A knows B, then A cannot be a celebrity; otherwise, B cannot be a celebrity.
        - Keep the remaining candidate and continue eliminating until only one is left.
        - Finally, verify that everyone knows the candidate and the candidate knows nobody.

    The key is: in every pair, we can prove that at least one person is definitely not a celebrity.
*/

// Brute Force, O(n^2)

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for (int i=0; i<n; i++){
            
            bool heKnowsNoOne = true;
            bool everyoneKnowsHim = true;
        
            int count = 0;
            for (int j=0; j<n; j++){
                count += mat[i][j];
                if (count > 1){
                    heKnowsNoOne = false;
                    break;
                }
            }
            
            if (!heKnowsNoOne)  continue;
        
            for (int j=0; j<n; j++){
                if (j != i && mat[j][i] == 0){
                    everyoneKnowsHim = false;
                    break;
                }
            }
            
            if (heKnowsNoOne && everyoneKnowsHim)
                return i;
            
        }
        
        return -1;
    }
};

// Optimal, O(n)

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        
        stack<int> st;
        
        for (int i=0; i<n; i++){
            st.emplace(i);
        }
        
        while (st.size() > 1){
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();
            
             // A does not know B, but B knows A => A "can" be a celebrity
            if (mat[A][B] == 0 && mat[B][A] == 1)
                st.emplace(A);
                
             // B does not know A, but A knows B => B "can" be a celebrity
            else if (mat[B][A] == 0 && mat[A][B] == 1)
                st.emplace(B);
        }
        
        if (st.empty())
            return -1;
        
        int TOP = st.top();
        st.pop();
        
        // everyone knows TOP
        for (int i=0; i<n; i++){
            if (i==TOP) continue;
            
            if (mat[i][TOP] == 0)
                return -1;
        }
        
        // TOP knows no one
        for (int i=0; i<n; i++){
            if (i==TOP) continue;
            
            if (mat[TOP][i] == 1)
                return -1;
        }
        
        return TOP;
    }
};
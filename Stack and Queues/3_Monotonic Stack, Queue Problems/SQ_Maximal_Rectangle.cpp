/*
Problem: 85. Maximal Rectangle
Link: https://leetcode.com/problems/maximal-rectangle/description/
Difficulty: Hard
Approach: Monotonic Stacks
Time Complexity: O(rows*cols))
Note:
    basically, Largest Rectangle in Histogram, combined with Height
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& inputMatrix) {
        int rows = inputMatrix.size();
        int cols = inputMatrix[0].size();

        stack<int> st;

        vector<vector<int>> matrix(rows, vector<int>(cols));

        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                if (inputMatrix[i][j] == '0')
                    matrix[i][j] = 0;
                else
                    matrix[i][j] = (i == 0 ? 1 : matrix[i-1][j] + 1);
            }
        }

        int maxArea = 0;

        for (int i=0; i<rows; i++){
            vector<int> pzero(cols);
            vector<int> nzero(cols);

            for (int j=cols-1; j>=0; j--){
                while (!st.empty() && matrix[i][st.top()] >= matrix[i][j])
                    st.pop();
                
                nzero[j] = st.empty() ? cols : st.top();
                st.emplace(j);
            }

            while (!st.empty())
                st.pop();

            for (int j=0; j<cols; j++){
                while (!st.empty() && matrix[i][st.top()] > matrix[i][j])
                    st.pop();
                
                pzero[j] = st.empty() ? -1 : st.top();
                st.emplace(j);
            }

            while (!st.empty())
                st.pop();

            for (int j=0; j<cols; j++){
                int width = nzero[j]-pzero[j]-1;
                maxArea = max(maxArea, width*matrix[i][j]);
            }
        }

        return maxArea;
    }
};
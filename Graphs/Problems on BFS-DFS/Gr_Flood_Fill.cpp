/*
Problem: 733. Flood Fill
Link: https://leetcode.com/problems/flood-fill/description/
Difficulty: Easy
Approach: BFS
Time Complexity: O(m*n)
Note:
    easy BFS
*/

class Solution {
public:
    bool isValidAndOgColor(pair<int, int>& move, vector<vector<int>>& image, int& ogColor){
        int i = move.first;
        int j = move.second;
        int m = image.size();
        int n = image[0].size();

        if (i<0 || i>=m || j<0 || j>=n || image[i][j]!=ogColor)
            return false;
        
        return true;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> newImage(image);

        int m = image.size();
        int n = image[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ogCol = image[sr][sc];

        queue<pair<int, int>> q;

        q.push({sr, sc});
        visited[sr][sc]=1;
        newImage[sr][sc]=color;
        
        int qsize=q.size();
        while (!q.empty()){
            qsize = q.size();
            for (int k=0; k<qsize; k++){
                int i = q.front().first;
                int j =q.front().second;
                q.pop();
                vector<pair<int, int>> moves={
                    {i-1, j},
                    {i+1, j},
                    {i, j-1},
                    {i, j+1},
                };
                for (auto& move : moves){
                    if (isValidAndOgColor(move, image, ogCol) && !visited[move.first][move.second]){
                        visited[move.first][move.second]=1;
                        newImage[move.first][move.second]=color;
                        q.push({move.first, move.second});
                    }
                }
            }
        }
        return newImage;
    }
};
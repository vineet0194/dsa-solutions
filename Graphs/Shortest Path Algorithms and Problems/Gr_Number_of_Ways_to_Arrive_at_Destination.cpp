/*
Problem: 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
Difficulty: Medium
Approach: DP (Floyd Warshall Algorithm)
Time Complexity: O(V^3)
Note:
    find all pair shortest distance
    for all cities, count the number of cities to which they are connected with at most the threshold distance
    return the minimum one, if >1 is the minimum then return the city with the greater number
            (this is why we used <= instead of < in our last loop while finding min)
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto& edge : edges){
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        for (int i=0; i<n; i++){
            dist[i][i] = 0;
        }

        for (int k=0; k<n; k++){
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        vector<int> cityDist(n, 0);
        for (int i=0; i<n; i++){
            int tempCount=0;
            for (int j=0; j<n; j++){
                if (i==j)
                    continue;
                if (dist[i][j] <= distanceThreshold)
                    tempCount++;
            }
            cityDist[i] = tempCount;
        }

        int min=0;
        for (int i=0; i<n; i++){
            if (cityDist[i] <= cityDist[min])
                min = i;
        }
        return min;
    }
};
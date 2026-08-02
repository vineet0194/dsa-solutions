/*
Problem: Check if an Array is Max Heap
Link: https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1
Difficulty: Easy
Approach: Heap Check
Time Complexity: O(logN)
Note:
    
*/

class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        int n = arr.size();
        
        for (int i=0; i<=(n/2)-1; i++){
            int leftIdx = 2*i + 1;
            int rightIdx = 2*i + 2;
            
            if (leftIdx < n && arr[i] < arr[leftIdx])
                return false;
            
            if (rightIdx < n && arr[i] < arr[rightIdx])
                return false;
        }
        
        return true;
    }
};

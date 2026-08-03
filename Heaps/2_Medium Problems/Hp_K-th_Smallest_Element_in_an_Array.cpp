/*
Problem: Kth Smallest Element in an Array
Link: https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
Difficulty: Medium
Approach: Heapify Algo
Time Complexity: O(N + klogN) => O(NlogN) worst case
Note:
    min heapify non-leaf nodes,
    delete root (k-1) times so that
        kth minimum is at the root after k-1 deletions
*/

// Heapify Algo

class Solution {
  public:
    void heapify(int i, vector<int>& arr){
        int n = arr.size();
        
        while (i < n){
            int leftChild = 2*i + 1;
            int rightChild = 2*i + 2;
            
            int smallest = i;
            
            if (leftChild < n && arr[smallest] > arr[leftChild])
                smallest = leftChild;
            
            if (rightChild < n && arr[smallest] > arr[rightChild])
                smallest = rightChild;
            
            if (smallest == i)
                break;
            
            swap(arr[i], arr[smallest]);
            i = smallest;
        }
    }
    
    void deleteFromHeap(vector<int>& arr){
        arr[0] = arr.back();
        arr.pop_back();
        
        heapify(0, arr);
    }
    
    int kthSmallest(vector<int> &arr, int k) {
        int n = arr.size();
        
        for (int i=n/2 -1; i>=0; i--)
            heapify(i, arr);
        
        for (int i=0; i<k-1; i++)
            deleteFromHeap(arr);
        
        return arr[0];
    }
};


// Using Priority Queue

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int n = arr.size();
        
        for (int i=0; i<n; i++)
            pq.push(arr[i]);
        
        for (int i=0; i<k-1; i++)
            pq.pop();
        
        return pq.top();
    }
};
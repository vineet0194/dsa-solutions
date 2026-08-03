/*
Problem: Heap Sort
Link: https://www.geeksforgeeks.org/problems/heap-sort/1
Difficulty: Medium
Approach: Heap Sort Algo
Time Complexity: O(N + NlogN)
Note:
    1. build max heap out of the array
    2. apply heap sort algo, how?
        i) init n = size of arr
        ii) while (n > 1){
                swap(root, last);
                n = n-1; (placed 1 elem => lower the bound now)
                heapify(root with bounded n)
            }
*/

class Solution {
  public:
    void heapify(int i, vector<int>& arr, int n){
        while (i<n){
            int leftChild = 2*i+1;
            int rightChild = 2*i+2;
            
            int largest = i;
            
            if (leftChild < n && arr[largest] < arr[leftChild])
                largest = leftChild;
            
            if (rightChild < n && arr[largest] < arr[rightChild])
                largest = rightChild;
            
            if (largest == i)
                break;
            
            swap(arr[i], arr[largest]);
            i = largest;
        }
    }
  
    void heapSort(vector<int>& arr) {
        int n = arr.size();
        
        for (int i=n/2 - 1; i>=0; i--)
            heapify(i, arr, n);
        
        while (n > 1){
            swap(arr[0], arr[n-1]);
            n--;
            heapify(0, arr, n);
        }
    }
};
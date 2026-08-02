/*
Problem: Convert Min Heap To Max Heap
Link: https://www.naukri.com/code360/problems/convert-min-heap-to-max-heap_1381084?leftPanelTabValue=PROBLEM
Difficulty: Medium
Approach: Heapify Algo
Time Complexity: O(n)
Note:
    
*/

void maxHeapify(int i, int& n, vector<int>& arr){
    while (i < n){
        int leftIdx = 2*i + 1;
        int rightIdx = 2*i + 2;

        int largest = i;

        if (leftIdx < n && arr[largest] < arr[leftIdx])
            largest = leftIdx;

        if (rightIdx < n && arr[largest] < arr[rightIdx])
            largest = rightIdx;
        
        if (largest == i)
            break;
        
        swap(arr[i], arr[largest]);
        i = largest;
    }
}

vector<int>MinToMaxHeap(int n, vector<int>&arr){
    
    for (int i=(n/2)-1; i>=0; i--)
        maxHeapify(i, n, arr);
    
    return arr;
}
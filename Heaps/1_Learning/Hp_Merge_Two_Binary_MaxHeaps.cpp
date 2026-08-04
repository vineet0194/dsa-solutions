/*
Problem: https://www.naukri.com/code360/problems/merge-two-binary-max-heaps_1170049?leftPanelTabValue=PROBLEM
Link: https://www.naukri.com/code360/problems/merge-two-binary-max-heaps_1170049?leftPanelTabValue=PROBLEM
Difficulty: Easy
Approach: Heaps
Time Complexity: O(m log(n + m))
Note:
    
*/

#include <bits/stdc++.h> 

void insertIntoHeap(int val, vector<int> &heap){
    heap.push_back(val);
    int i = heap.size() - 1;

    while (i>0){
        int parent = (i-1)/2;

        if (heap[parent] < heap[i]){
            swap(heap[parent], heap[i]);
            i = parent;
        }
        else
            break;
    }
}

vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    for (auto& num: arr2){
        insertIntoHeap(num, arr1);
    }
    return arr1;
}
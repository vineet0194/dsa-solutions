/*
Problem: Heap Introduction
Link: -
Difficulty: -
Approach: -
Time Complexity: -
Note:
    
*/

#include<bits/stdc++.h>
using namespace std;

// HEAPIFY (Max Heap)   =   O(logN)
// Build Heap (heapify all internal nodes): O(N)
void MaxHeapify(int i, vector<int>& arr){
    int n = arr.size();
   
    while (i < n){
        int leftIdx = 2*i;
        int rightIdx = 2*i + 1;

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

class MaxHeap{
public:
    vector<int> heap;

    MaxHeap(){
        heap.push_back(-1);
    }
    
    // INSERT   =   O(logN)
    // 1. Push element to the end
    // 2. Propagate the element to its right position
    void insertIntoHeap(int val){
        heap.push_back(val);

        int i = heap.size()-1;

        while (i>1){
            int parent = i/2;

            if (heap[parent] < heap[i]){
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
                return;
        }
    }

    // DELETE   =   O(logN)
    // 1. Move the last element to the root.
    // 2. Remove the last element.
    // 3. Heapify from the root. (0 for 0-based, 1 for 1-based)
    void deleteFromHeap(){
        if (heap.size() == 1)
            return;

        heap[1] = heap.back();
        
        heap.pop_back();

        MaxHeapify(1, heap);
    }

    void print(){
        for (int i=1; i<this->heap.size(); i++){
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    MaxHeap myMH = MaxHeap();

    myMH.insertIntoHeap(50);
    myMH.insertIntoHeap(55);
    myMH.insertIntoHeap(53);
    myMH.insertIntoHeap(52);
    myMH.insertIntoHeap(54);

    myMH.print();

    myMH.deleteFromHeap();

    myMH.print();

    vector<int> arr = {-1, 54, 53, 55, 52, 50};
    
    for (int i=arr.size()/2; i>0; i--){
        MaxHeapify(i, arr);
    }

    for (int i=1; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
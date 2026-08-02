/*
Problem: Min Heap implementation
Link: https://www.geeksforgeeks.org/problems/min-heap-implementation/1
Difficulty: Easy
Approach: Min Heap Implementation
Time Complexity:    Push/Pop/Heapify(i) => O(logN)
                    Peek/Size => O(1)
Note:
    
*/

class minHeap {
  private:
    vector<int> heap;

  public:
  
    void heapify(int i){
        int n = heap.size();
        
        while (i < n){
            int leftIdx = 2*i + 1;
            int rightIdx = 2*i + 2;
            int smallest = i;
            
            if (leftIdx < n && heap[smallest] > heap[leftIdx])
                smallest = leftIdx;
            
            if (rightIdx < n && heap[smallest] > heap[rightIdx])
                smallest = rightIdx;
            
            if (smallest == i)
                break;
            
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

    void push(int x) {
        heap.push_back(x);
        
        int i = heap.size()-1;
        
        while (i>0){
            int parent = (i-1)/2;
            
            if (heap[parent] > heap[i]){
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
                return;
        }
    }

    void pop() {
        if (heap.empty())
            return;
        
        heap[0] = heap.back();
        heap.pop_back();
        
        heapify(0);
    }

    int peek() {
        if (heap.empty())
            return -1;
        
        return heap[0];
    }

    int size() {
        return heap.size();
    }
};
/*
Problem: Max Heap implementation
Link: https://www.geeksforgeeks.org/problems/max-heap-implementation/1
Difficulty: Easy
Approach: Max Heap Implementation
Time Complexity:    Push/Pop/Heapify(i) => O(logN)
                    Peek/Size => O(1)
Note:
    
*/

class maxHeap {
  private:
    vector<int> heap;

  public:
  
    void heapify(int i){
        int n = heap.size();
        
        while (i < n){
            int leftIdx = 2*i + 1;
            int rightIdx = 2*i + 2;
            int largest = i;
            
            if (leftIdx < n && heap[largest] < heap[leftIdx])
                largest = leftIdx;
            
            if (rightIdx < n && heap[largest] < heap[rightIdx])
                largest = rightIdx;
            
            if (largest == i)
                break;
            
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    void push(int x) {
        heap.push_back(x);
        
        int i = heap.size()-1;
        
        while (i>0){
            int parent = (i-1)/2;
            
            if (heap[parent] < heap[i]){
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
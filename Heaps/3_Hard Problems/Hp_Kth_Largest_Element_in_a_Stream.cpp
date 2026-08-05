/*
Problem: 703. Kth Largest Element in a Stream
Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
Difficulty: Easy
Approach: Heaps
Time Complexity: 
                Constructor: O(nlogk)
                Insert: O(logk)
                Delete: O(logk)
                Heapify: O(logk)
Note:
    
*/

class KthLargest {
public:
    vector<int> heap;
    int k;

    void heapify(int i){
        int n = heap.size();
        while (i<n){
            int leftChild = 2*i + 1;
            int rightChild = 2*i + 2;

            int smaller = i;

            if (leftChild < n && heap[leftChild] < heap[smaller])
                smaller = leftChild;
            
            if (rightChild < n && heap[rightChild] < heap[smaller])
                smaller = rightChild;
            
            if (smaller == i)
                break;
            
            swap(heap[i], heap[smaller]);
            i = smaller;
        }
    }

    void insertIntoHeap(int val){
        heap.emplace_back(val);
        int i = heap.size()-1;

        while (i>0){
            int parent = (i-1)/2;

            if (heap[parent] > heap[i]){
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
                break;
        }
    }

    void deleteFromHeap(){
        if (heap.size() == 0)
            return;
        
        heap[0] = heap.back();
        heap.pop_back();

        heapify(0);
    }

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto& num : nums){
            if (heap.size() < k)
                insertIntoHeap(num);
            else if (num > heap.front()){
                deleteFromHeap();
                insertIntoHeap(num);
            }
        }
    }
    
    int add(int num) {
        if (heap.size() < k)
            insertIntoHeap(num);
        else if (num > heap[0]){
            deleteFromHeap();
            insertIntoHeap(num);
        }

        return heap[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
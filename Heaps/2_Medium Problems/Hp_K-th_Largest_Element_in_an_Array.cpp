/*
Problem: 215. Kth Largest Element in an Array
Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
Difficulty: Medium
Approach: Heapify Algo
Time Complexity: O(N + klogN) => O(NlogN) worst case
Note:
    max heapify non-leaf nodes,
    delete root (k-1) times so that
        kth largest is at the root after k-1 deletions
*/

class Solution {
public:    
    void heapify(int i, vector<int>& nums){
        int n = nums.size();
        while (i < n){
            int leftIdx = 2*i + 1;
            int rightIdx = 2*i + 2;
            int largest = i;
        
            if (leftIdx < n && nums[leftIdx] >= nums[largest])
                largest = leftIdx;
            
            if (rightIdx < n && nums[rightIdx] >= nums[largest])
                largest = rightIdx;
            
            if (largest == i)
                break;
            
            swap(nums[i], nums[largest]);
            i = largest;
        }
    }

    void deleteFromHeap(vector<int>& nums){
        nums[0] = nums.back();
        nums.pop_back();

        heapify(0, nums);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i=n/2 - 1; i>=0; i--)
            heapify(i, nums);

        for (int i=0; i<k-1; i++)
            deleteFromHeap(nums);

        return nums[0];
    }
};
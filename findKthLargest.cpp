// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

// priority queue - time complexity: O(n*log(k))
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        
        for(int num : nums) {
            pq.push(num);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        return pq.empty() ? -1 : pq.top();
    }
};

// quick select - time complexity: O(n) in the average case, O(n^2) in the worst case
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 0) {
            return -1;
        }
        
        // pick a random element as pivot
        int index = rand() % nums.size();
        int pivot = nums[index];
        
        vector<int> left; // elements greater than pivot
        vector<int> right; // elements less than or equal to pivot
        
        for(int i = 0;i < nums.size();i ++) {
            if(i == index) {
                continue;
            }
            
            if(nums[i] > pivot) {
                left.push_back(nums[i]);
            }
            else {
                right.push_back(nums[i]);
            }
        }
        
        // pivot is the kth largest element
        if(left.size() == k - 1) {
            return pivot;
        }
        
        return left.size() > k - 1 ? findKthLargest(left, k) : findKthLargest(right, k - left.size() - 1);
    }
};
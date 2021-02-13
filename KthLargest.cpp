// 703. Kth Largest Element in a Stream
// https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
private:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        
        for(int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K) {
            pq.pop();
        }
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
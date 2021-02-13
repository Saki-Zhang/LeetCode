// 295. Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> low; // max heap
    priority_queue<int, vector<int>, greater<int>> high; // min heap

public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        low.push(num);
        high.push(low.top());
        low.pop();
        
        if(low.size() < high.size()) {
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        if(low.empty()) {
            return -1;
        }
        
        if(low.size() == high.size()) {
            return (low.top() + high.top()) / 2.0;
        }
        
        return low.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

class cmp {
public:
    bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> cnt;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        
        for(int num : nums) {
            cnt[num] ++;
        }
        
        for(auto p : cnt) {
            pq.push(p);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        while(!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        return result;
    }
};
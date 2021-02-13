// 692. Top K Frequent Words
// https://leetcode.com/problems/top-k-frequent-words/

class cmp {
public:
    bool operator() (pair<string, int>& p1, pair<string, int>& p2) {
        if(p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        unordered_map<string, int> cnt;
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        
        for(string word : words) {
            cnt[word] ++;
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
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
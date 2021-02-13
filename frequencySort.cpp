// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/

// bucket sort
class Solution {
public:
    string frequencySort(string s) {
        string result = "";
        int n = s.length();
        
        unordered_map<char, int> cnt;
        vector<vector<char>> buckets (n + 1);
        
        for(char ch : s) {
            cnt[ch] ++;
        }
        
        for(auto p : cnt) {
            buckets[p.second].push_back(p.first);
        }
        
        for(int i = n;i > 0;i --) {
            for(char ch : buckets[i]) {
                result.append(i, ch);
            }
        }
        
        return result;
    }
};

// priority queue
class cmp {
public:
    bool operator() (pair<char, int>& p1, pair<char, int>& p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        string result = "";
        
        unordered_map<char, int> cnt;
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        
        for(char ch : s) {
            cnt[ch] ++;
        }
        
        for(auto p : cnt) {
            pq.push(p);
        }
        
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            
            result.append(p.second, p.first);
        }
        
        return result;
    }
};
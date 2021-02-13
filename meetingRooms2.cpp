// 253. Meeting Rooms II
// https://leetcode.com/problems/meeting-rooms-ii/

class Solution {
public:
    static bool cmp(vector<int>& u, vector<int>& v) {
        return u[0] < v[0];
    }
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        
        // use a min heap to keep track of the ending times
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto itv : intervals) {
            // update the ending time when an old meeting room is free
            // otherwise, open a new meeting room
            
            if(!pq.empty() && pq.top() <= itv[0]) {
                pq.pop();
            }
            pq.push(itv[1]);
        }
        
        return pq.size();
    }
};
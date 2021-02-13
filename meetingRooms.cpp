// 252. Meeting Rooms
// https://leetcode.com/problems/meeting-rooms/

class Solution {
public:
    static bool cmp(vector<int>& u, vector<int>& v) {
        return u[0] < v[0];
    }
    
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        
        for(int i = 1;i < intervals.size();i ++) {
            if(intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        
        return true;
    }
};
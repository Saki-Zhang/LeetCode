// 630. Course Schedule III
// https://leetcode.com/problems/course-schedule-iii/

class Solution {
public:
    static bool cmp(vector<int>& u, vector<int>& v) {
        return u[1] < v[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp); // sort the courses by their end days
        
        priority_queue<int> pq; // max heap: the course with the longest duration will be at the top
        int day = 0; // number of days needed to take courses in the priority queue
        
        for(auto c : courses) {
            if(day + c[0] <= c[1]) {
                pq.push(c[0]);
                day += c[0];
            }
            else {
                pq.push(c[0]);
                day += c[0];
                day -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};
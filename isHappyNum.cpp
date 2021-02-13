// 202. Happy Number
// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        
        while(n != 1) {
            if(visited.find(n) != visited.end()) {
                return false;
            }
            
            visited.insert(n);
            
            int tmp = n;
            int sum = 0;
            
            while(tmp != 0) {
                sum += (tmp % 10) * (tmp % 10);
                tmp /= 10;
            }
            
            n = sum;
        }
        
        return true;
    }
};
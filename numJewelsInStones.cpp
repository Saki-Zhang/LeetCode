// 771. Jewels and Stones
// https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s (jewels.begin(), jewels.end());
        int cnt = 0;
        
        for(char ch : stones) {
            if(s.find(ch) != s.end()) {
                cnt ++;
            }
        }
        
        return cnt;
    }
};
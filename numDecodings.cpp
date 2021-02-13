// 91. Decode Ways
// https://leetcode.com/problems/decode-ways/

// recursion with memoization - time complexity: O(n)
class Solution {
public:
    int numDecodings(string s) {
        if(s == "") {
            return 0;
        }
        
        unordered_map<string, int> ways;
        ways[""] = 1;
        
        return numDecodings(s, ways);
    }
    
    int numDecodings(string s, unordered_map<string, int>& ways) {
        if(ways.find(s) != ways.end()) {
            return ways[s];
        }
        
        if(s[0] == '0') {
            return ways[s] = 0;
        }
        
        if(s.length() == 1) {
            return ways[s] = 1;
        }
        
        int num = stoi(s.substr(0, 2));
        
        int w1 = numDecodings(s.substr(1), ways); // decode one digit
        int w2 = num <= 26 ? numDecodings(s.substr(2), ways) : 0; // decode two digits
        
        return ways[s] = w1 + w2;
    }
};

// dynamic programming - time complexity: O(n)
class Solution {
public:
    int numDecodings(string s) {
        if(s == "" || s[0] == '0') {
            return 0;
        }
        
        vector<int> ways (s.length() + 1, 0); // number of ways to decode the first i digits
        ways[0] = ways[1] = 1;
        
        for(int i = 2;i <= s.length();i ++) {
            int num = stoi(s.substr(i - 2, 2));
            
            int w1 = s[i - 1] != '0' ? ways[i - 1] : 0;
            int w2 = s[i - 2] != '0' && num <= 26 ? ways[i - 2] : 0;
            
            ways[i] = w1 + w2;
        }
        
        return ways.back();
    }
};
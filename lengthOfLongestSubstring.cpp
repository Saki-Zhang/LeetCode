// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// hashset
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        
        unordered_set<char> window; // current substring without duplicate characters
        int l = 0; // left boundary of the sliding window
        int r = 0; // right boundary of the sliding window
        
        while(r < s.length()) {
            // keep removing the leftmost character until the current character is not in the window
            while(window.find(s[r]) != window.end()) {
                window.erase(s[l]);
                l ++;
            }
            
            // add the current character into the window
            window.insert(s[r]);
            r ++;
            result = max(result, r - l);
        }
        
        return result;
    }
};

// hashmap
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        
        unordered_map<char, int> pos; // store the last position of the characters
        int l = 0; // left boundary of the sliding window
        int r = 0; // right boundary of the sliding window
        
        while(r < s.length()) {
            if(pos.find(s[r]) != pos.end()) {
                l = max(l, pos[s[r]] + 1);
            }
            
            pos[s[r]] = r;
            r ++;
            result = max(result, r - l);
        }
        
        return result;
    }
};
// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> groups;
        
        for(string str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            groups[tmp].push_back(str);
        }
        
        for(auto g : groups) {
            result.push_back(g.second);
        }
        
        return result;
    }
};
// 320. Generalized Abbreviation
// https://leetcode.com/problems/generalized-abbreviation/

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        generate(word, 0, 0, "", result);
        return result;
    }
    
    void generate(string word, int pos, int cnt, string curr, vector<string>& result) {
        string num = cnt == 0 ? "" : to_string(cnt);
        
        if(pos == word.length()) {
            result.push_back(curr + num);
            return;
        }
        
        generate(word, pos + 1, 0, curr + num + word[pos], result); // keep the current character
        generate(word, pos + 1, cnt + 1, curr, result); // abbreviate the current character
    }
};
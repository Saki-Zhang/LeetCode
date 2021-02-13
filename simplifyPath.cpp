// 71. Simplify Path
// https://leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        string short_path = "";
        stack<string> s;
        
        for(int i = 1, j = 1;i <= path.length();i ++) {
            if(i == path.length() || path[i] == '/') {
                string dir = path.substr(j, i - j);
                j = i + 1;
                
                if(dir == "" || dir == ".") {
                    continue;
                }
                else if(dir == "..") {
                    if(!s.empty()) {
                        s.pop();
                    }
                }
                else {
                    s.push(dir);
                }
            }
        }
        
        if(s.empty()) {
            return "/";
        }
        
        while(!s.empty()) {
            string dir = s.top();
            s.pop();
            short_path = "/" + dir + short_path;
        }
        
        return short_path;
    }
};
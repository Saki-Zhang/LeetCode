// 535. Encode and Decode TinyURL
// https://leetcode.com/problems/encode-and-decode-tinyurl/

class Solution {
private:
    string s = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string prefix = "http://tinyurl.com/";
    unordered_map<string, string> m;

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = randStr();
        
        while(m.find(key) != m.end()) {
            key = randStr();
        }
        
        m[key] = longUrl;
        string shortUrl = prefix + key;
        
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string key = shortUrl.substr(prefix.length());
        string longUrl = m[key];
        
        return longUrl;
    }
    
    string randStr() {
        string key = "";
        
        for(int i = 0;i < 6;i ++) {
            key += s[rand() % s.length()];
        }
        
        return key;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
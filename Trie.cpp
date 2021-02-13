// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode {
public:
    TrieNode* next[26];
    bool is_end;

public:
    TrieNode() {
        memset(next, 0, sizeof(next));
        is_end = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        
        for(char ch : word) {
            if(curr -> next[ch - 'a'] == NULL) {
                curr -> next[ch - 'a'] = new TrieNode();
            }
            curr = curr -> next[ch - 'a'];
        }
        
        curr -> is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        
        for(char ch : word) {
            if(curr -> next[ch - 'a'] == NULL) {
                return false;
            }
            curr = curr -> next[ch - 'a'];
        }
        
        return curr -> is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        
        for(char ch : prefix) {
            if(curr -> next[ch - 'a'] == NULL) {
                return false;
            }
            curr = curr -> next[ch - 'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
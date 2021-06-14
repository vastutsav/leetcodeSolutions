class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for (auto w:word) {
            if (!node->next.count(w))
                node->next[w] = new Trie();
            node = node->next[w];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for (auto w:word) {
            if (!node->next.count(w))
                return false;
            node = node->next[w];
        }
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for (auto w:prefix) {
            if(!node->next.count(w)) {
                return false;
            }
            node = node->next[w];
        }
        return true;
    }
private:
    unordered_map <int, Trie*> next = {};
    bool isWord = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
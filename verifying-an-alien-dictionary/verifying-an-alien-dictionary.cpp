class Solution {
private:
    unordered_map <char,int> um;
    
    int myStrcmp(string a, string b) {
        int aL = a.length();
        int bL = b.length();
        int minL = min(aL, bL);
        
        for (int i = 0; i < minL; ++i) {
            if (a[i] != b[i])
                return um[a[i]] - um[b[i]];
        }
        
        if (aL > bL)
            return 1;
        else
            return -1;
            
        
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        int i = 0;
        for(auto c:order)
            um[c] = i++;
        
        for (int i = 0; i < words.size() - 1 ; ++i){
            if (myStrcmp(words[i], words[i+1]) > 0)
                return false;
        }
        
        return true;
        
    }
};
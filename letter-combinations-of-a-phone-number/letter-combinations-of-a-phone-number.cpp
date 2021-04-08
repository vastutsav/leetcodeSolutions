class Solution {
private:
    const vector<string> pad = {
        "", 
        "", "abc", "def",
        "ghi", "jkl", "mno", 
        "pqrs", "tuv", "wxyz"
    };
    
public:
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        
        vector <string> res;
        res.push_back("");
        
        for (auto digit:digits) {
            vector <string> tmp;
            for (auto alphabet:pad[digit - '0']) {
                for (auto s:res) {
                    tmp.push_back(s+alphabet);
                }
            }
            res.swap(tmp);
        }
        
        return res;
    }
};
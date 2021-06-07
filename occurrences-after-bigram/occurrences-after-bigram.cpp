class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        
        stringstream s(text);
        vector <string> ans;
        vector <string> words;
        string temp;
        while (s >> temp) {
            words.push_back(temp);
        }
        for (int i = 0; i < words.size() - 2; ++i) {
            if (words[i] == first && words[i+1] == second)
                ans.push_back(words[i+2]);
        }
        return ans;
    }
};
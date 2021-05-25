class Solution {
public:
    const int x = 32;
    string toLowerCase(string s) {
        for (int i = 0; i < s.length(); ++i)
            s[i] = tolower(s[i]);
        return s;
    }
};
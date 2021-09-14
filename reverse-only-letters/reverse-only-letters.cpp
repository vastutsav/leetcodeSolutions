class Solution {
public:
    string reverseOnlyLetters(string s) {
        int sz = s.size();
        
        int i = 0, j = sz - 1;

        while(1) {
            
            while (i < sz && !isalpha(s[i])) {
                ++i;
            }
            while (j >= 0 && !isalpha(s[j])) {
                --j;
            }
            if ( i >= j )
                break;
            
            swap(s[i], s[j]);

            ++i;
            --j;

            if ( i >= j)
                break;
        }
        
        return s;
    }
};
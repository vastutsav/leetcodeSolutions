class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int nd = 0, np = 0;
        for (i = 0; i < s.length(); ++i)
            if (s[i] != ' ')
                break;
        
                
        if (s[i] == '+' || s[i] == '-') ++i;
        
        for (;(s[i] >= '0' && s[i] <= '9') || s[i] == '.';++i) {
            if (s[i] == '.')
                np++;
            else
                nd++;
        }
        
        if (np > 1 || nd < 1)
            return false;
        
        if (s[i] == 'e' || s[i] == 'E') {
            ++i;
            if (s[i] == '+' || s[i] == '-')
                ++i;
            
            int end = 0, enp = 0;
            for (;(s[i] >= '0' && s[i] <= '9') || s[i] == '.';++i){
                if (s[i] == '.')
                    enp++;
                else
                    end++;
            }
            if (enp > 0 || end < 1)
                return false;
        }
        
        return s[i] == 0;
    }
};
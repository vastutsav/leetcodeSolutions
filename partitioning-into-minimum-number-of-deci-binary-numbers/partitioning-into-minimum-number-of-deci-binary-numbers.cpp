class Solution {
public:
    int minPartitions(string n) {
        int m = 0, i;
        for (auto c:n) {
            if ((i = c - '0') > m)
                m = i;
        }
        return m;
    }
};
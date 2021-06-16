class Solution {
    void paraGen(vector <string> &result, string str, int left, int right) {
        if (!left && !right){
            result.push_back(str);
        } else {
            if (left > 0) {
                paraGen(result, str + "(", left - 1, right + 1);
            }
            if (right > 0) {
                paraGen(result, str + ")", left, right - 1);
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector <string> result;
        paraGen(result, "", n, 0);
        return result;
    }
};
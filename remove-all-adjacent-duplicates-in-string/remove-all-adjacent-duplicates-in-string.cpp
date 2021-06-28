class Solution {
public:
    string removeDuplicates(string s) {
        stack <int> st;
        string ans = "";
        
        for (auto c:s) {
            bool found = false;
            if (st.size() != 0) {
                char ch = st.top();
                if (c==ch) {
                    st.pop();
                    found = true;
                }
            }
            if (!found)
                st.push(c);
        }
        while (st.size()) {
            //ans.push_back(st.top());
            char c = st.top();
            ans = c + ans;
            st.pop();
        }
        
        return ans;
    }
};
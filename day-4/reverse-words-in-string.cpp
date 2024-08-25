

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i = 0;
        int n = s.size();
        string temp = "";
        while (i < n) {
            if (s[i] == ' ') {
                if (!temp.empty()) {
                    st.push(temp);
                    temp = "";
                }
            } else{
                temp += s[i];
            }
            i++;
        }
        if (!temp.empty())
            st.push(temp);
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) {
                ans += " ";
            }
        }
        return ans;
    }
};

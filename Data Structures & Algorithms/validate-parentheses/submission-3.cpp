class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> paran;
        paran[')'] = '(';
        paran[']'] = '[';
        paran['}'] = '{';

        stack<char> st;

        for(char c : s){
            if (c == '(' || c == '[' || c== '{') st.push(c);
            else{
                if (st.empty()) return false;
                char match = st.top();
                st.pop();
                if (match != paran[c]) return false;
            }
        }
        if (st.empty()) return true;
        return false;
    }
};

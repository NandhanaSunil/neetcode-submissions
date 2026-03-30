class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        unordered_map <char, char> paran;
        paran[')'] = '(';
        paran[']'] = '[';
        paran['}'] = '{';
        for (char c : s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else{
                if (st.empty()) return false;
                char popped = st.top();
                st.pop();
                if (popped != paran[c]) return false;

            }
        }
        if (st.empty()) return true;
        return false;
    }
};

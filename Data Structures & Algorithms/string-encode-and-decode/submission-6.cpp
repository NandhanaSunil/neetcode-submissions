class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(string st : strs){
            s = s + '#' + to_string(st.size()) + '#' + st;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i<s.size()){
            int j = i+1;
            while(s[j] != '#') j++;
            int wordlen = stoi(s.substr(i+1,j-i-1));
            res.push_back(s.substr(j+1,wordlen));
            i=j+wordlen+1;
        }
        return res;
    }
};

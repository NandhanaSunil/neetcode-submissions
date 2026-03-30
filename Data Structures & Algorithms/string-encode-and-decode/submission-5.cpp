class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s : strs){
            res += to_string(s.size()) + '#' + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> res;
        while(i<s.size()){
            int start = i;
            while(i<s.size() && s[i] != '#'){
                i++;
            }
            int len = stoi(s.substr(start, i-start));
            i++;
            res.push_back(s.substr(i, len));
            i+=len;
        }
        return res;
    }
};

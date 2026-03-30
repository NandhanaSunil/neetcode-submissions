class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (string s: strs){
            res += to_string(s.size()) + '#' + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> res;
        while (i<s.size()){
            string num = "";
            while(s[i] != '#'){
                num += s[i];
                i++;
            }
            i++;
            int numchar = stoi(num);
            string w = "";
            for (int j=0; j<numchar; j++){
                w += s[i];
                i++;
            }
            res.push_back(w);
        }
        return res;
    }
};

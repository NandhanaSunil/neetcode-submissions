class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s : strs){
            int n = s.size();
            res = res + to_string(n) + '#' + s;
        }
        cout << res << endl;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i<s.size()){
            string num = "";
            int start = i;
            while(s[i]!='#'){
                num = num + s[i];
                i++;
            }
            int n = stoi(num);
            cout << num << endl;
            i++;
            res.push_back(s.substr(i, n));
            i+=n;
        }
        return res;
    }
};

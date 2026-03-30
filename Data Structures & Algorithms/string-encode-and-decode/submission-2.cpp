class Solution {
public:

    string encode(vector<string>& strs) {
        string e = "";
        for (string s : strs){
            int len = s.size();
            e += to_string(len) + "#" + s;
        }
        cout << e <<endl;
        return e;
    }

    vector<string> decode(string s) {
        int len = s.size();
        int i = 0;
        vector<string> res;
        while(i<len){
            string numchars = "";
            while(s[i]!='#'){
                numchars += s[i];
                i++;
            }
            i++;
            int j=0;
            int wordlen = stoi(numchars);
            string word = "";
            while(j<wordlen){
                word += s[i];
                j++;
                i++;
            }
            res.push_back(word);
        }
        return res;
    }
};

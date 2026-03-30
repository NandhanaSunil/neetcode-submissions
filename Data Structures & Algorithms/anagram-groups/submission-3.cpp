class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anaMap;
        for (string s : strs){
            unordered_map<char, int> charCount;
            for (char c: s){
                charCount[c]++;
                cout << c << " " << charCount[c] << endl;
            }
            string key = "";
            for(int i=0; i<26; i++){
                if(charCount.count('a'+i)) {
                    key += char('a'+i) + to_string(charCount['a'+i]);
                }
                else key += '0';
            }
            cout << key << endl;
            anaMap[key].push_back(s);
        }
        vector<vector<string>> res;
        for(const auto &p: anaMap){
            res.push_back(p.second);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anamap;
        for(string s: strs){
            vector<int> freq(26);
            for (char c: s){
                freq[c -'a']++;
            }
            string key = "";
            for(int i=0; i<26; i++){
                if(freq[i]){
                    char keychar = 'a' + i;
                    string freqnum = to_string(freq[i]);
                    key = key + '#'+  keychar + '#' + freqnum;
                    }
            }

            anamap[key].push_back(s);
        }

        vector<vector<string>> res;
        for(const auto &p : anamap) res.push_back(p.second);
        return res;
    }
};

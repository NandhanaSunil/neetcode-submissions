class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrammap;
        for(string s : strs){
            unordered_map<char, int> charmap;
            for(char c: s){
                charmap[c]++;
            }
            string key = "";
            for(int i=0; i<26; i++){
                char c = 'a'+ i;
                if(charmap.find(c) !=charmap.end()){
                    key = key + c + to_string(charmap[c]);
                }
            }

            anagrammap[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto &p : anagrammap){
            res.push_back(p.second);
        }
        return res;
    }
};

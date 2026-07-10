class Solution {
public:
    string constructString(vector<int>& charscount){
        string s;
        for(int n: charscount){
            s = s + char('a' + n);
        }
        return s;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> charsmap;

        for(string word : strs){
            vector<int> chars(26,0);
            for(char c: word) chars[c-'a']++;
            string keystr = constructString(chars);
            charsmap[keystr].push_back(word);
        }
        vector<vector<string>> result;
        for(const auto&p : charsmap) result.push_back(p.second);
        return result;
    }
};

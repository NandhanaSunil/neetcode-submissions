class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> charMap;
        int numWords = strs.size();
        for(int i=0; i<numWords; i++){
            unordered_map<char, int> charCount;
            for(int i=0; i<26; i++){
                charCount['a'+i] =0;
            }
            string word = strs[i];
            for (int j=0; j<word.size(); j++){
                charCount[word[j]]++;
            }
            string key = "";
            for(int k=0; k<26; k++){
                key += to_string(charCount['a'+k]) + ",";
            }
            charMap[key].push_back(word);
        }
        vector<vector<string>> result;
        for (auto const& [key, val] : charMap) {
            result.push_back(val);
        }
        return result;
    }
};

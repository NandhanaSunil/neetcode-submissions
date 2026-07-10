class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> charset;
        for (char c: s){
            charset[c]++;
        }
        for(char c: t) charset[c]--;
        for(const auto&p : charset){
            if(p.second)return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> charmap;
        for(char c : s) charmap[c]++;
        for(char c : t) charmap[c]--;
        for(char c : s){
            if(charmap[c]) return false;
        }
        return true;
    }
};

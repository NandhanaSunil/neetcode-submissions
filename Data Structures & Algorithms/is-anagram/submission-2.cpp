class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charcount;
        if (s.size() != t.size()) return false;
        for(char c: s){
            charcount[c]++;
        }
        for (char c: t){
            charcount[c]--;
        }
        for (const auto&p : charcount){
            if(p.second != 0) return false;
        }
        return true;
    }
};

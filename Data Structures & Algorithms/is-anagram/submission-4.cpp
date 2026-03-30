class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charmap;
        for(char c : s){
            charmap[c]++;
        }
        for(char c : t){
            charmap[c]--;
        }
        for(auto &p : charmap){
            if(p.second) return false;
        }
        return true;
    }
};

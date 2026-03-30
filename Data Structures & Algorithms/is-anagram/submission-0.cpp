class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> anagram;
        int sLen = s.size();
        int tLen = t.size();
        if (sLen != tLen) return false;
        for (int i = 0; i<sLen; i++){
            anagram[s[i]] = 0;
        } 
        for (int i=0; i<sLen; i++){
            anagram[s[i]]++;
        }
        for (int i=0; i<tLen; i++){
            if (anagram.find(t[i]) != anagram.end()) anagram[t[i]]--;
            else return false;
        }
        for (int i=0; i<tLen; i++){
           if (anagram[s[i]] != 0) return false;
        }
        return true;
    }
};

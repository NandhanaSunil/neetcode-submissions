class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charCount;
        int sLen = s.size();
        int tLen = t.size();
        if (sLen != tLen) return false;
        for (int i =0; i<sLen; i++){
            charCount[s[i]]++;
        }
        for (int i =0; i<sLen; i++){
            charCount[t[i]]--;
        }
        for (int i =0; i<sLen; i++){
            if (charCount[s[i]]!= 0) return false;
        }
        return true;
    }
};

class Solution {
public:
    unordered_map<char, string> digitmap;
        
    vector<string> res;
    void dfs(int i, string digits, string word){
        if(i == digits.size()) {
            res.push_back(word);
            return;
            }
        char c = digits[i];
        string chars = digitmap[c];
        for(char s : chars){
            dfs(i+1, digits, word + s);
        }


    }
    vector<string> letterCombinations(string digits) {
        if (digits == "") return res;
        digitmap['2'] = "abc";
        digitmap['3'] = "def";
        digitmap['4'] = "ghi";
        digitmap['5'] = "jkl";
        digitmap['6'] = "mno";
        digitmap['7'] = "pqrs";
        digitmap['8'] = "tuv";
        digitmap['9'] = "wxyz";

        dfs(0, digits, "");
        return res;
    }
};

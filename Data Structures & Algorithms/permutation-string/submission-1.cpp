class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map <char, int> s;
        for (char c : s1){
            s[c]++;
        }
        int len = s1.size();
        int i = 0;
        int l = 0;
        while ( i < s2.size()){
            char c = s2[i];
            if(s.count(c)){
                int added = 0;
                unordered_map <char, int> f;
                int ind = i;
                while (ind<s2.size() && (added < len)){
                    f[s2[ind]]++;
                    ind++;
                    added++;
                }
                if(added == len){
                    bool flag = true;
                    for (char d : s1){
                        if(f.find(d) == f.end() || (f[d] != s[d])){
                            flag = false;
                            i++;
                            break;
                        }
                    }
                    if(flag) return true;
                }
                else return false;
            }
            else i++;
        }
        return false;
    }
};

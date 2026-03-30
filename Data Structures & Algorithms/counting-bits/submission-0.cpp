class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; i++){
            int c =0;
            int num = i;
            while(num){
                c += num%2;
                num = num >> 1;
            }
            res.push_back(c);
        }
        return res;
    }
};

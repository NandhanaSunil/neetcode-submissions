class Solution {
public:
    int getSum(int n){
        int res = 0;
        while(n>=10){
            int dig = n%10;
            res += dig*dig;
            n = n/10;
            // cout << res << ": n : " << n << endl;
        }
        res += n*n;
        // cout << " res : " << res << endl;
        return res;
    }
    bool isHappy(int n) {
        unordered_set <int> seen;
        while(n > 1){
            n = getSum(n);
            cout << n << endl;
            if(seen.count(n)) return false;
            seen.insert(n);
        }
        if (n == 1) return true;
    }
};

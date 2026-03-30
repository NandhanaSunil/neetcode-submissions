class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(1){
            if(n==1) return true;
            int sum = 0;
            while(n>0){
                int dig = n % 10;
                sum += dig*dig;
                n = n/10;
            }
            cout << sum << endl; 
            n = sum;
            if(seen.find(n) != seen.end()) return false;
            seen.insert(sum);
        }
        return false;
    }
};

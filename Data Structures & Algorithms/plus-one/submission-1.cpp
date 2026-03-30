class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = digits.size() - 1;
        if(digits[last]<9){
            digits[last]+=1;
            return digits;
        }
        else{
            int i=last;
            int inc = 0;
            while(i>=0){
                digits[i]++;
                inc = digits[i]/10;
                cout << i << " " << inc << endl;
                if(!inc){
                    return digits;
                    }
                digits[i] = digits[i] % 10;
                i--;
            }
            vector<int> res(digits.size()+1, 0);
            res[0] = 1;
            return res;
        }
    }
};

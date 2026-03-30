class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            bool k = n & 1;
            if(k)count++;
            n = n >> 1;
        }
        return count;
    }
};

class Solution {
public:
    int dfs(int n, int i){
        if(i>=n)return i==n;
        return (dfs(n,i+1) + dfs(n, i+2));
    }
    int climbStairs(int n) {
        vector<int> dfsarr(n, 0);
        dfsarr[0] = 1;
        dfsarr[1] = 2;
        int i = 2;
        while(i<n){
            dfsarr[i] = dfsarr[i-1] + dfsarr[i-2];
            i++;
        }
        return dfsarr[n-1];
        
    }
};

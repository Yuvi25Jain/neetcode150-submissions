class Solution {
public:

    int helper_fun(vector<int>& a, int n , int i , int free, vector<vector<int>>&dp){
        if(i == n) return 0 ;
        if(dp[i][free]!= -1){
            return dp[i][free];
        }
        if(free == 0){
            return dp[i][free] = helper_fun(a,n,i+1,1,dp);
        }
        int c1 = a[i]+helper_fun(a,n,i+1,0,dp);
        int c2 = helper_fun(a,n,i+1,1,dp);
        return dp[i][free] = max(c1,c2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n);
        for(int i =  0 ; i<n ; i++){
            vector<int>t(2,-1);
            dp[i] = t;
        }
        return helper_fun(nums,n,0,1,dp);
        
    }
};

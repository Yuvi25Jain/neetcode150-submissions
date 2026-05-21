class Solution {
   public:
    unordered_map<int, int> dp;  // or vector<int>dp(n)
    int climbStairs_Helper(int i, int n) {
        if (i == n) {
            return 1;
        }
        if (i > n) {
            return 0;
        }

        if (dp.find(i) != dp.end()) {
            return dp[i];
        }
        int a1 = climbStairs_Helper(i + 1, n);
        int a2 = climbStairs_Helper(i + 2, n);
        dp[i] = a1 + a2;

        return dp[i];
    }
    int climbStairs(int n) { 
        return climbStairs_Helper(0, n); 
        }
};

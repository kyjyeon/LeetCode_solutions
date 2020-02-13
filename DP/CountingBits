//Reference
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        dp[0] = 0;
        for (int i = 1; i <= num; i++) {
            dp[i] = dp[i>>1] + i % 2; //dp[i] = shifting i once to right side + i mod 2;
        }
        return dp;
    }
};

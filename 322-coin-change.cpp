//https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        if(amount == 0)
            return amount;

        vector<long> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int a = 0; a <= amount; a++){
            for(int index = 0; index < coins.size(); index++){
                if(a >= coins[index])
                dp[a] = min(dp[a], 1+dp[a-coins[index]]);
            }
        }

        if(dp[amount] == INT_MAX)
            return -1;

        return dp[amount];
    }
};

// Extra testcases:
// [186,419,83,408]
// 6249
// [1,2147483647]
// 2
// [1,1]
// 2
// [2,5,10,1]
// 27
// [474,83,404,3]
// 264
// [1,4,5]
// 8

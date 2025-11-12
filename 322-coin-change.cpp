//https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        sort(coins.begin(), coins.end());

        vector<long> v(amount+1, INT_MAX);

        for(int a=0; a<=amount; a++){
            if(a%coins[0] == 0){
                v[a] = a/coins[0];
            }
        }

        for(int i=1; i<coins.size(); i++){
            for(int a=0; a<=amount; a++){
                if(a-coins[i] >= 0){
                    v[a] = min((1 + v[a-coins[i]]), v[a]);
                }
            }
        }

        return (v[amount] == INT_MAX)? -1: v[amount];
    }
};




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
// [1,2,5]
// 100
// [186,419,83,408]
// 6249
// [3,7,405,436]
// 8839
// [176,6,366,357,484,226,1,104,160,331]
// 5557
// [19,28,176,112,30,260,491,128,70,137,253]
// 8539
// [370,417,408,156,143,434,168,83,177,280,117]
// 9953
// [2,4,6,8,10,12,14,16,18,20,22,24]
// 9999
// [2,4,6]
// 9999
// [1448861204]
// 0
// [29,29,17]
// 841
// [3,31,13,59]
// 1209
// [37,2,43,31]
// 3182
// [1495,598,2990,299]
// 5382
// [2680,5360,536,1072]
// 9648
// [7,2,14,28,73,132,220,343,518,734,1010,1337]
// 9999
// [5,11,8,30,72,129,223,349,513,739,1005,1334]
// 9951

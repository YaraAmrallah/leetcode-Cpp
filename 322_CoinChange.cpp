/*

You are given coins of different denominations and a total amount of money amount.
Write a function to compute the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1

*/


#define INF 32767

class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int coinsSize = coins.size();
        if(coinsSize == 0) return -1;
        if(amount <= 0) return 0;

        int value[amount + 1] = {0};

        for(int i = 1; i <= amount; i++)
        {
            value[i] = INF;

            for(auto c : coins)
            {
                if(i-c >= 0)
                value[i] = min(value[i],value[i-c]+1);
            }
        }

        if(value[amount] != INF) return value[amount];
        return -1;
    }
};

/*{1,2,5}

    10


        value[11]
        value[0] = 0;
        value[1] = 1
            min(value[1], value[1-1] + 1)
            min(INF, 1)
        value[2] = 1
            min(value[2], value[2-1]+1)
            min(INF, 2) = 2
            min(value[2], value[2-2]+1)
            min(2,1) = 1*/

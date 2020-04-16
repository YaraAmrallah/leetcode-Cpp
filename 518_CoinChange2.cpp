#define INF 32767

class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int coinsSize = coins.size();
        if(amount == 0) return 1;
        if(coinsSize == 0) return 0;
        if(amount < 0) return 0;

        int numberOfWays[amount + 1] = {0};
        numberOfWays[0] = 1;


        for(auto c : coins)
        {
            for(int i = 1; i <= amount; i++)
            {
                if(i-c >= 0)
                numberOfWays[i] += numberOfWays[i-c];
            }
        }

        return numberOfWays[amount];

    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unsigned int vectorSize = nums.size();
        unordered_map<int,int> numberSet;
        for (unsigned int i = 0; i < vectorSize; i++)
        {
            numberSet[nums[i]]++;
            if(numberSet[nums[i]] > 1) return true;
        }

        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int> indices;
        unsigned int size = nums.size();

        for(unsigned int i = 0; i < size; i++)
        {

            unordered_map<int,int> :: iterator it = indices.find(nums[i]);
            if(it != indices.end())
            {
               //element found;
                if(i - (indices[nums[i]]) <= k)
                {
                    return true;
                }
                else
                {
                    indices[nums[i]] = i;
                }

            }
            else
            {
                indices[nums[i]] = i;
            }
        }

        return false;
    }
};

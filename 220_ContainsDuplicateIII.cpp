class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
     multiset<int> s;

     using ll = long long;
     for(int i = 0, len = (int)nums.size(); i < len; ++i){

       if(i > k) s.erase(s.find(nums[i - k - 1]));

       if(auto it = s.lower_bound(nums[i]); (it != s.end() && abs(*it - (ll)nums[i]) <= t) || (it != s.begin() && abs(*prev(it) - (ll)nums[i]) <= t)) return true;
       s.insert(nums[i]);
     }
     return false;
   }

};

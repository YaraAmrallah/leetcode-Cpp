/*

Given an array of integers, find out whether there are two distinct
indices i and j in the array such that the absolute difference
between nums[i] and nums[j] is at most t and the absolute difference
between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false

*/


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

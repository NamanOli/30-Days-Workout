// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
           if(mp.find(nums[i])!=mp.end()) // means already present in map
           {
               return true;
           }
            else
            {
                mp[nums[i]]=1;
            }
        }
        return false;
    }
};

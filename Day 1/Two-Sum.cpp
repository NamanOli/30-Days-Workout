//  https://leetcode.com/problems/two-sum/

// O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v(2);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if((target-nums[i]==nums[j])&&(i!=j)) // Corner case 
                {
                    v[0]=i;
                    v[1]=j;
                }
            }
        }
        return v;
    }
};

// O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            auto it=mp.find(target-nums[i]);
            if(it!=mp.end())
            {
                return vector<int>{i,it->second}; // key - number , value - index
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};

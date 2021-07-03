// https://leetcode.com/problems/3sum/

// O(N^3) - Brute Force
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int arr_size=nums.size();
        vector<vector<int>>res;
        for (int i = 0; i < arr_size - 2; i++)
    {
            if(i>0 && (nums[i]==nums[i-1]) )continue; // removing duplicates
 
        
        for (int j = i + 1; j < arr_size - 1; j++)
        {
 
            
            for (int k = j + 1; k < arr_size; k++)
            {
                if ((nums[i] + nums[j] + nums[k] == 0)&&(i!=j)&&(i!=k)&&(j!=k))
                {
                    res.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }
    }
        return res;
    }
};


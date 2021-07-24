// https://leetcode.com/problems/subsets-ii/

class Solution {
    private:
    void findsubset(int ind,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans)
    {
        ans.push_back(ds); // for storing [{}]
        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind&&nums[i]==nums[i-1]) continue; // to remove duplicate subsets
            ds.push_back(nums[i]);
            findsubset(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds; // data structure to hold subsets
        sort(nums.begin(),nums.end());
        findsubset(0,nums,ds,ans);
        return ans;
    }
    
};

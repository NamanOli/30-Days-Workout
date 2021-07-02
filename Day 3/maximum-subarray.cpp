// https://leetcode.com/problems/maximum-subarray/ 


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxcurr=0,maxsofar=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            
            maxcurr=nums[i]>maxcurr+nums[i]?nums[i]:maxcurr+nums[i];
            maxsofar=max(maxsofar,maxcurr);
        }
        return maxsofar;
    }
};

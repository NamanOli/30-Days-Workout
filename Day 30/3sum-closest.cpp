// https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        int sum=nums[0]+nums[1]+nums[len-1];
        for(int i=0;i<len-2;i++)
        {
            int a=i+1;
            int b=len-1;
            while(a<b)
            {
                int cur=nums[i]+nums[a]+nums[b];
                if(cur>target)
                {
                    b--;
                }
                else{
                    a++;
                }
                if(abs(cur-target)<abs(sum-target))
                   {
                       sum=cur;
                   }
            }
        }
        return sum;
    }
};

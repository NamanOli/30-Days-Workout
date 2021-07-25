// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0,sum1=0;
        for(int i=0;i<=n;i++)
        {
            sum+=i;
        }
        for(int i=0;i<n;i++)
        {
            sum1+=nums[i];
        }
        return (abs(sum1-sum));
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;
        
        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }
        
        return result;
    }
};

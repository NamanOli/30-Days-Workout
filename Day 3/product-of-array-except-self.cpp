// https://leetcode.com/problems/product-of-array-except-self/


// 1
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,1);
       int left=1;
        int right=1;
        for(int i=1;i<n;i++)
        {
            left=left*nums[i-1];
            res[i]=res[i]*left;
        }
        for(int i=n-2;i>=0;i--)
        {
            right=right*nums[i+1];
            res[i]=res[i]*right;
        }
        return res;
    }
};

// 2
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int left = nums[0], right=nums[n-1];
        vector<int> v(n,1);
        for(int i=1; i<n; i++){
            v[i]=left;
            left*=nums[i];
        }
        for(int i=n-2; i>=0; i--){
            v[i]*=right;
            right*=nums[i];
        }
        return v;
    }
};

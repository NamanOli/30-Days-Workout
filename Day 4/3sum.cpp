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

// O(N^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        if(n < 3)
            return {};
        
        vector<vector<int>> ans;
        
        sort(arr.begin() , arr.end());
        
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && arr[i] == arr[i-1])
                continue;
            
            int low = i+1, high = n-1;
            
            while(low < high)
            {
                int sum = arr[i] + arr[low] + arr[high];
                if(sum < 0)
                    low++;
                else if(sum > 0)
                    high--;
                else
                {
                    ans.push_back({arr[i] , arr[low] , arr[high]});
                    
                    while(low < high && arr[low] == arr[low+1]) low++;
                    while(low < high && arr[high] == arr[high-1]) high--;
                    low++;
                    high--;
                }
            }
                
        }
        return ans;
    }
};

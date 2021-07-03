// https://leetcode.com/problems/container-with-most-water/

// O(n)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int maxwater=0;
        
        while(l<r)
        {
            int w=r-l;
            int h=min(height[l],height[r]);
            
            maxwater=max(maxwater, w*h);
            
            if(height[l]<=height[r])        //minimum height will change
                l++;
            else
                r--;
        }
        
        return maxwater;
        
    }
};

// https://leetcode.com/problems/get-maximum-in-generated-array/

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0||n==1)
        {
            return n;
        }
        vector<int>res(n+1);
        res[0]=0;
        res[1]=1;
        int maxo=1;
        for(int i=2;i<=n;i++)
        {
            res[i]=((i%2)==0)?res[i/2]:res[i/2]+res[(i/2)+1];
            maxo=max(maxo,res[i]);
        }
        return maxo;
    }
};

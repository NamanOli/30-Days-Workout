// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<int>t=intervals[0];
        for(auto i:intervals)
        {
            if(t[1]>=i[0])
            {
                t[1]=max(t[1],i[1]);
            }
            else{
                res.push_back(t);
                t=i;
            }
            
        }
        res.push_back(t);
        return res;
    }
};

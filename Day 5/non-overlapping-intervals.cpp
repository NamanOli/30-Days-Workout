// https://leetcode.com/problems/non-overlapping-intervals/

bool cmp(vector<int>&a,vector<int>&b) // function to sort elements based of 2nd element of vector
{
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res=-1;
        sort(intervals.begin(),intervals.end(),cmp); // sorting wrt 2nd element
        vector<int>t=intervals[0];
        for(auto i:intervals)
        {
            if(t[1]>i[0]) // if the second of first element coincides with first of second element means overlapping
            {
                res++; // ans increment
            }
            else
            {
                t=i; // else move to next element
            }
        }
        return res;
    }
};

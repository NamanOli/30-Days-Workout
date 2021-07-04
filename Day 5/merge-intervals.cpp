// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(),intervals.end());
		vector<int>t=intervals[0];
		vector<vector<int>>res;
		for(auto i:intervals)
		{
			if(i[0]<=t[1])  // corner case if the start of next element is smaller than end of first
			{
				t[1]=max(t[1],i[1]);
			}
			else
			{
				res.push_back(t);
				t=i;
			}
		}
		res.push_back(t);
		return res;
	}
};

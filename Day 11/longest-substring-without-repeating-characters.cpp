// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
	int lengthOfLongestSubstring(string s) 
	{
		unordered_set<char> set;
    
		int i = 0, j = 0, n = s.size(), ans = 0;
    
		while( i<n && j<n)
		{
			if(set.find(s[j]) == set.end()) //If the character does not in the set
			{
				set.insert(s[j++]); //Insert the character in set and update the j counter
				ans = max(ans, j-i); //Check if the new distance is longer than the current answer
			}
			else
			{
				set.erase(s[i++]); 
				/*If character does exist in the set, ie. it is a repeated character, 
				we update the left side counter i, and continue with the checking for substring. */
			}
		}
    
		return ans;
	}
};


// using map
class Solution {
public:
	int lengthOfLongestSubstring(string s) 
	{
		vector<char>mp(256,-1);
        int l=0,r=0;
        int n=s.size();
        int res=0;
        while(r<n)
        {
            if(mp[s[r]]!=-1)
            {
                l=max(l,mp[s[r]]+1);
               
            }
             mp[s[r]]=r;
            res=max(res,r-l+1);
            r++;
        }
         return res;
	}
};

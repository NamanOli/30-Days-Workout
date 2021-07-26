// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int i=0,j=0;
        for(auto i:t)
            mp[i]++;
        int count=mp.size();
        int n=s.size();
        string ans;
        int temp=INT_MAX;
        string res;
        while(j<n)
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    count--;
            }
            while(count==0)
            {
                if(j-i+1<temp)
                {
                    temp=j-i+1;
                    res=s.substr(i,j-i+1);
                }
                if(mp.find(s[i])!=mp.end())
                {
                        mp[s[i]]++;
                        if(mp[s[i]]==1)
                        {
                            count++;
                        }
                }
                i++;
            }
            j++;
        }
        mp.clear();
        return res;
    }
};

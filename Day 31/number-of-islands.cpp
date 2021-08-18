// https://leetcode.com/problems/number-of-islands/

class Solution {
    vector<vector<char>>g;
public:
    int numIslands(vector<vector<char>>& grid) {
    
        int numIsland=0;
        g=grid;
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[i].size();j++)
            {
                    numIsland+=dfs(i,j);   
            }
        }
        return numIsland;
    }
    public:
    int dfs(int i,int j)
    {
        if(i<0||i==g.size()||j<0||j==g[i].size()||g[i][j]=='0')
        {
            return 0;
        }
        g[i][j]='0';
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j+1);
        dfs(i,j-1);
        return 1;
    }
};

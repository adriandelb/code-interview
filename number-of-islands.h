#include <vector>

using namespace std;


//medium
//https://leetcode.com/problems/number-of-islands/


//input: vector<vector> of chars
/*
[
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
*/

class Solution {
public:
    int n = 0;
    int m = 0;
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        n = grid.size();
        //cout << "n" << n <<endl;
        if(n == 0)
        {
            return 0;
        }
        m = grid[0].size();
        
        for(int i = 0; i < n;i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
        
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1')
        {
            return;
        }
        
        grid[i][j] = '0';
        
        dfs(grid,i + 1, j);
        dfs(grid,i -1, j);
        dfs(grid,i, j+1);
        dfs(grid,i, j-1);
    }
    
};
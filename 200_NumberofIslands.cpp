class Solution {
public:

    int dfs (vector<vector<char>> &grid, int i, int j)
    {
        int N = grid.size();
        if(N == 0) return 0;
        int M = grid[0].size();

        if(i < 0 || i >= N || j < 0 || j >= M || (grid[i][j] == '0')) return 0;

        grid[i][j] = '0';

        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);

        return 1;
    }


    int numIslands(vector<vector<char>>& grid)
    {
        int N = grid.size();
        if(N == 0) return 0;
        int M = grid[0].size();

        int numberOfIslands = 0;

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(grid[i][j] == '1')
                {
                    numberOfIslands += dfs(grid, i, j);
                }
            }
        }

        return numberOfIslands;
    }

};

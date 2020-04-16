class Solution {
public:

    void dfs(vector<vector<char>>&board, vector<int>& click, vector<vector<bool>> &visited)
{
    if(visited[click[0]][click[1]] == true)
        return;
    //if(board[click[0]][click[1]] != 'E') return;

    visited[click[0]][click[1]] = true;
    int mineCounter = 0;

    for(int i = click[0] - 1; i <= click[0] + 1; i++)
    {
        if(i < 0 || i >= board.size())
            continue;
        for(int j = click[1] - 1; j <= click[1] + 1; j++)
        {
            if(i == click[0] && j == click[1])
                continue;
            if(j < 0 || j >= board[0].size())
                continue;

            if(board[i][j] == 'M')
            {
                mineCounter++;
                visited[i][j] = true;
            }
        }

    }

        if(mineCounter == 0)
        {
            for(int i = click[0] - 1; i <= click[0] + 1; i++)
            {
                if(i < 0 || i >= board.size())
                    continue;
                for(int j = click[1] - 1; j <= click[1] + 1; j++)
                {
                    if(i == click[0] && j == click[1])
                        continue;
                    if(j < 0 || j >= board[0].size())
                        continue;
                    if (board[i][j] == 'E')
                    {
                        vector<int> bla = {i,j};
                        dfs(board, bla, visited);
                    }
                }
            }
        }

        if(mineCounter != 0)
        {
            board[click[0]][click[1]] = (char)(mineCounter + 48);
        }
        else
        {
            board[click[0]][click[1]] = 'B';
        }

    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        if(board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        if(board[click[0]][click[1]] != 'E')
            return board;

        int N = board.size();
        int M = board[0].size();
        vector<vector<bool>> visited(N, std::vector<bool>(M, false));

        dfs(board, click, visited);

        return board;

    }
};

#include <vector>
#include <queue>
using namespace std;

int getReverLength(vector<vector<int>>& matrix, int row, int col)
{
    vector<int> dirs = {-1, 0, 1, 0, -1};
    int length = 0;
    queue<pair<int, int>> que;
    que.push(make_pair(row, col));
    matrix[row][col] = 0;
    
    while (!que.empty())
    {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();
        length++;

        for (int i = 0; i < 4; i++)
        {
            int next_r = r + dirs[i];
            int next_c = c + dirs[i + 1];
            if (next_r < 0 || next_r >= matrix.size() || 
                next_c < 0 || next_c >= matrix[0].size() ||
                matrix[next_r][next_c] == 0)
                continue;
            que.push(make_pair(next_r, next_c));
            matrix[next_r][next_c] = 0;
        }
    }

    return length;
}

vector<int> riverSizes(vector<vector<int>> matrix)
{
    vector<int> res;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 1)
            {
                res.push_back(getReverLength(matrix, i, j));
            }
        }
    }
    return res;
}

// int main()
// {
//     vector<vector<int>> matrix;
//     matrix.push_back({1, 0, 0, 1, 0});
//     matrix.push_back({1, 0, 1, 0, 0});
//     matrix.push_back({0, 0, 1, 0, 1});
//     matrix.push_back({1, 0, 1, 0, 1});
//     matrix.push_back({1, 0, 1, 1, 0});

//     vector<int> res = riverSizes(matrix);

//     return 0;
// }

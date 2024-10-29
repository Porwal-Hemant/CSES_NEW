#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int column, vector<string> board, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 'Q' || board[i][column] == 'Q')
        {
            return false;
        }
    }

    int right_diagonal = row + column;

    int left_diagonal = row - column + (n - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int row = i;
            int column = j;

            int firstP = row + column;
            int secondP = row - column + (n - 1);

            if ((firstP == right_diagonal && board[row][column] == 'Q') || (secondP == left_diagonal && board[row][column] == 'Q'))
            {
                return false;
            }
        }
    }

    return true;
}

void solve(int &ans, vector<string> &board, int n, int row)
{

    if (row == n)
    {
        ans = ans + 1;
        return ; 
    }

    for (int i = 0; i < n; i++)
    {

        if (isSafe(row, i, board, n) && board[row][i] != '*')
        {
            // *  ->  reserved
            board[row][i] = 'Q';

            solve(ans, board, n, row + 1);
            // backtracking

            board[row][i] = '.';
        }
        // jab uss column par possible nahi hai than agle column par jayga
    }
}

int main()
{

    int n = 8;

    vector<string> board(n);

    for (int i = 0; i < n; i++)
    {

        string s;

        for (int j = 0; j < 8; j++)
        {

            char ch;
            cin >> ch;
            s = s + ch;
        }

        board[i] = s; // 1D vector of strings
    }

    int ans = 0;

    solve(ans, board, n, 0);

    cout << ans;
}

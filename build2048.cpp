#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back

struct Game2048
{
    int board[4][4];

    void swipe_right(int arr[])
    {
        int last_placed = 4;
        int can_merge = 0;

        for (int i = 3; i >= 0; i--)
        {
            if (arr[i] != 0)
            {
                if (can_merge)
                {
                    if (arr[i] == arr[last_placed])
                    {
                        arr[last_placed] *= 2;
                        if (i != last_placed)
                        {
                            arr[i] = 0;
                        }
                        can_merge = false;
                    }
                }
                else
                {
                    arr[last_placed - 1] = arr[i];
                    last_placed--;
                    if (i != last_placed)
                    {
                        arr[i] = 0;
                    }
                    can_merge = true;
                }
            }
        }
    }

    bool has_game_ended()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool move_end()
    {
        if (has_game_ended())
        {
            return true;
        }
        else
        {
            random_populate();
            return false;
        }
    }

    void random_populate()
    {
        while (1)
        {
            int i = rand() % 4;
            int j = rand() % 4;
            if (board[i][j] == 0)
            {
                board[i][j] = 2;
                break;
            }
        }
    }

    void init()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                board[i][j] = 0;
            }
        }
        random_populate();
        random_populate();
    }

    bool up()
    {
        for (int col = 0; col < 4; col++)
        {
            int arr[4];
            for (int row = 0; row < 4; row++)
            {
                arr[3 - row] = board[row][col];
            }
            swipe_right(arr);
            for (int row = 0; row < 4; row++)
            {
                board[row][col] = arr[3 - row];
            }
        }
        return move_end();
    }

    bool down()
    {
        for (int col = 0; col < 4; col++)
        {
            int arr[4];
            for (int row = 0; row < 4; row++)
            {
                arr[row] = board[row][col];
            }
            swipe_right(arr);
            for (int row = 0; row < 4; row++)
            {
                board[row][col] = arr[row];
            }
        }
        return move_end();
    }

    bool left()
    {
        for (int row = 0; row < 4; row++)
        {
            int arr[4];
            for (int col = 0; col < 4; col++)
            {
                arr[3 - col] = board[row][col];
            }
            swipe_right(arr);
            for (int col = 0; col < 4; col++)
            {
                board[row][col] = arr[3 - col];
            }
        }
        return move_end();
    }

    bool right()
    {
        for (int row = 0; row < 4; row++)
        {
            int arr[4];
            for (int col = 0; col < 4; col++)
            {
                arr[col] = board[row][col];
            }
            swipe_right(arr);
            for (int col = 0; col < 4; col++)
            {
                board[row][col] = arr[col];
            }
        }

        return move_end();
    }

    void print_board()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j])
                {
                    cout << board[i][j] << "\t";
                }
                else
                {
                    cout << ".\t";
                }
            }
            cout << endl;
        }
    }
};

signed main()
{
    srand(time(0));

    Game2048 mygame;
    mygame.init();

    while (1)
    {
        mygame.print_board();
        cout << "What Move (L,R,D,U)" << endl;
        char ch;
        cin >> ch;
        bool ended = false;

        if (ch == 'U')
        {
            ended = mygame.up();
        }
        else if (ch == 'D')
        {
            ended = mygame.down();
        }
        else if (ch == 'L')
        {
            ended = mygame.left();
        }
        else if (ch == 'R')
        {
            ended = mygame.right();
        }
        else
        {
            cout << "INVALID" << endl;
        }

        if (ended)
        {
            mygame.print_board();
            cout << "GAME ENDED" << endl;
            break;
        }
    }

    return 0;
}

#include <iostream.h>
#include <graphics.h>
#include <conio.h>

void drawCircle(int x, int y, int rad)
{
    circle(75 + x, 75 + y, rad);
}

void drawCross(int x, int y)
{
    line(50 + x, 50 + y, 100 + x, 100 + y);
    line(100 + x, 50 + y, 50 + x, 100 + y);
}

void drawBoard()
{
    line(150, 0, 150, 400);
    line(300, 0, 300, 400);
    line(50, 150, 400, 150);
    line(50, 300, 400, 300);
}

int checker(int arr[3][3])
{
    if ((arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][0] != -1) ||
        (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][0] != -1) ||
        (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][0] != -1) ||
        (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[0][0] != -1) ||
        (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[0][1] != -1) ||
        (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[0][2] != -1) ||
        (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != -1) ||
        (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != -1))
    {
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == -1)
            {
                return 0;
            }
        }
    }

    return -1;
}

int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");

    int arr[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
    int block, invalid = 0;
    int player = 0;
    drawBoard();

    int code;
    do
    {
        if (player == 0)
        {
            cout << "Player O's turn" << endl;
        }
        else
        {
            cout << "Player X's turn" << endl;
        }

        cout << "Enter Block No (1-9): ";
        cin >> block;

        invalid = 0;
        int row = (block - 1) / 3;
        int col = (block - 1) % 3;

        if (block < 1 || block > 9 || arr[row][col] != -1)
        {
            cout << "Invalid Block" << endl;
            invalid = 1;
        }

        if (!invalid)
        {
            arr[row][col] = player;

            int x = col * 150;
            int y = row * 150;

            if (player == 0)
            {
                drawCircle(x, y, 50);
                player = 1;
            }
            else
            {
                drawCross(x, y);
                player = 0;
            }
        }

        code = checker(arr);
    } while (code == 0);

    if (code == 1)
    {
        cout << "Winner is Player " << (player == 0 ? "X" : "O") << endl;
    }
    else
    {
        cout << "It's a Draw!" << endl;
    }

    getch();
    closegraph();
    return 0;
}

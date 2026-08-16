// #include <iostream>
// using namespace std;

// bool isSafe(char maze[][3], int row, int col, bool visited[], [3], int newX, int newY)
// {
//     // safe inside bounds valid sell per move kr rahe honge aur visited nhi hoga

//     if ((newX >= 0 && newX < row) && (newY >= 0 && newY < col) && maze[newx][newY] == '.' && visited[newx][newY] == false;)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// void solve(char maze[][3], int row, int col, int srcX, int srcY, string output, int desX, int dexY, bool visited[][3])
// {
//     // base case
//     // if current pos==destination ->answer is ready ,print it and return
//     if (srcX == desX && srcY == desY)
//     {
//         // rat is standing on destination only
//         cout << output << endl;
//         return;
//     }
//     // 1 case main solve karunga baki ka recusion dekh lega
//     // 1 case -> 1 movement
//     //-> up or down or left or right
//     // up
//     int newtX = srcX - 1;
//     int newY = srcY;
//     if (isSafe(maze, row, col, visited, newtX, newY))
//     {
//         visited[newtX][newY] = true;
//         // baki ka recusion
//         solve(maze, row, col, newtX, newY, output + 'U', desX, desY, visited);
//         // jab mai bapas aaya
//         visited[newtX][newY] = false;
//     }

//     // down
//     newX = srcX + 1;
//     newY = srcY;
//     if (isSafe(maze, row, col, visited, newtX, newY))
//     {
//         visited[newtX][newY] = true;
//         // baki ka recusion
//         solve(maze, row, col, newtX, newY, output + 'D', desX, desY, visited);
//         // jab mai bapas aaya
//         visited[newtX][newY] = false;
//     }
//     // left
//     newtX = srcX;
//     newY = srcY - 1;
//     if (isSafe(maze, row, col, visited, newtX, newY))
//     {
//         visited[newtX][newY] = true;
//         // baki ka recusion
//         solve(maze, row, col, newtX, newY, output + 'L', desX, desY, visited);
//         // jab mai bapas aaya
//         visited[newtX][newY] = false;
//     }

//     // right
//     newtX = srcX;
//     newY = srcY + 1;
//     if (isSafe(maze, row, col, visited, newtX, newY))
//     {
//         visited[newtX][newY] = true;
//         // baki ka recusion
//         solve(maze, row, col, newtX, newY, output + 'R', desX, desY, visited);
//         // jab mai bapas aaya
//         visited[newtX][newY] = false;
//     }
// }

// int main()
// {

//     // maze contains '.' && '-'
//     //  -> '.' rat can move here
//     //-> '-' rat cannot move here
//     char arr[3][3] = {
//         {'.', '.', '.'},
//         {'.', '-', '-'},
//         {'.', '.', '.'}};

//     int row = 3;
//     int col = 3;
//     // src-> 0,0
//     int srcX = 0;
//     int srcY = 0;
//     // dest ->n-1,n-1->(2,2)
//     string output = "";
//     int desX = row - 1;
//     int desY = col - 1;
//     bool visited[3][3] = {
//         {false, false, false},
//         {false, false, false},
//         {false, false, false}};
//     solve(arr, row, col, srcX, srcY, output, desX, desY, visited);

//     return 0;
// }






#include <iostream>
using namespace std;

bool isSafe(char maze[][3], int row, int col, bool visited[][3], int newX, int newY)
{
    // safe inside bounds valid sell per move kr rahe honge aur visited nhi hoga

    if ((newX >= 0 && newX < row) && (newY >= 0 && newY < col) && maze[newX][newY] == '.' && visited[newX][newY] == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(char maze[][3], int row, int col, int srcX, int srcY, string output, int desX, int desY, bool visited[][3])
{
    // base case
    // if current pos==destination ->answer is ready ,print it and return
    if (srcX == desX && srcY == desY)
    {
        // rat is standing on destination only
        cout << output << endl;
        return;
    }

    // 1 case main solve karunga baki ka recusion dekh lega
    // 1 case -> 1 movement
    //-> up or down or left or right

    // up
    int newX = srcX - 1;
    int newY = srcY;

    if (isSafe(maze, row, col, visited, newX, newY))
    {
        visited[newX][newY] = true;
        // baki ka recusion
        solve(maze, row, col, newX, newY, output + 'U', desX, desY, visited);
        // jab mai bapas aaya
        visited[newX][newY] = false;
    }

    // down
    newX = srcX + 1;
    newY = srcY;

    if (isSafe(maze, row, col, visited, newX, newY))
    {
        visited[newX][newY] = true;
        // baki ka recusion
        solve(maze, row, col, newX, newY, output + 'D', desX, desY, visited);
        // jab mai bapas aaya
        visited[newX][newY] = false;
    }

    // left
    newX = srcX;
    newY = srcY - 1;

    if (isSafe(maze, row, col, visited, newX, newY))
    {
        visited[newX][newY] = true;
        // baki ka recusion
        solve(maze, row, col, newX, newY, output + 'L', desX, desY, visited);
        // jab mai bapas aaya
        visited[newX][newY] = false;
    }

    // right
    newX = srcX;
    newY = srcY + 1;

    if (isSafe(maze, row, col, visited, newX, newY))
    {
        visited[newX][newY] = true;
        // baki ka recusion
        solve(maze, row, col, newX, newY, output + 'R', desX, desY, visited);
        // jab mai bapas aaya
        visited[newX][newY] = false;
    }
}

int main()
{
    // maze contains '.' && '-'
    //  -> '.' rat can move here
    //-> '-' rat cannot move here
    char arr[3][3] = {
        {'.', '.', '.'},
        {'.', '-', '-'},
        {'.', '.', '.'}};

    int row = 3;
    int col = 3;

    // src-> 0,0
    int srcX = 0;
    int srcY = 0;

    // dest ->n-1,n-1->(2,2)
    string output = "";
    int desX = row - 1;
    int desY = col - 1;

    bool visited[3][3] = {
        {false, false, false},
        {false, false, false},
        {false, false, false}};

    visited[srcX][srcY] = true;

    solve(arr, row, col, srcX, srcY, output, desX, desY, visited);

    return 0;
}
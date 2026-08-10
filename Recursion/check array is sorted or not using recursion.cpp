#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int> arr, int n)
{
    if (n == 0)
    {
        return true;
    }
    // 1 case handle by me
    if (arr[n] < arr[n - 1])
    {
        return false;
    }
    // recursive call
    solve(arr, n - 1);
}

int main()
{

    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = arr.size();
    bool ans = solve(arr, n - 1);
    cout << ans;
}
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void getMaxElement(const vector<int> &arr, int n, int index, int &maxi)
{
    // base case
    if (index >= n)
    {
        return;
    }

    // 1 case main solve karunga
    maxi = max(maxi, arr[index]);

    // recursive call
    getMaxElement(arr, n, index + 1, maxi);
}

int findMaxRecursively(const vector<int> &arr, int index)
{
    int maxi = INT_MIN;
    getMaxElement(arr, arr.size(), 0, maxi);
    return maxi;
}

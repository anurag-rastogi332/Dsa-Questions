#include <iostream>
using namespace std;

/*

In case there are fewer than k unique elements in the array, return -1.

Example
Example 1:
Input: array = [1, 1, 1, 2, 2, 3, 4], k = 2
Output: 2
The frequencies are:

1 occurs 3 times
2 occurs 2 times
3 and 4 occur 1 time each
The 2nd most frequent element is 2.

Example 2:
Input: array = [4, 4, 1, 1, 2, 3], k = 3
Output: 2
The frequencies are:

4 and 1 both occur 2 times each
2 and 3 occur 1 time each
Resolving a tie by order, the 3rd most frequent element is 1.

Example 3:
Input: array = [5, 6, 5, 7], k = 10
Output: -1
There are only 3 unique elements, so the 10th most frequent element doesn't exist.

Example 1:

Input:

Input: arr = [1, 1, 1, 2, 2, 3, 4], k = 2

Output:

2
Explanation:The 2th most frequent element is 2 after resolving any ties.

Example 2:

Input:

Input: arr = [4, 4, 1, 1, 2, 3], k = 3

Output:

2
Explanation:The 3th most frequent element is 2 after resolving any ties.

Example 3:

Input:

Input: arr = [5, 6, 5, 7], k = 10

Output:

-1
Explanation:There are fewer than 10 unique elements in the array.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first > b.first;
    }

    int kthMostFrequent(const vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }

        vector<pair<int, int>> freq;

        for (auto it : mp)
        {
            freq.push_back({it.second, it.first});
        }

        if (k > freq.size())
        {
            return -1;
        }

        sort(freq.begin(), freq.end(), cmp);

        return freq[k - 1].second;
    }
};
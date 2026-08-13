#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &nums1, int m, vector<int> &nums2, int n, int i, int j, vector<int> &ans)
    {

        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while (i < m)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < n)
        {
            ans.push_back(nums2[j]);
            j++;
        }
    }
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = 0;
        int j = 0;
        vector<int> ans;
        solve(nums1, m, nums2, n, i, j, ans);
        for (int i = 0; i < m + n; i++)
        {
            nums1[i] = ans[i];
        }
    }
};

// try to write for this o(1) space complexity next time
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start = 0;
        int balance = 0;
        int deficit = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            /// ya toh main aage ja skta hu, ya toh main aage nahi jaa skta
            if (balance + gas[i] < cost[i])
            {
                // deficit case - k main aage nahi ja skta, petrol kam pdega
                deficit += balance + gas[i] - cost[i];
                start = i + 1;
                balance = 0;
            }
            else
            {
                // aage ja skta hu -> possibilty h petrol extra hojaye mere paas
                balance = balance + gas[i] - cost[i];
            }
        }
        // ab loop khtm ho chuka h , we just need to compare deficit and balance
        if (balance + deficit >= 0)
        {
            // iska matlab balance ne deficit ko fill krdia ya exceed krdia
            return start;
        }
        else
        {
            // petrol km padgye , no answer
            return -1;
        }
    }
};
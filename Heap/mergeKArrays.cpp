#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Info
{
public:
    int element;
    int rowIndex;
    int colIndex;

    Info(int val, int row, int col)
    {
        element = val;
        rowIndex = row;
        colIndex = col;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->element > b->element;
    }
};

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Info *, vector<Info *>, compare> pq;

        vector<int> ans;
        int totalRows = arr.size();
        int totalCol = arr[0].size();
        // inital state
        // process first k elements
        for (int i = 0; i < K; i++)
        {
            // first element of each row
            int element = arr[i][0];
            Info *temp = new Info(element, i, 0);
            pq.push(temp);
        }

        // main logic
        while (!pq.empty())
        {
            Info *front = pq.top();
            pq.pop();

            int element = front->element;
            int rIndex = front->rowIndex;
            int cIndex = front->colIndex;

            // element should be inserted inside the ans arrayv
            ans.push_back(element);
            // and same array ka new element heap me insert krna h
            if (cIndex + 1 < totalCol)
            {
                int element = arr[rIndex][cIndex + 1];
                int newRowIndex = rIndex;
                int newColIndex = cIndex + 1;
                Info *temp = new Info(element, newRowIndex, newColIndex);
                pq.push(temp);
            }
        }

        return ans;
    }
};
#include <iostream>
#include <queue>
using namespace std;

/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.


Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0


Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.


Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

*/

class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {

        // 3 cases
        if (maxHeap.size() == minHeap.size())
        {
            double median = findMedian();
            if (num > median)
            {
                // right
                minHeap.push(num);
            }
            else
            {
                // left
                maxHeap.push(num);
            }
        }
        else if (maxHeap.size() == minHeap.size() + 1)
        {
            double median = findMedian();
            // maxheap is bar minheap se bada h
            // left side , right side se jada badi h
            // agar left me insert krna pada toh pehle left me jagah
            // banani padegi
            if (num > median)
            {
                // right me placee krna h num ko
                minHeap.push(num);
            }
            else
            {
                // left me place krna h num ko
                // pehle jagah banao , fere insert karo
                int element = maxHeap.top();
                maxHeap.pop();
                minHeap.push(element);
                // ab jagah bangyi
                // ab left me insert kr skte ho
                maxHeap.push(num);
            }
        }
        else if (minHeap.size() == maxHeap.size() + 1)
        {
            double median = findMedian();
            // min heap is bar maxheap se badab h
            // right side iss bar left side se badi h
            // agar mujhe right side me insert karna hua
            // toh mujhe pehle right side me jagaha banani padegi
            if (num > median)
            {
                // right side me mpush krna h
                // pehle jagah banao, fer insert karo
                int element = minHeap.top();
                minHeap.pop();
                maxHeap.push(element);
                // ab main right me insrt kar skta hu
                minHeap.push(num);
            }
            else
            {
                // left side me push krna h
                maxHeap.push(num);
            }
        }
    }

    double findMedian()
    {
        // 4 cases
        // first case is very important orderwise
        if (maxHeap.size() == 0 && minHeap.size() == 0)
        {
            return 0;
        }
        else if (maxHeap.size() == minHeap.size())
        {
            double maxi = maxHeap.top() * 1.0;
            double mini = minHeap.top() * 1.0;
            double ans = (maxi + mini) / 2.0;
            return ans;
        }
        else if (maxHeap.size() == minHeap.size() + 1)
        {
            return maxHeap.top();
        }
        else if (minHeap.size() == maxHeap.size() + 1)
        {
            return minHeap.top();
        }
        else
        {
            return -1;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
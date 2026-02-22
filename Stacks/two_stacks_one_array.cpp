#include <iostream>
using namespace std;


class Stack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int capacity)
    {
        arr = new int[capacity];
        size = capacity;
        top1 = -1;
        top2 = size;
    }

    void push1(int value)
    {
        // normal push or overflow
        if (top2 - top1 == 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top1++;
            arr[top1] = value;
        }
    }

    void push2(int value)
    {
        // normal push or overflow
        if (top2 - top1 == 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top2--;
            arr[top2] = value;
        }
    }

    void pop1()
    {
        // normal pop or underflow
        if (top1 == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            top1--;
        }
    }

    void pop2()
    {
        // normal pop or undertflow
        if (top2 == size)
        {
            cout << "Stack Underflow " << endl;
        }
        else
        {
            top2++;
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Top1: " << top1 << endl;
        cout << "Top2: " << top2 << endl;
    }
};

int main()
{

    Stack s(10);

    s.push1(11);
    s.print();
    s.push2(17);
    s.print();
    s.push1(21);
    s.push1(31);
    s.push1(41);
    s.push1(51);
    s.push1(61);
    s.print();

    s.push2(111);
    // s.print();

    s.push2(112);
    // s.print();

    s.push2(113);
    // s.print();

    s.push1(311);
    // s.print();

    s.pop1();
    s.print();

    return 0;
}

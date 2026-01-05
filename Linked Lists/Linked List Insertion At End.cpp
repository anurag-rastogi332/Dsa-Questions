#include <iostream>
using namespace std;


/*

Input: x = 6,

Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6
Explanation: We can see that 6 is inserted at the end of the linkedlist.

Input: x = 1,

Output: 4 -> 5 -> 1
Explanation: We can see that 1 is inserted at the end of the linked list.


*/

class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution
{
public:
    Node *insertAtEnd(Node *head, int x)
    {
        // Code here

        Node *newNode = new Node(x);
        if (head == NULL)
            return newNode;
        Node *tmp = head;

        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        return head;
    }
};
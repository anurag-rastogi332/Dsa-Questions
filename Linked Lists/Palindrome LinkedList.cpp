#include <iostream>
using namespace std;

/*

Examples:

Input:

Output: true
Explanation: The given linked list is 1 -> 2 -> 1 -> 1 -> 2 -> 1, which is a palindrome.
Input:

Output: false
Explanation: The given linked list is 10 -> 20 -> 30 -> 40 -> 50, which is not a palindrome.

*/

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    int getLengthOfLinkedList(Node *head)
    {
        int len = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

    Node *getMidNode(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        // agar fast k paas 2 step chalne ka chance h, toh hi main slow and fast ko
        // aage badhaunga, nahi toh loop se bahar niklo
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void reverseLinkedList(Node *&head)
    {
        // empty ll
        if (head == NULL)
        {
            return;
        }

        Node *prev = NULL;
        Node *curr = head;

        while (curr != NULL)
        {
            Node *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        // update head
        head = prev;
    }

    bool isPalindrome(Node *head)
    {
        // find the length
        int len = getLengthOfLinkedList(head);

        // find the mid
        Node *mid = getMidNode(head);

        // update mid according to the length
        // even length me mid as it is use krna h
        // odd case me main finalMid, mid->next ko lunga
        Node *finalMid = NULL;
        if (len & 1)
        {
            // odd
            finalMid = mid->next;
        }
        else
        {
            // even
            finalMid = mid;
        }

        // reverse linkedlist starting from the mid node - reverse second half
        reverseLinkedList(finalMid);

        // compare and return true and false
        // now i have 2 linked list with starting pointer as head and finalMid
        Node *temp = head;
        while (temp != NULL && finalMid != NULL)
        {
            if (temp->data != finalMid->data)
            {
                return false;
            }
            // 1 step aage badhao
            temp = temp->next;
            finalMid = finalMid->next;
        }

        // agar main yaha tk aagya, iska mtlb saare data match ho gaye
        // palindrome hai
        return true;
    }
};

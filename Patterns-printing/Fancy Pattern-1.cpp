#include<iostream>
using namespace std;


/*

Example

For N = 7 and C = @, output should be:

@@@@@@@
 @@@@@
  @@@
   @
  @@@
 @@@@@
@@@@@@@
Input Format

An integer N

A character C

Output Format

Print the required hourglass pattern.

*/


class Solution {
public:
    void printPattern(int N, char C) {
        int chars = N;
        int spaces = 0;

        // Upper part
        while (chars >= 1) {
            for (int i = 0; i < spaces; i++) {
                cout << " ";
            }

            for (int i = 0; i < chars; i++) {
                cout << C;
            }

            cout << endl;

            spaces++;
            chars -= 2;
        }

        // Lower part
        chars = 3;
        spaces = N / 2 - 1;

        while (chars <= N) {
            for (int i = 0; i < spaces; i++) {
                cout << " ";
            }

            for (int i = 0; i < chars; i++) {
                cout << C;
            }

            cout << endl;

            spaces--;
            chars += 2;
        }
    }
};
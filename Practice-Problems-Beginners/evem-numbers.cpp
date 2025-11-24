class Solution {
public:
    void printEvenNumbers(int n) {
        bool first = true;  // to handle spaces
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                if (!first) cout << " ";  // print space before next number
                cout << i;
                first = false;
            }
        }
    }
};

class Solution {
public:
    int sumNumbers(int n) {
        //do not write cin >> n, as input n is already taken in the driver code
        // Implement the loop logic to sum n numbers
        int sum=0,x;
        for(int i=1;i<=n;i++){
            cin>>x;
           sum=sum+x;
        }
        return sum;
    }
};
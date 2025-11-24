class Solution {
public:
  void printNumberMultipleTimes(int num, int n) {
    // Implement the loop logic to print num, n times
    for(int i=1;i<=n;i++){
        cout<<num;
        if(i<n){
          cout<<" ";
        }
    }
  }
};
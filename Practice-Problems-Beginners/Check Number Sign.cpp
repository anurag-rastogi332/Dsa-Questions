//platform:-codehelp
//platform link:-https://www.codehelp.in/dashboard/courses/dsa-red/assignment-1/check-number-sign/description


class Solution {
public:
    string checkNumberSign(int num) {
        // Implement the logic to check if the number is positive, negative, or zero
        if(num>0){
            return "Positive";
        }
        else if(num<0){
           return "Negative";
        }
        else{
            return "Zero";

        }
    }
};
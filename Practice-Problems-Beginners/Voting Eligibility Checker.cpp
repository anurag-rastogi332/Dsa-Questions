//platform:-code help
//platform link:-https://www.codehelp.in/dashboard/courses/dsa-red/assignment-1/voting-eligibility-checker/description

class Solution {
public:
    string checkVotingEligibility(int age) {
        // Implement the logic to check voting eligibility
        if(age>=18){
            return "Eligible to vote";
        }
        else{
            return "Not eligible to vote";
        }
    }
};
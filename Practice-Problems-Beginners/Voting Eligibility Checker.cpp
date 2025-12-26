

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
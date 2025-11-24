

class Solution {
public:
    string determineDayType(int day) {
        // Implement the if-else-if ladder logic to determine if it's a weekday or weekend
        if(day==6||day==7){
   return  "Weekend";
        }
        else{
            return "Weekday";
        }
    }
};
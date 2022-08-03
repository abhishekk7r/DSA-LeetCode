class Solution {
public:
    int reverse(int x) {
       int digit;
        int ans=0;
        while(x!=0){
            //using modulus 10 we extract the last digit
            digit=x%10;
            
            //We check whether the number ccan be stored in INT or not.
            if(ans<(INT_MIN/10) || ans>(INT_MAX/10)){
            return 0;
            }
            
            //Formula used to reverse the number
            ans=(ans*10)+digit;
            
            //We move to the next digit in the number from right to left
            x=x/10;
        }
        return ans;
    }
};
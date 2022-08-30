class Solution {
public:
    bool isPalindrome(int x) {
        long int ans = 0;
        int a = x;
        while(x>0){
            int digit = x%10;
            ans = (ans*10)+digit;
            x = x/10;
        }
        if(ans == a){
            return 1;
        } else
        {return 0;}        
    }
};
class Solution {
public:
    bool isPalindrome(int x) {
        // long int ans = 0;
        // int a = x;
        // while(x>0){
        //     int digit = x%10;
        //     ans = (ans*10)+digit;
        //     x = x/10;
        // }
        // if(ans == a){
        //     return 1;
        // } else
        // {return 0;}        
        
        string str =  to_string(x);
        for(int i=0; i<str.size()/2; i++){
            if(str[i]!=str[str.size()-i-1]){
                return 0;
            }
        }
        return 1;
    }
};
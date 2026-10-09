class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        int maxLen = 0;
        string ans = "";

        for(int i=0; i<s.size() - 1; i++){
            string odd = isPalindrome(s, i, i);
            string even = isPalindrome(s, i, i + 1);


            if(odd.size() > maxLen) {
                maxLen = odd.size();
                ans = odd;
            }

            if(even.size() > maxLen) {
                maxLen = even.size();
                ans = even;
            }
        }

        return ans;
    }

    string isPalindrome(string s, int left, int right){
        
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }

        return s.substr(left+1, right - left -1);
    }
};
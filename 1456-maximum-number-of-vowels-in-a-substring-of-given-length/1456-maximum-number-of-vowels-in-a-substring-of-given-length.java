class Solution {
    public int maxVowels(String s, int k) {
        int ans = 0;
        int vowelLen = 0;

        for(int i=0; i<k; i++){
            if("AEIOUaeiou".indexOf(s.charAt(i)) != -1){
                vowelLen++;
                ans = Math.max(vowelLen, ans);
            }
        }

        for(int i = k; i<s.length(); i++){
            char rightChar = s.charAt(i);
            char leftChar = s.charAt(i-k);

            if("AEIOUaeiou".indexOf(leftChar) != -1){
                vowelLen--;
                vowelLen = Math.max(0, vowelLen);
            } 
            
            if("AEIOUaeiou".indexOf(rightChar) != -1) {
                vowelLen++;
            }

            ans = Math.max(vowelLen, ans);
        }

        return ans;
    }
}


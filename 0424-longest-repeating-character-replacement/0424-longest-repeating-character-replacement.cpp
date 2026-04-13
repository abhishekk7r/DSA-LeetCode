class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int ans = 0, maxFreq = INT_MIN;
        
        int i = 0, j = 0, n = s.length();

        while(j < n){
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);
            int changes = j-i+1 - maxFreq;

            if(changes > k){
                mp[s[i]]--;
                i++;
            } else {
                ans =  j - i + 1;
            }

            j++;
        }

        return ans;
    }
};
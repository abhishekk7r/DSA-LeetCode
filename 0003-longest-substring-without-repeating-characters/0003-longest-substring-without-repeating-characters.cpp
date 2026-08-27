class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0, right = 0;

        unordered_map<int, int> freq;

        while(right<s.size()){
            freq[s[right]]++;

            while(freq[s[right]] > 1){
                freq[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);

            right++;
        }

        return ans;
    }
};
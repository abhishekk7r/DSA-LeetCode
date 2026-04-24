class Solution {
public:
    string minWindow(string s, string t) {
         unordered_map<char, int> need, window;

    // Step 1: Build frequency map for t
    for (char c : t) {
        need[c]++;
    }

    int have = 0;
    int needCount = need.size();

    int left = 0;
    int minLen = INT_MAX;
    int start = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];

        // Step 2: Expand window
        window[c]++;

        // Step 3: Check if this char satisfies requirement
        if (need.count(c) && window[c] == need[c]) {
            have++;
        }

        // Step 4: Try shrinking when valid
        while (have == needCount) {
            // Update answer
            if ((right - left + 1) < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            // Remove from window
            char leftChar = s[left];
            window[leftChar]--;

            // Check if window becomes invalid
            if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                have--;
            }

            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
        
    }
};